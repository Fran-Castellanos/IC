/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tablero;

/**
 *
 * @author Paco
 */
public class Coordenada {
    private int x;
    private int y;
    
    
    Coordenada()
    {
        x=y=0;
    }
    
    Coordenada(Coordenada c)
    {
        x = c.x;
        y = c.y;
    }
    
    Coordenada(int x, int y)
    {
        this.x = x;
        this.y = y;
    }
    
    Coordenada(String s)
    {
        String[] aux;

        aux = s.split(",");

        System.out.println("s: " + s);
        System.out.println("aux0: " + aux[0]);
        System.out.println("aux1: " + aux[1]);

        
        String[] aux2 = aux[0].split("\t");
        
        System.out.println("s2: " + s);
        System.out.println("aux02: " + aux2[0]);

        
        x = Integer.parseInt(aux2[0]);
        
        aux2 = aux[1].split("\t");
        
        y = Integer.parseInt(aux2[0]);
    }
    
    
    
    
    public int getX(){
         return x;
    }
           
    
    public int getY(){
            return y;
    }
    
    
}
