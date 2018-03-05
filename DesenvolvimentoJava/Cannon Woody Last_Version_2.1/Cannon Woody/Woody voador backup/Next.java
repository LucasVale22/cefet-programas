import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Write a description of class Next here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Next extends Level
{
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
