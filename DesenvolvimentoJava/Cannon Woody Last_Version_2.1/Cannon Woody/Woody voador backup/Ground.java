import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Ground here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Ground extends N_Hero
{
    /**
     * Act - do whatever the Ground wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    private Ground anterior;
    
    public void act() 
    {
        if (getX()<=-200)
        {
            setLocation(anterior.getX() + 200,getY());        
        }    
    }

    public void setAnterior(Ground anterior)
    {
            this.anterior = anterior;
    }

}

