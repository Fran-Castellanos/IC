/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tablero;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Paco
 */
public class Tablero {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        
        
        Parametros p = new Parametros();
        Coordenada g = new Coordenada();
        
        if(args.length>0){
            File archivo = new File(args[0]);
            try {
                FileReader fr = new FileReader(archivo);
                BufferedReader br = new BufferedReader(fr);

                String linea = br.readLine();
                p.setNumeroCuerpos(Integer.parseInt(linea));

                linea = br.readLine();
                p.setGravedad(new Coordenada(linea));



                while((linea = br.readLine())!= null)
                {


                    if(linea.contains(","))
                    {
                        String[] aux = linea.split("\t");
                        for (String aux1 : aux) {
                            p.addCuerpo(new Coordenada(aux1));
                        }
                    }else
                    {
                        
                        p.setTamano(Integer.parseInt(linea));
                    }
                }


                Ventana v = new Ventana(p);
                
                
            } catch (FileNotFoundException ex) {
                Logger.getLogger(Tablero.class.getName()).log(Level.SEVERE, null, ex);
            } catch (IOException ex) {
                Logger.getLogger(Tablero.class.getName()).log(Level.SEVERE, null, ex);
            }

      
        }
    }
    
}
