import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class N_Hero here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public abstract class N_Hero extends Actor
{
    protected void worldEdgeRemove()
    {
        if(getX()<-25)
        {
            getWorld().removeObject(this);
        }
    }
    protected boolean inWorld()
    {
        if((getX()>=-50)&&(getX()<=650))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
