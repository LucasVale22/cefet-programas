import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

public class Ketchup extends Mover
{
    public void act() 
    {
        setLocation(getX(),getY()+2);

        if (atWorldEdge())
        {
            RainBurgerWorld world = (RainBurgerWorld)getWorld();
            
            world.removeObject(this);
        }        
    }    
}

