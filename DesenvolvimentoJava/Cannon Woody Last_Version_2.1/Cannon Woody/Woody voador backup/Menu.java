import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Menu here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Menu extends World
{

    /**
     * Constructor for objects of class Menu.
     * 
     */
    public static GreenfootSound snd=new GreenfootSound("Music Menu.wav");
    public Menu()
    {    
        super(600, 400, 1);
        prepare();
        snd.setVolume(66);
        snd.playLoop();
    }
    

    private void prepare()
    {
        addObject(new Start_Game(),385,306);
        addObject(new Start_Arcade(),387,367);
    }
}
