/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tablero;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.awt.image.BufferedImage;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Paco
 */
public class Dibujo extends Canvas{
    
    private Parametros p;
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

        //BufferedImage imagen = new BufferedImage (getWidth(), getHeight(),255);
        
        ArrayList<Color> color = new ArrayList();
        
        color.add(Color.GREEN);
        color.add(Color.BLUE);
        color.add(Color.CYAN);
        color.add(Color.ORANGE);
        color.add(Color.PINK);
        

        
         g.setColor(Color.red);
         g.fillRect(p.getGravedad().getY(), p.getGravedad().getX(), 5*p.getTamano()/100, 5*p.getTamano()/100);
         
         
         int k = indice;
         
         for(int i = 0; i< p.getNumeroCuerpos();i++)
         {
             g.setColor(color.get(i%color.size()));
             
             g.fillRect(p.getCuerpo(indice).getY(),p.getCuerpo(indice).getX(),5*p.getTamano()/100, 5*p.getTamano()/100 );
             indice++;
            
         }
         
         //g.drawImage(imagen, 0, 0, this);

         
        try {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {
            Logger.getLogger(Dibujo.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        
        if(indice<p.getMovimientos()){
            for(int i = 0; i< p.getNumeroCuerpos();i++)
             {

                 g.clearRect(p.getCuerpo(k).getY(),p.getCuerpo(k).getX(),5*p.getTamano()/100, 5*p.getTamano()/100 );
                 k++;
             }
        
            repaint();
        }
    }
    
    
    
    
}
