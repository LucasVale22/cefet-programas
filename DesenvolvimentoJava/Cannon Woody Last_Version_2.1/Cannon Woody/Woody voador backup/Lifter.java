import greenfoot.*;
import java.awt.Color;
/**
 * Write a description of class Lifter here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Lifter extends Energy 
{
    // instance variables - replace the example below with your own
    public static int real=500;
    private int energy;
    public Lifter()
    {
        reset();
    }
    protected void consume()
    {
        real--;
        if(real>=5)
        {
            energy=Math.round(real/5);
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
        real=500;
        img= new GreenfootImage(width,height);
        img.drawRect(0,0,width,height);
        color=new Color (31,132,204);
        img.setColor(color);
        img.fill();
        setImage(img);
    }
}
