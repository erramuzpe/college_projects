package p2p;

import java.util.*;
import java.net.*; 
import java.io.*;

public class HiloDescargas extends Thread{

	DataOutputStream p; 
	String mensaje;

    	public HiloDescargas (DataOutputStream p, String mensaje) {

		this.p = p;
		this.mensaje = mensaje;

    	}

   	public void run() {

		enviar(p,mensaje);

   	}

	public static void enviar(DataOutputStream p, String mensaje) {
	      
		try {
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
		    		mensaje_fichero = mensaje_fichero+string_fichero+"\n";
			}
			fr.close();			

			System.out.println("P: "+p);
			System.out.println("Mensaje: "+mensaje_fichero);
			// Una vez que tenemos el fichero en el string, ya lo podemos enviar con writeObject
			writeObject(p,mensaje_fichero);

		} catch(Exception e) {
         		e.printStackTrace();
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
}