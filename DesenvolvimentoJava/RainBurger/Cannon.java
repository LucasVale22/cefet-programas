import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

public class Cannon  extends Actor
{
    private int fireRatio = 0;
    private int fireLimit = 15;

    public void act() 
    {
        if (Greenfoot.isKeyDown("left"))
        {
            setRotation (getRotation() - 5);
        }
        
        if (Greenfoot.isKeyDown("right"))
        {
            setRotation (getRotation() + 5);
        }
        
        if (Greenfoot.isKeyDown("space") && fireRatio == 0)
        {
            fire();
            fireRatio = 1;
        }
        
        // Forces a minimum 5 act interval between every shot
        if (fireRatio >= 1)
            fireRatio++;
        
        if (fireRatio == fireLimit)
            fireRatio = 0;
    }    
    
    private void fire()
    {
        Blob blob = new Blob();
        getWorld().addObject(blob, getX(), getY());
        blob.setRotation(getRotation());
        blob.move(40.0);
    }
}



