package p2p;

import java.io.*;
import java.net.Socket;
import java.net.ServerSocket;
import java.net.UnknownHostException;
import java.net.InetAddress;
import java.util.*;

public class Cliente extends Thread{

    public void run () {

        Socket s;
        DataOutputStream p;
        DataInputStream b;

        //String host = "192.168.1.128";
	String host = "172.16.210.23";
	//String host = "10.1.1.142";
        int port = 5000;
        String respuesta;
        String mensaje;
	String fichero_descarga = "archivo.txt";

        //Referencia a la entrada por consola (System.in)
        BufferedReader    in = new BufferedReader(new InputStreamReader(System.in));

        try {

            //Creo una conexion al socket servidor
            s = new Socket(host,port);  

            //Creo las referencias al canal de escritura y lectura del socket
            p = new DataOutputStream ( s.getOutputStream() );
            b = new DataInputStream ( s.getInputStream() );
	    
  	    InetAddress ip = InetAddress.getLocalHost();
	    String ip_string = ip.getHostAddress();		

	    while (true) {
	      String teclado = in.readLine();

	      if (teclado.equalsIgnoreCase("C")) {

		  writeObject(p,"C@"+ip_string);
		  System.out.println("Mensaje conexion: "+readObject(b)); // Mensaje conectado
	      } else if (teclado.equalsIgnoreCase("B")) {

		  //Para sacar la hora actual nuestra
		  long hora_nuestra = System.currentTimeMillis()/1000;
		  writeObject(p,"B@"+fichero_descarga+"@"+ip_string+"@"+hora_nuestra);

		  // Esperar a que llegue el mensaje de respuesta
		  mensaje = readObject(b); 
		  System.out.println("Recepcion " + mensaje );
	      }
		else if (teclado.equalsIgnoreCase("D")) {
		  writeObject(p,"D@"+fichero_descarga+"@"+ip_string); //Escribir el mensaje de descarga

		  Socket so_vecino = new Socket();
		  Iterator itr = Servidor.sockets_abiertos.iterator();

		  try {
			  // Sacamos el canal de lectura del servidor que nos manda el fichero, ya sea el vecino o no, en
			  // cuyo caso tendremos que escuchar en un nuevo socket y asociarle un canal de lectura
			  Boolean no_es_vecino = true;

			  while (itr.hasNext() && no_es_vecino) {					//iteramos sobre todo el vector de sockets
				so_vecino = (Socket)itr.next();			//sacamos el siguiente socket

				if (so_vecino == s) {				//Si el envio es de un vecino
				    no_es_vecino = false;
				    // Abrir nuevo hilo para la descarga
				    descargarFichero(b,fichero_descarga);
				}
				else {
				    no_es_vecino = true;
				}
			  }
			  
			  if (no_es_vecino) { // Crear un nuevo socket servidor para recibir el fichero

				int puerto = 5000;
				ServerSocket ss = new ServerSocket(puerto); // Socket servidor
				Socket so = ss.accept();
				//Obtengo una referencia al canal de lectura del socket cliente
				DataInputStream inp = new DataInputStream ( so.getInputStream() );
				descargarFichero(inp,fichero_descarga);
				so.close();
				
			  }
			  
		  } catch (Exception e) {
			  e.printStackTrace();
		  }

     		  //descargarFichero(b,fichero_descarga);
	      }



	    //while (true) {
		//System.out.println(readObject(b));
	    //}  
	    }
            
        } catch (UnknownHostException e) {
            System.out.println("No puedo conectarme a " + host + ":" + port);
        } catch (IOException e) {
            System.out.println("Error de E/S en " + host + ":" + port);
	} catch (Exception e) {
            System.out.println("Error");
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

 	public static String readObject(DataInputStream in) throws IOException {
		// Se lee la longitud de la cadena y se le resta 1 para eliminar el \0 que nos envía C.
		int c = in.readInt() - 1;

		// Array de bytes auxiliar para la lectura de la cadena.
		byte [] aux = null;
		aux = new byte[c];  // Se le da el tamaño 

		in.read(aux, 0, c); // Se leen los bytes
		String mensaje = new String (aux); // Se convierten a String

		// Se lee el caracter nulo del final
		in.read(aux,0,1);

		return mensaje;
	 }

	/*public static void descargarFichero(DataInputStream b, String fichero_descarga) {
		

		try {

		      // Se lee la longitud de la cadena y se le resta 1 para eliminar el \0 que nos envía C.
		    int c = b.readInt() - 1;
		    while ((c = b.readByte()) != -1) {
			
			

			// Array de bytes auxiliar para la lectura de la cadena.
			byte [] aux = null;
			aux = new byte[c];  // Se le da el tamaño 

			b.read(aux, 0, c); // Se leen los bytes
			String mensaje = new String (aux); // Se convierten a String

			// Se lee el caracter nulo del final
			b.read(aux,0,1);
			System.out.println("Recepcion " + mensaje );
			String ruta = "./Descargas/";
			File fichero = new File (ruta+fichero_descarga);
			FileInputStream in = new FileInputStream(fichero);
			//int tam = mensaje.length();
			//byte[] buf = new byte[tam];
			//int longi;

			// Para escribir el fichero
			FileOutputStream fw = new FileOutputStream(fichero);
			//BufferedWriter bw = new BufferedWriter(fw);

			//bw.write(mensaje);

			fw.write(mensaje, 0, c);
			}



			System.out.println("COMPLETADO!");
			fw.flush();
			fw.close();			

		} catch(Exception e) {
         		e.printStackTrace();
      		}
	}*/

	public static void descargarFichero(DataInputStream b, String fichero_descarga) {
	      
		try {
			String mensaje = readDataFile(b);   //Recibir mensaje de descarga byte a byte para que no haya problemas con las fotos
			System.out.println("Recepcion " + mensaje );
			String ruta = "./Descargas/";
			File fichero = new File (ruta+fichero_descarga);
			FileInputStream in = new FileInputStream(fichero);
			int tam = mensaje.length();
			byte[] buf = new byte[tam];
			int longi;

			// Para escribir el fichero
			FileOutputStream fw = new FileOutputStream(fichero);
			//BufferedWriter bw = new BufferedWriter(fw);

			//bw.write(mensaje);
		 	while ((longi = in.read(buf)) != -1) {
			      fw.write(buf, 0, longi);
			}
			System.out.println("COMPLETADO!");
			fw.flush();
			fw.close();			

		} catch(Exception e) {
         		e.printStackTrace();
      		}
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
}
