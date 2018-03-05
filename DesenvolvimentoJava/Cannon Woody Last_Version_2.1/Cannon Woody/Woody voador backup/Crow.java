import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;

/**
 * Write a description of class Crow here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Crow extends Movers
{
    private List <Woody> hero;
    private Woody woody;
    private int actCount=0;
    private GreenfootSound snd=new GreenfootSound("Bird.wav");
    private void move()
    {
        setLocation(getX()-2,getY());
    }
    private boolean checaWoody()
    {
        hero=getObjectsAtOffset(0,0,Hero.class);
        if((!hero.isEmpty())&&(woody==null))
        {
          woody=hero.get(0);
          return true;
        }
        else
        {
            return false;
        }
    }
    private void changeImg()
    {
        if(actCount%36==0)
        {
            setImage("crow_0.png");
        }
        if(actCount%36==12)
        {
            setImage("crow_1.png");
        }
        if(actCount%36==24)
        {
            setImage("crow_3.png");
        }
        actCount++;
    }
    public void act() 
    {
        if(inWorld())
        {
            move();
        }
        if(checaWoody())
        {
            woody.rotation=120;
            snd.setVolume(50);
            snd.play();
        }
        changeImg();
        worldEdgeRemove();
    }    
}
