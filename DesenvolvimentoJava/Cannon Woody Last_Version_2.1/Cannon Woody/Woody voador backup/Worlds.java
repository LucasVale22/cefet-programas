import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.List;
/**
 * Write a description of class Worlds here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public abstract class Worlds extends World
{

    
    protected int x;
    protected int y;
    protected int i=0;
    public static int actualLevel=0;
    protected static String levelS="fase";
    protected static String levelE=".txt";
    protected static List <N_Hero> obj;
    public static Lifter lift;
    protected static Booster booster;
    protected static Meters meter;
    public static Points point;
    protected static Canon canon;
    protected static Rodape rodape;
    protected static String line;
    protected static List <Ground> grounds;
    protected static List <Movers> objs;
    protected static GreenfootSound snd=new GreenfootSound("Music Game.wav");
    public Worlds(int width,int height,int cels,boolean bound)
    {    
        // Create a new world with 600x400 cells with a cell size of 1x1 pixels.
        super(width, height, cels,bound); 
    }
    public abstract void mountLevel() throws Exception;
}
