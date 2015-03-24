package p2p;

import java.util.*;
import java.net.*;  // El paquete java.net se necesita para //
                    // las clases Socket, ServerSocket, //
                    // DatagramSocket y DatagramPackt. //
import java.io.*;   // El paquete java.io se necesita para //
                    // las clases InputStream y OutputStream//

/**
 *
 * @author re38
 */
public class Hilos extends Thread{

        Socket so;
        DataInputStream b;
        DataOutputStream p;
        String mensaje;
        String tipoMensaje;
        boolean entrante;

    	public Hilos (Socket so,DataInputStream b,DataOutputStream p,String mensaje,String tipoMensaje,boolean entrante) {
		this.so = so;
                this.b = b;
                this.p = p;
                this.mensaje = mensaje;
                this.tipoMensaje = tipoMensaje;
                this.entrante = entrante;
    	}

        public Hilos (Socket so,DataInputStream b,DataOutputStream p,String tipoMensaje,boolean entrante) {
		this.so = so;
                this.b = b;
                this.p = p;
                this.tipoMensaje = tipoMensaje;
                this.entrante = entrante;
    	}

   	public void run() {

	    try {
		    
		    while (!tipoMensaje.equalsIgnoreCase("C")) {  				
			    mensaje = readObject(b);				//Leo lo que escribio el socket cliente en el canal de lectura
			    System.out.println(mensaje);
			    tipoMensaje = ObtenerTipoMensaje(mensaje);
		    }
		    // Se ha conectado con éxito

		   if (entrante) {
                            synchronized(this) {
                                    writeObject(p,"T@S");
                                    Servidor.conexiones_actuales++;
                                    System.out.println("Se ha conectado otro, ahora hay: "+Servidor.conexiones_actuales);
                            }
                   }

		    synchronized(this) {
			    Servidor.sockets_abiertos.add(so); //Añadimos el socket al vector de sockets
			    System.out.println(Servidor.sockets_abiertos);
		    }
	    } catch (Exception e) {
		    e.printStackTrace();
		    return;
	    }


	    try {		    
		    while ( true ) {

                            System.out.println("Estoy en el while\n");

			    mensaje = readDataFile(b);
			    System.out.println("AAAAAAAAAAA "+mensaje);
			    tipoMensaje = ObtenerTipoMensaje(mensaje);

		      	    if (tipoMensaje.equalsIgnoreCase("B") ){		//BÚSQUEDA

				    System.out.println("esta en B");
				    synchronized(this) {
					    rellenarTablaRutas(mensaje,so);
				    }

				    reenviarPaquete(mensaje,so,p);	

				    if (buscarEnPc(mensaje)) {
					enviarRespuestaBusqueda(p,mensaje);
				    }

			    }
			    if (tipoMensaje.equalsIgnoreCase("D") ){		//DESCARGA

				    System.out.println("esta en D");
				    enviarFichero(p,so,mensaje);

			    }
                            if (tipoMensaje.equalsIgnoreCase("R") ){		//RESPUESTA
                                    // Esperar a que llegue el mensaje de respuesta un tiempo prudencial --> 3 segundos = 5000 ms
                                    long milisInicio = System.currentTimeMillis(); // tiempo actual
                                    int cont = 0;
                                    while (System.currentTimeMillis() <= milisInicio+3000) {
                                        
                                            if (cont>=1) {
                                               mensaje = readObject(b);
                                               tipoMensaje = ObtenerTipoMensaje(mensaje);

                                               // Descartamos los mensajes que no sean R durante 3 segs
                                               if (tipoMensaje.equalsIgnoreCase("R") ) {
                                                   System.out.println("Mensaje de respuesta: " + mensaje );

                                                   // Guardamos la ip de los mensajes de respuesta
                                                   String[] arrayMsj = mensaje.split("@");
                                                   synchronized(this) {
                                                        Servidor.ip_respuestas.add(arrayMsj[2]);
                                                   }
                                               }

                                            } else {
                                                System.out.println("Mensaje de respuesta: " + mensaje );

                                                // Guardamos la ip de los mensajes de respuesta
                                                String[] arrayMsj = mensaje.split("@");
                                                synchronized(this) {
                                                     Servidor.ip_respuestas.add(arrayMsj[2]);
                                                }
                                            }
                                            cont++;
                                    }
                            } 
                            
                            // Es una descarga de un vecino
                            if(!(tipoMensaje.equalsIgnoreCase("B") || tipoMensaje.equalsIgnoreCase("D") || tipoMensaje.equalsIgnoreCase("R"))) {
                                System.out.println("Recepcion " + mensaje );
                                String ruta = "./Descargas/";
                                File fichero = new File (ruta+NewJFrame.fichero_descarga);
                                //FileInputStream in = new FileInputStream(fichero);
                                int tam = mensaje.length();
                                byte[] buf = new byte[tam];
                                int longi;
                                InputStream in = new ByteArrayInputStream( mensaje.getBytes() );

                                // Para escribir el fichero
                                FileOutputStream fw = new FileOutputStream(fichero);

                                //BufferedWriter bw = new BufferedWriter(fichero);
                                //bw.write(mensaje_d);

                                longi = in.read(buf);
                                //while ((longi = in.read(buf)) != -1) {
                                      System.out.println("Longitud: "+longi);
                                      fw.write(buf, 0, longi);
                                      fw.flush();
                                //}

                                /*FileWriter f = new FileWriter(fichero);
                                PrintWriter pw = new PrintWriter(f);
                                pw.println(mensaje_d);
                                pw.flush();
                                pw.close();*/

                                System.out.println("COMPLETADO!");
                                fw.flush();
                                fw.close();
                            }
		    }
	    } catch (Exception e) {
		    e.printStackTrace();
		    return;
	    } finally {
		    try {
			    so.close();
			    if (entrante) {
                                    synchronized(this) {
                                            Servidor.conexiones_actuales--;
                                            System.out.println("Se ha desconectado uno, ahora hay: "+Servidor.conexiones_actuales);
                                    }
			    }
                            Servidor.sockets_abiertos.remove(so);
		    } catch (Exception ex) {
			    ex.printStackTrace();
			    return;
		    }
	    }
   	}

	public String ObtenerTipoMensaje(String mensaje) {
		String[] arrayMsj = mensaje.split("@");
		return arrayMsj[0];
	}

	/*public String ObtenerMensajeReenviar(String mensaje) {
		String[] arrayMsj = mensaje.split("@");
		int ttl = Integer.parseInt(arrayMsj[2])-1;

		if (ttl == 0) {	//Si el ttl es cero, guardamos en mensaje "null" para que luego cuando vayamos a reenviar el paquete lo tengamos en cuenta
			mensaje = null;
		} else {
			mensaje = arrayMsj[0]+"@"+arrayMsj[1]+"@"+Integer.toString(ttl);
		}
		return mensaje;
	}*/

	public void rellenarTablaRutas(String mensaje, Socket so) {
		String[] arrayMsj = mensaje.split("@");					//Separar los campos del mensaje y meterlos en arrayMsj
		ArrayList value = new ArrayList();				//En el value del hashtable metemos el archivo de busqueda y nuestra hora
		ArrayList aux_value = new ArrayList();

		//Para sacar la hora actual nuestra
		long hora_nuestra = System.currentTimeMillis()/1000;

		Object elementos[] = {arrayMsj[2],arrayMsj[3],so};
		
		//Definimos la clave como un hashset. Luego se utilizara como key del hashtable
		HashSet key = new HashSet(Arrays.asList(elementos));
		
		
		//si la tabla de rutas esta vacia O no esta almacenada esa busqueda,lo meto
		if (Servidor.tablaRutas.isEmpty() || !Servidor.tablaRutas.contains(key)){

			value.add(0,arrayMsj[1]); 					//guardo en el auxiliar el archivo de la busqueda
			value.add(1,hora_nuestra); 					//guardo en el auxiliar nuestra hora actual n milisegs dede '70
											//reenviar paquetes a todos menos al correspondiente
			synchronized(this) {
				Servidor.tablaRutas.put(key,value);
			}

			System.out.println("Clave: "+key);
			System.out.println("Valor: "+Servidor.tablaRutas.get(key));
		
		//Si ya existe, comparamos con la hora en que lo metimos para guardarlo o no
		} else {

			aux_value = (ArrayList)Servidor.tablaRutas.get(key);
			int hora = ((Integer)aux_value.get(1)).intValue(); 		//"hora_actual" de la busqueda almacenada
			if (hora > hora_nuestra) { 
		
				value.add(0,arrayMsj[1]); 				//guardo en el auxiliar el archivo de la busqueda
				value.add(1,hora_nuestra); 				//guardo en el auxiliar nuestra hora actual n milisegs dede '70
											//reenviar paquetes a todos menos al correspondiente
				synchronized(this) {
				  Servidor.tablaRutas.put(key,value);
				}

				System.out.println("Clave: "+key);
				System.out.println("Valor: "+Servidor.tablaRutas.get(key));

			}
		}
	}

	public void reenviarPaquete(String mensaje, Socket so, DataOutputStream p) {
		Socket reenvios = new Socket();
		ArrayList aux = new ArrayList();
		Iterator itr = Servidor.sockets_abiertos.iterator();

		try {
			while (itr.hasNext()) {					//iteramos sobre todo el vector de sockets
			      reenvios = (Socket)itr.next();			//sacamos el siguiente socket
			      if (reenvios != so) {				//reenviamos el paquete a todos menos a "so"
				  p = new DataOutputStream(reenvios.getOutputStream());
				  writeObject(p,mensaje);
			      }
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void writeObject(DataOutputStream out, String mensaje) throws IOException {
		// Longitud de la cadena
		int c = mensaje.length();

                System.out.println("Tamaño de envio: "+c);
	  
		// Se envía la longitud de la cadena + 1 por el \0 necesario en C
		out.writeInt (c+1);

		// Se envía la cadena como bytes.
		out.writeBytes (mensaje);

		// Se envía el \0 del final
		out.writeByte ('\0');
	}

 	public String readObject(DataInputStream in) throws IOException {
		// Se lee la longitud de la cadena y se le resta 1 para eliminar el \0 que nos envía C.
		int c = in.readInt() - 1;
                //int c = 27;
		System.out.println("Tamaño recibido: "+c);

		// Array de bytes auxiliar para la lectura de la cadena.
		byte [] aux = null;
		aux = new byte[c];  // Se le da el tamaño 

		in.read(aux, 0, c); // Se leen los bytes
		String mensaje_salida = new String (aux); // Se convierten a String

		// Se lee el caracter nulo del final
		in.read(aux,0,1);

		return mensaje_salida;
	 }

        public static String readDataFile(DataInputStream b) throws IOException {
                // Se lee la longitud de la cadena y se le resta 1 para eliminar el \0.
                int c = b.readInt() - 1;
                // Array de bytes auxiliar para la lectura de la cadena.
                /*byte [] aux = null;
                byte [] aux2 = null;*/
                byte [] aux = new byte[c];
                byte [] aux2=new byte[1];
                int i=0;
                //leemos byte a byte y lo insertamos en el array
                while (i!=c) {
                        aux[i]=b.readByte();
                        i=i+1;
                }
                // Se lee el caracter nulo del final
                b.read(aux2,0,1);
                return new String(aux);
         }

	 public boolean buscarEnPc(String mensaje) {
	  
		boolean esta = false;

		String[] arrayMsj = mensaje.split("@");					//Separar los campos del mensaje y meterlos en arrayMsj
		String nombre_archivo = arrayMsj[1];
		String ruta = "./Descargas/";
		File fichero = new File(ruta + nombre_archivo);

		if (fichero.exists()) {
		    esta = true;
		    System.out.println("Encontrado archivo " + nombre_archivo);
		}
        
		return esta;
	}

	public void enviarRespuestaBusqueda(DataOutputStream p,String mensaje) throws IOException {

		String[] arrayMsj = mensaje.split("@");					//Separar los campos del mensaje y meterlos en arrayMsj
		InetAddress ip = InetAddress.getLocalHost();
		String ip_string = ip.getHostAddress();

		String mensaje_respuesta = "R@"+arrayMsj[1]+"@"+ip_string+"@"+arrayMsj[2]; // El mensaje de respuesta es: R@nombredearchivo@miip@ipdestino

		try {
		      writeObject(p,mensaje_respuesta);
                      p.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	public void enviarFichero(DataOutputStream p, Socket so, String mensaje) {
		Socket so_vecino = new Socket();
		Iterator itr = Servidor.sockets_abiertos.iterator();

		try {
			// Sacamos el canal de escritura del cliente que nos pide el fichero, ya sea el vecino o no, en
			// cuyo caso tendremos que abrir un nuevo socket y asociarle un canal de escritura
			Boolean no_es_vecino = true;
			System.out.println("Enviando sockets " + Servidor.sockets_abiertos);
			while (itr.hasNext() && no_es_vecino) {					//iteramos sobre todo el vector de sockets
			      so_vecino = (Socket)itr.next();			//sacamos el siguiente socket

			      if (so_vecino == so) {				//Si la descarga nos la pide un vecino
				  no_es_vecino = false;
				  // Abrir nuevo hilo para la descarga
				  HiloDescargas hdesc = new HiloDescargas(p,mensaje);
				  hdesc.start();
			      }
			      else {
				  no_es_vecino = true;
			      }
			}
			
			if (no_es_vecino) { // Crear un nuevo socket cliente para mandar el fichero

			      int puerto = 5000;
			      String[] arrayMsj = mensaje.split("@");
			      String host = arrayMsj[2];
			      Socket so_no_vecino = new Socket(host,puerto);
			      DataOutputStream out = new DataOutputStream ( so_no_vecino.getOutputStream() );
			      HiloDescargas hdesc = new HiloDescargas(out,mensaje);
			      hdesc.start();
			      
			}
			
		} catch (Exception e) {
			e.printStackTrace();
		}
        }	
}
