import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.awt.Color;

/**
 * Write a description of class Lifes here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Life extends Actor
{
    private int life = 3;
    private int count = 0;
    
    public Life()
    {               
       updateImage();
    }  
    
    public void takeLife()
    {
        life--;
        updateImage();
    }    
    
    public void updateImage()
    {
        // texto, tamanho da fonte, cor de fonte, cor de fundo
        GreenfootImage image = new GreenfootImage("Lifes: "+life,          
                                   30,
                                   new Color(0,0,0,200),
                                   new Color(255,255,255,0)); 
                                   
        // adiciona o texto para ser desenhado
        setImage(image);  
    }
    
    public boolean isDead()
    {
        return life==0;
    }
    
    public void giveLife()
    {
        life++;
        updateImage();
    }
}
