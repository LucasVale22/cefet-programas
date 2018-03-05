import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.awt.Color;
/**
 * Write a description of class Start_Game here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Start_Arcade extends Menus
{
    public void act()
    {
        mInfo=Greenfoot.getMouseInfo();
        if(mInfo!=null)
        {
            if((mInfo.getActor()==this)&&(mInfo.getButton()==1))
            {
                Menu.snd.stop();
                Greenfoot.setWorld(new Arcade());
            }
        }
    }
}
