import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.awt.Color;
import java.awt.Font;
/**
 * Write a description of class Meters here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Meters extends Scores
{
    private float dist=0;
    private String msg="Km: ";
    private int width=100;
    private int height=50;
    private float fontSize=20;
    private GreenfootImage img;
    private Font font1;
    private Font font2;
    public Meters ()
    {
        changeImg();
    }
    private void changeImg()
    {
        img= new GreenfootImage (width,height);
        font1=img.getFont();
        font2=font1.deriveFont(fontSize);
        img.setFont(font2);
        img.setColor(Color.BLACK);
        img.drawString(msg+(int)dist,0,15);
        setImage(img);
    }
    public void addDist(float mov)
    {
        dist-=mov;
        changeImg();
    }
    public void reset()
    {
        dist=0;
        changeImg();
    }
}
