import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;

/**
 * Write a description of class Trampoline here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Trampoline extends Movers
{
    private List <Woody> hero;
    private Woody woody;
    private boolean isTrue=false;
    private int actCount=0;
    private GreenfootSound snd=new GreenfootSound("Bouncing.wav");
    private boolean checaWoody()
    {
        hero=getObjectsAtOffset(0,-10,Hero.class);
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
    private void rodaWoody()
    {
        woody.rotation=170-woody.rotation;
        woody.velocity();
        woody.move();
        woody.move();
        woody.move();
    }
    public void act() 
    {
        if(checaWoody())
        {
            snd.setVolume(50);
            snd.play();
            rodaWoody();
            isTrue=true;
        }
        if(isTrue)
        {
            if(actCount==0)
            {
                setImage("trampolim_1.png");
            }
            if(actCount>=20)
            {
                setImage("trampolim_0.png");
            }
            actCount++;
        }
        worldEdgeRemove();
    }    
}
