/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tablero;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Paco
 */
public class Dibujo extends Canvas{
    
    private final Parametros p;
    private int indice;
    
    public Dibujo(Parametros p)
    {
        setBackground(Color.GRAY);
        this.p = p;
        indice = 0;
    }
    
    
 
    @Override
    public void update (Graphics g)
   {
      paint (g);
   }
    
    

    @Override
    public void paint(Graphics g) {
        
        ArrayList<Color> color = new ArrayList();
        
        color.add(Color.GREEN);
        color.add(Color.BLUE);
        color.add(Color.CYAN);
        color.add(Color.ORANGE);
        color.add(Color.PINK);
        

        
         g.setColor(Color.red);
         g.fillRect(p.getGravedad().getX(), p.getGravedad().getY(), 25, 25);
         
         
         int k = indice;
         
         for(int i = 0; i< p.getNumeroCuerpos();i++)
         {
             g.setColor(color.get(i%color.size()));
             
             g.fillRect(p.getCuerpo(indice).getX(),p.getCuerpo(indice).getY(), 25, 25);
             indice++;
            
         }
         
        try {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {
            Logger.getLogger(Dibujo.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
        if(indice<p.getMovimientos()){
            for(int i = 0; i< p.getNumeroCuerpos();i++)
             {

                 g.clearRect(p.getCuerpo(k).getX(),p.getCuerpo(k).getY(), 25, 25);
                 k++;
             }
        
            repaint();
        }
    }
    
    
    
    
}
