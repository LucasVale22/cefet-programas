import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.awt.Color;
/**
 * Write a description of class Energy here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public abstract class Energy extends Actor
{
    protected GreenfootImage img;
    protected int width=100;
    protected int height=15;
    protected Color color;
    protected Color color2;
    public Energy()
    {
        color2=new Color (255,255,255);
    }
    protected abstract void consume ();
}
