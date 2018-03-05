import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.awt.Font;
/**
 * Write a description of class Menus here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public abstract class Menus extends Actor
{
    protected GreenfootImage img;
    protected int width=400;
    protected int height=100;
    protected int actCount=0;
    private int transValue;
    protected float fontSize=40;
    private boolean toZero=true;
    protected Font font1;
    protected Font font2;
    protected MouseInfo mInfo;
    public void transparency()
    {
        transValue=img.getTransparency();
        if(toZero)
        {
            transValue-=17;
        }
        else
        {
            transValue+=17;
        }
        if(transValue==0)
        {
            toZero=false;
        }
        if(transValue==255)
        {
            toZero=true;
        }
        img.setTransparency(transValue);
        setImage(img);
    }
}
