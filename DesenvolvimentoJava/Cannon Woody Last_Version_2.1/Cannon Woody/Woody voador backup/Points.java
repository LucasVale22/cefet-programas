import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.awt.Color;
import java.awt.Font;
/**
 * Write a description of class Meters here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Points extends Scores
{
    public int points=0;
    private String msg="Score: ";
    private int width=250;
    private int height=50;
    private float fontSize=20;
    private GreenfootImage img;
    private Font font1;
    private Font font2;
    public Points ()
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
        img.drawString(msg+points,0,15);
        setImage(img);
    }
    public void addPoints(int num)
    {
        points+=num;
        changeImg();
    }
        public void reset()
    {
        points=0;
        changeImg();
    }
}
