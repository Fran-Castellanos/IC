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
import javax.swing.JFrame;

/**
 *
 * @author Paco
 */
public class Ventana extends JFrame {
    
    
    public Ventana(Parametros p){
        setSize(p.getTamano(),p.getTamano());
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setVisible(true);
        int i=0;
           
        add(new Dibujo(p));

        
        
        
        
    }
    
    
}
