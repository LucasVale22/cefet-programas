import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.awt.*;
/**
 * Write a description of class Starting_Greeting here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Starting_Greeting extends Menus
{
    private String msg="Press any Button";
    private String key;
    
    public Starting_Greeting()
    {
        img=new GreenfootImage(width,height);
        font1=img.getFont();
        font2=font1.deriveFont(fontSize);
        img.setFont(font2);
        img.setColor(Color.WHITE);
        img.drawString(msg,0,50);
        setImage(img);
    }
    public void act() 
    {
        key=Greenfoot.getKey();
        mInfo=Greenfoot.getMouseInfo();
        if(mInfo!=null)
        {
            if(key!=null||mInfo.getButton()==1)
            {
                getWorld().addObject(new Start_Game(),525,300);
                getWorld().addObject(new Start_Arcade(),525,375);
                getWorld().removeObject(this);
            }
        }
        if(actCount%2==0)
        {
            transparency();
        }
        actCount++;
    }    
}
