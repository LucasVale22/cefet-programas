import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;

/**
 * Write a description of class Tornado here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Tornado extends Enemy
{
    private boolean contact=false;
    private int count=0;
    private int actCount=0;
    private GreenfootSound snd=new GreenfootSound("Tornado.wav");
    private void tornadoSprite()
    {
        woody.setImage("woody_4.png");
    }
    private void standardSprite()
    {
        woody.setImage("woody_0.png");
    }
    private void checaWoody()
    {
        hero=getObjectsAtOffset(0,0,Hero.class);
        if(!hero.isEmpty()&&woody==null)
        {
            woody=hero.get(0);
            Worlds.point.addPoints(500);
            contact=true;
        }
    }
    private void changeImg()
    {
        if(actCount%60==0)
        {
            setImage("tornado_0.png");
        }
        if(actCount%60==12)
        {
            setImage("tornado_1.png");
        }
        if(actCount%60==24)
        {
            setImage("tornado_2.png");
        }
        if(actCount%60==36)
        {
            setImage("tornado_3.png");
        }
        if(actCount%60==48)
        {
            setImage("tornado_3.png");
        }
        actCount++;
    }
    public void act() 
    {
        if(!contact)
        {
           checaWoody();
           if(inWorld())
           {
               setLocation(getX()-1,getY()-1);
           }
        }
        else
        {
            if(count<=250)
            {
                if(count==0)
                {
                    snd.play();
                }
                tornadoSprite();
                woody.rotation=75;
                woody.velocity();
                woody.move();
                woody.move();
                woody.moverX(1);
                count++;
            }
            else
            {  
                getWorld().removeObject(this);
            }
        }
        changeImg();
    }    
}
