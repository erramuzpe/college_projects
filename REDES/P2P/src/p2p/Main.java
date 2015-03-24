/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package p2p;

/**
 *
 * @author re38
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {

        try {
            // Pantalla
            new  NewJFrame();
        
            // Correr el servidor
            Servidor serv = new Servidor();
            serv.run();
        }
        catch (Exception e) {
            e.printStackTrace();
        }
    }

}
