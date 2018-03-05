import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;

/**
 * Write a description of class Plane here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Plane extends Movers
{
    private List <Woody> woody;
    private boolean contact=true;
    private int actCount=0;
    private GreenfootSound snd=new GreenfootSound("Plane.wav");
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
        if(actCount%72==0)
        {
            setImage("airplane_0.png");
        }
        if(actCount%72==24)
        {
            setImage("airplane_1.png");
        }
        if(actCount%72==48)
        {
            setImage("airplane_2.png");
        }
        actCount++;
    }
    public void act() 
    {
        if(checaWoody())
        {
            Worlds.point.addPoints(200);
            snd.play();
        }
        changeImg();
    }    
}
