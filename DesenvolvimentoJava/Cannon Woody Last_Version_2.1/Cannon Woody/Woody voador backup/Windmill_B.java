import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;

/**
 * Write a description of class Windmill_B here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Windmill_B extends Enemy
{
    private List <Ground> obj;
    private boolean contact=false;
    private int count=0;
    private void crashSprite()
    {
        woody.setImage("woody_5.png");
    }
    private void checaWoody()
    {
        hero=getObjectsInRange(80,Hero.class);
        if(!hero.isEmpty()&&woody==null)
        {
            woody=hero.get(0);
            Worlds.point.addPoints(500);
            contact=true;
        }
    }
    public void act() 
    {
        if(!contact)
        {
           checaWoody();
        }
        else
        {
            if(!woody.contact())
            {
                crashSprite();
                woody.setRotation(0);
                woody.moverY(-1);
            }
            else
            {
                woody.vXFall=-1;
                try
                {
                    Thread.sleep(500);
                }catch(Exception e)
                {
                    System.out.println(e);
                }
                woody.fall();
            }
        }
    }      
}
