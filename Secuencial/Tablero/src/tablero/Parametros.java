/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package tablero;

import java.util.ArrayList;

/**
 *
 * @author Paco
 */
public class Parametros {
    private int numeroCuerpos;
    private Coordenada gravedad;
    private ArrayList<Coordenada> cuerpos = new ArrayList() ;
    private int tamano;
    
    Parametros()
    {
        numeroCuerpos = 0;
        gravedad = null;
        tamano=0;
    }
    
    public int getMovimientos()
    {
        return cuerpos.size()/numeroCuerpos;
    }
    
    public void setTamano(int n)
    {
        tamano = n;
    }
    
    public int getTamano()
    {
        return tamano;
    }
    
   public void setNumeroCuerpos(int n)
    {
        numeroCuerpos = n;
    }
    
    public void setGravedad(Coordenada g)
    {
        gravedad = g;
    }
    
    public void addCuerpo(Coordenada c)
    {
        cuerpos.add(c);
    }
    
    
    public int getNumeroCuerpos()
    {
        return numeroCuerpos;
    }
    
    public Coordenada getCuerpo(int i)
    {
        return cuerpos.get(i);
    }
    
    
    public Coordenada getGravedad()
    {
        return gravedad;
    }
    
    
}
