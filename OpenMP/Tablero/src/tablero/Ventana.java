/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tablero;

import javax.swing.JFrame;

/**
 *
 * @author Paco
 */
public class Ventana extends JFrame {
    
    
    public Ventana(Parametros p){
        setSize(1000,1000);
        
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        
        setVisible(true);
           
        add(new Dibujo(p));
        
    }    
}
