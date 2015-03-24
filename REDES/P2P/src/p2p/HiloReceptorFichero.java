package p2p;

import java.io.*;

public class HiloReceptorFichero extends Thread{

	DataInputStream b;
	String fichero_descarga;

    	public HiloReceptorFichero (DataInputStream b, String fichero_descarga) {

		this.b = b;
		this.fichero_descarga = fichero_descarga;

    	}

   	public void run() {

		descargarFichero(b,fichero_descarga);

   	}

	public static void descargarFichero(DataInputStream b, String fichero_descarga) {

                    try {
                            String mensaje_d = readDataFile(b);   //Recibir mensaje de descarga byte a byte para que no haya problemas con las fotos

                            System.out.println("Recepcion " + mensaje_d );
                            String ruta = "./Descargas/";
                            File fichero = new File (ruta+fichero_descarga);
                            //FileInputStream in = new FileInputStream(fichero);
                            int tam = mensaje_d.length();
                            byte[] buf = new byte[tam];
                            int longi;
                            InputStream in = new ByteArrayInputStream( mensaje_d.getBytes() );

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

                    } catch(Exception e) {
                            e.printStackTrace();
                            //escribirTA1 ("Se ha producido un ERROR descargando el fichero: "+fichero_descarga+".\n");
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
