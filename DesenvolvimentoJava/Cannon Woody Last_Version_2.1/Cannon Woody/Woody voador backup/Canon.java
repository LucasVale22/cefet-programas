import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.math.*;
/**
 * Write a description of class Canon here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Canon extends N_Hero
{
    /**
     * Act - do whatever the Canon wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    private int rotation=0;
    private int i=1;
    private boolean launch=false;
    private double y2;
    private double x2;
    private int y;
    private int x;
    private int actCount=0;
    private Lifter lift;
    private Booster boost;
    private Meters meter;
    private Points point;
    private Cannon world;
    private Arcade arcade;
    public static Woody woody;
    private GreenfootSound snd=new GreenfootSound("Cannon.wav");
    public Canon(Lifter lift,Booster boost,Meters meter,Points point,Cannon world)
    {
        this.lift=lift;
        this.boost=boost;
        this.meter=meter;
        this.point=point;
        this.world=world;
    }
    public Canon(Lifter lift,Booster boost,Meters meter,Points point,Arcade world)
    {
        this.lift=lift;
        this.boost=boost;
        this.meter=meter;
        this.point=point;
        this.arcade=world;
    }
    public void act() 
    {
        if(!launch)
        {
            setRotation(rotation);
            rotation+=i;
            if (rotation==90)
            i=-1;
            if (rotation==20)
            i=1;
            if (Greenfoot.isKeyDown("space")&& !launch)
            {
                snd.play();
                y2= 100*Math.cos(Math.toRadians(rotation));
                x2= 100*Math.sin(Math.toRadians(rotation));
                x=(int) x2;
                y=(int) y2;
                woody=new Woody(rotation,lift,boost,meter,point,world);
                setImage("cannon_1.png");
                getWorld().addObject(woody,getX()+x,getY()-y);
                launch=true;
            }
        }
        else
        {
            if(actCount>=15)
            {
                setImage("cannon_2.png");
            }
            if(actCount>=30)
            {
                setImage("cannon_4.png");
            }
            if(actCount>=45)
            {
                setImage("cannon_5.png");
            }
            if(actCount>=55)
            {
                setImage("cannon_3.png");
            }
            actCount++;
        }
    }
}
