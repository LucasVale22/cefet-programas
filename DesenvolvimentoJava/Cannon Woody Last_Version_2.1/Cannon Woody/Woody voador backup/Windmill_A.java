import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;
/**
 * Write a description of class Windmill_A here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Windmill_A extends Enemy
{
    private int count=0;
    private GreenfootSound snd=new GreenfootSound("Windmill.wav");
    private void rotate()
    {
        setRotation(getRotation()+4);
    }
    private boolean checaWoody()
    {
        hero=getObjectsInRange(100,Woody.class);
        if(!hero.isEmpty()&&woody==null)
        {
            woody=hero.get(0);
            return true;
        }
        else
        {
            return false;
        }
    }
    public void act() 
    {
        if(inWorld())
        {
            rotate();
        }
        if(checaWoody()||count>0)
        {
            if(count<=75)
            {
                if(count==0)
                {
                    snd.setVolume(35);
                    snd.play();
                }
                woody.rotation=65;
                woody.velocity();
                if(checaWoody())
                {
                    woody.move();
                }
                count++;
            }
        }
        worldEdgeRemove();
    }    
}
