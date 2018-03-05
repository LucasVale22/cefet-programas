import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

public class Splat  extends Actor
{
    private int splatLife = 0;

    public void act() 
    {
        // makes the splat go away every 10 acts
        if (splatLife++ == 10)
        {
            getWorld().removeObject(this);
        }
    }    
}
