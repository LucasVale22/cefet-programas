import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;

/**
 * Write a description of class Rainy_Cloud here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Rainy_Cloud extends Cloud
{
    private List <Woody> woody;
    private boolean contact=true;
    private int actCount=0;
    private GreenfootSound snd=new GreenfootSound("Lightning.wav");
    private boolean checaWoody()
    {
        woody=getObjectsAtOffset(0,0,Woody.class);
        if(!woody.isEmpty()&&contact)
        {
            contact=false;
            return true;
        }
        else
        {
            return false;
        }
    }    
    private void changeImg()
    {
        if(actCount%48==0)
        {
            setImage("rcloud_0.png");
        }
        if(actCount%48==24)
        {
            setImage("rcloud_1.png");
        }
        actCount++;
    }
    public void act() 
    {
        if(checaWoody())
        {
            Worlds.lift.real+=126;
            Worlds.lift.consume();
            snd.play();
        }
        changeImg();
    }    
}
