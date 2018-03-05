import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;
import java.math.*;
import java.lang.*;
/**
 * Write a description of class Woody here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Woody extends Hero
{
    public  int rotation;
    private int vXin=5;
    private int vYin=10;
    public int vXFall=3;
    private int act=100;
    private int velX;
    private int velY;
    private int i;
    private int descRatio=25;
    private int count=0;
    private int actCount=0;
    private int fallCount=0;
    private int countAct=0;
    private int fase=1;
    private double tan;
    private boolean rightdown=false;
    private GreenfootSound sndFall=new GreenfootSound("Floor.wav");
    private GreenfootSound sndDash=new GreenfootSound("Dash.wav");
    private static Lifter lift;
    private static Booster boost;
    private Actor ground;
    private static Meters meter;
    private static Points point;
    private static Show_Points sPoints;
    private static Restart restart;
    private static Next next;
    private static Background background;
    public static Worlds world;
    public Woody(int rotation,Lifter lift,Booster boost,Meters meter,Points point, Worlds world)
    {
        this.rotation=rotation;
        setRotation (rotation);
        velX=(int)(vXin*Math.sin(Math.toRadians(rotation)));
        velY=(int)(vYin*Math.cos(Math.toRadians(rotation)));
        this.lift=lift;
        this.boost=boost;
        this.meter=meter;
        this.point=point;
        this.world=world;        
    }
    public void move()
    {
        moverX(-velX);
        moverY(velY);
    }
    private void rotate()
    {
         if(rotation<180 && count % descRatio==0)
         {
            rotation+=5;
         }
         else
         {
            if(count % descRatio==0)
            i+=5;
         }
    }
    private void normalSprite()
    {
        if(countAct%100==0)
        {
            setImage("woody_0.png");
        }
        if(countAct%100==50)
        {
            setImage("woody_3.png");
        }
    }
    private void liftSprite()
    {
        if(countAct%26==0)
        {
            setImage("woody_1.png");
        }
        if(countAct%26==13)
        {
            setImage("woody_2.png");
        }
    }
    private void boostSprite ()
    {
            setImage("woody_4.png");
    }
    private void fallSprite()
    {
        setImage("woody_5.png");
    }
    private boolean lift()
    {
        if(Greenfoot.isKeyDown("space")&&lift.real>0)
        {
            if(i==0 && rotation>=0)
            {
                rotation--;
            }
            else
            {
                i--;
            }
            lift.consume();
            return true;
        }
        return false;
    }
    public void velocity()
    {
        velX=(int)(vXin*Math.sin(Math.toRadians(rotation)));
        velY=(int)(vYin*Math.cos(Math.toRadians(rotation)));
        setRotation(rotation);
        count++;
    }
    private boolean boost()
    {
        if(boost.real>=0)
        {
            if ((Greenfoot.isKeyDown("right")&&!rightdown)||(actCount>0))
            {
                if(actCount==0)
                {
                    boost.consume();
                    sndDash.stop();
                    sndDash.setVolume(50);
                    sndDash.play();
                    actCount=30;
                }
                else
                actCount--;
                rightdown=true;
                rotation=90;
                moverX(-10);
                return true;
            }
            else
            {
                if(!Greenfoot.isKeyDown("right"))
                rightdown=false;
                return false;
            }
        }
        else 
        return false;
    }
    public boolean contact()
    {
        ground=getOneObjectAtOffset (0,8,Ground.class);
        if(ground!=null)
        {
            fallSprite();
            sndFall.setVolume(35);
            sndFall.play();
            return true;
        }
        else
        {
            return false;
        }
    }
    public static void resetAll()
    {
        meter.reset();
        point.reset();
        boost.reset();
        lift.reset();
    }
    public void fall()
    {
        setRotation(90);
        if(vXFall>=0)
        {
            setLocation(getX()+vXFall,getY());
            if(fallCount%45==0)
            {
                vXFall--;
            }
        }
        else 
        {
            Worlds.snd.stop();
            if(world instanceof Cannon)
            {
                sPoints=new Show_Points(point.points);
                background=new Background();
                restart=new Restart();
                next=new Next();
                getWorld().addObject(sPoints,300,200);
                getWorld().addObject(background,300,200);
                background.failImg();
                getWorld().addObject(restart,150,315);
                if(point.points>Show_Points.req)
                {
                    background.victoryImg();
                    getWorld().addObject(next,450,315);
                }
            }
            else
            {
                Greenfoot.setWorld(new Ranking(point.points));
            }
        }
        fallCount++;
    }
    private boolean checaContact()
    {
        List <Enemy> enemy=getObjectsAtOffset(0,0,Enemy.class);
        if(enemy.isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    public void act() 
    {
        if(checaContact())
        {
            if(!contact())
            {
                if (act!=0)
                {
                    move();
                    act--;
                }
                else 
                {
                    move();
                    if(!boost())
                    {
                        rotate();
                        if(lift())
                        {
                            liftSprite();
                        }
                        else
                        {
                            normalSprite();
                        }
                    }
                    else 
                    {
                        if(boost.real>=0)
                        {
                            boostSprite();
                        }
                    }
                    velocity();
                }
            }
            else
            {
                fall();
            }
        }
    }   
    public void moverX (int vel)
    {
        if((getX()==76)||(act!=0)||(countAct%4!=0))
        {
            List <N_Hero> obj=getWorld().getObjects(N_Hero.class);
            for (N_Hero i : obj)
            {
                i.setLocation(i.getX()+vel,i.getY());
            }
        }
        else 
        {
            setLocation(getX()-1,getY());
        }
        if(countAct%10==0)
        {
            meter.addDist((float)vel/10);
        }
        if(countAct%2==0)
        {
            point.addPoints(1);
        }
        countAct++;
    }
    private boolean checaY(List <N_Hero> obj,int vel)
    {
        for (N_Hero i : obj)
        {
            if ((i.getY()>=395)||vel>0)
            {
                return true;
            }
        }
        return false;
    }
    public void moverY(int vel)
    {
        if(getY()<=110)
        {
            List <N_Hero> obj=getWorld().getObjects(N_Hero.class);
            if(checaY(obj,vel))
            {
                for (N_Hero i : obj)
                {
                    i.setLocation(i.getX(),i.getY()+vel);
                }
            }
            else
            {
                this.setLocation(getX(),getY()-vel);
            }
        }
        else
        {
            setLocation(getX(),getY()-vel);
        }
    }
}
