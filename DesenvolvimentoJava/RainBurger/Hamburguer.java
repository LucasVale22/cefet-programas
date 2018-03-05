import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

public class Hamburguer extends Mover
{
    public void act() 
    {
        setLocation(getX(),getY()+1);

        if (atWorldEdge())
        {
            RainBurgerWorld world = (RainBurgerWorld)getWorld();
            
            world.burgerEscaped();
            world.removeObject(this);
        }        
    }    
}




