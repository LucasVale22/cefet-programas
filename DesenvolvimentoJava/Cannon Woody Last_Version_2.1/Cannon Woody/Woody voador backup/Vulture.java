import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;

/**
 * Write a description of class Vulture here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Vulture extends Movers
{
    private List <Woody> woody;
    private boolean contact=true;
    private int actCount=0;
    private GreenfootSound snd=new GreenfootSound("Bird.wav");
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
            setImage("vulture_0.png");
        }
        if(actCount%48==12)
        {
            setImage("vulture_1.png");
        }
        if(actCount%48==24)
        {
            setImage("vulture_2.png");
        }
        if(actCount%48==36)
        {
            setImage("vulture_3.png");
        }
        actCount++;
    }
    public void act() 
    {
        if(checaWoody())
        {
            Worlds.lift.real-=124;
            Worlds.lift.consume();
            snd.play();
        }
        setLocation(getX()-1,getY());
        changeImg();
    }    
}
