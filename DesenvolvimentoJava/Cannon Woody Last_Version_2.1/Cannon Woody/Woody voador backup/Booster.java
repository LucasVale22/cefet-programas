import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.awt.Color;
/**
 * Write a description of class Booster here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Booster extends Energy 
{
    // instance variables - replace the example below with your own
    public int real=5;
    private int energy;
    public Booster()
    {
        reset();
    }
    protected void consume()
    {
        real--;
        if(real>0)
        {
            energy=real*100/5;
            img= new GreenfootImage(energy,height);
            img.drawRect(0,0,energy,height);
            img.setColor(color);
            img.fill();
            setImage(img);
        }
        else
        {
            img= new GreenfootImage(energy,height);
            img.setColor(color2);
            setImage(img);
        }
    }
    public void reset()
    {
        real=5;
        img= new GreenfootImage(width,height);
        img.drawRect(0,0,width,height);
        color=new Color (250,154,57);
        img.setColor(color);
        img.fill();
        setImage(img);
    }
}
