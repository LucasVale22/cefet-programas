import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Restart here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Restart extends Level
{
    /**
     * Act - do whatever the Restart wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    private MouseInfo mInfo;
    /**
     * Act - do whatever the Next wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void act()
    {
        mInfo=Greenfoot.getMouseInfo();
        if(mInfo!=null)
        {
            if((mInfo.getActor()==this)&&(mInfo.getButton()==1))
            {
                try{
                    Worlds.actualLevel--;
                    Woody.world.mountLevel();
                }catch(Exception e)
                {
                    System.out.println(e);
                }
                Woody.resetAll();
            }
        }
    }
}
