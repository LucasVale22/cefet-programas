import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

public class Blob  extends Mover
{
    public void act() 
    {
        move(10.0);
    
        if (atWorldEdge())
        {
            getWorld().removeObject(this);
        }
        else
        {
            Actor actor = getOneIntersectingObject(Mover.class);
            
            if(actor != null)
            {
                if(actor instanceof Hamburguer)
                {
                    RainBurgerWorld world = (RainBurgerWorld)getWorld();
                
                    world.burgerKilled();
                    world.addObject(new Splat(),actor.getX(),actor.getY());
                    world.removeObject(actor);
                    world.removeObject(this); 
                }
                
                if(actor instanceof Ketchup)
                {
                    RainBurgerWorld world = (RainBurgerWorld)getWorld();
                
                    world.ketchupKilled();
                    world.addObject(new Splat(),actor.getX(),actor.getY());
                    world.removeObject(actor);
                    world.removeObject(this);
                }
                
                if(actor instanceof Apple)
                {
                    RainBurgerWorld world = (RainBurgerWorld)getWorld();
                
                    world.appleKilled();
                    world.addObject(new Splat(),actor.getX(),actor.getY());
                    world.removeObject(actor);
                    world.removeObject(this);
                }
            }
        }        
    }    
}



