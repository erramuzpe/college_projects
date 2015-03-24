package p2p;

import java.io.* ;
import java.net.* ;
import java.util.*;

class Servidor extends Thread{
	static Vector<Socket> sockets_abiertos = new Vector<Socket>();
	static int conexiones_actuales = 0;
	static Hashtable tablaRutas = new Hashtable();
        static Vector<String> ip_respuestas = new Vector<String>();

	public void run () {
		ServerSocket ss;
		Socket so;
		int puerto = 5000;
		int max_conexiones = 2;
                String mensaje;
                String tipoMensaje;
                DataInputStream b;     //Canal de Lectura
                DataOutputStream p;     //Canal de Lectura
	
        	try {
            		ss = new ServerSocket(puerto);  // Se crea el socket servidor ss, asociandolo al numero de puerto especificado para la aplicacion
			while (true) {
                                so = ss.accept();

                                //Obtengo una referencia al canal de lectura  para leer el primer mensaje y ver si es una descarga
                                b = new DataInputStream ( so.getInputStream() );
                                // Canal de escritura
                                p = new DataOutputStream ( so.getOutputStream() );

                         
                                // Leo el primer mensaje
                                mensaje = readObject(b);
                                System.out.println("Primer mensaje: "+mensaje);
                                tipoMensaje = ObtenerTipoMensaje(mensaje);

                                if (tipoMensaje.equalsIgnoreCase("D") ){		//DESCARGA

				    System.out.println("esta en D");
				    enviarFichero(p,so,mensaje);

                                }
				if (conexiones_actuales == max_conexiones){	
				    // Se ha conectado con éxito
				    writeObject(p,"T@N");
				    so.close();
				    
				}
				else {
				    Hilos cliente = new Hilos (so,b,p,mensaje,tipoMensaje,true);
                                    cliente.setName(b.toString());
				    cliente.start();
				}
			}
		} catch (Exception e) {
            		e.printStackTrace();
            		return;
        	} 
	}

	public static void writeObject(DataOutputStream out, String mensaje) throws IOException {
		// Longitud de la cadena
		int c = mensaje.length();
	  
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
		System.out.println("Tamaño: "+c);

		// Array de bytes auxiliar para la lectura de la cadena.
		byte [] aux = null;
		aux = new byte[c];  // Se le da el tamaño 

		in.read(aux, 0, c); // Se leen los bytes
		String mensaje = new String (aux); // Se convierten a String

		// Se lee el caracter nulo del final
		in.read(aux,0,1);

		return mensaje;
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

		/*try {
			String[] arrayMsj = mensaje.split("@");					//Separar los campos del mensaje y meterlos en arrayMsj
			//Socket so_descarga = new Socket(arrayMsj[2],5000);
			String ruta = "./Descargas/";
			File fichero = new File (ruta+arrayMsj[1]);
			FileReader fr = new FileReader(fichero);
			BufferedReader br = new BufferedReader(fr);

		 	// Lectura del fichero
		 	String string_fichero = null;
			String mensaje_fichero = "";
		 	while((string_fichero = br.readLine())!=null) {
		    		mensaje_fichero = mensaje_fichero+string_fichero;
			}
			fr.close();

			System.out.println("P: "+p);
			System.out.println("Mensaje: "+mensaje_fichero);
			// Una vez que tenemos el fichero en el string, ya lo podemos enviar con writeObject
			writeObject(p,mensaje_fichero);

		} catch(Exception e) {
         		e.printStackTrace();
      		}*/
	}

        public String ObtenerTipoMensaje(String mensaje) {
		String[] arrayMsj = mensaje.split("@");
		return arrayMsj[0];
	}
}
