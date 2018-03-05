import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * This is an modified and extended version of the "ketchup shooter" scenario, used at CEFET/RJ to teach Greenfoot 
 * in Object-Oriented programming courses.
 * 
 * For the original scenario visit http://www.greenfoot.org/scenarios/3624.
 * 
 * @author Rafael Castaneda (rafaelcastaneda@gmail.com)
 * @version 2012-03-20
 * 
 */
public class RainBurgerWorld  extends World
{
    // Gives a 10% chance that a burguer may spawn in a given act
    private int burgerSpawnRatio = 10;    
    
    // Controles the number of acts in which burgers are allowed to spawn
    private int burgerSpawnCount = 0;
    private int burgerSpawnLimit = 5;
    
    // Gives a 1% chance that a ketchup bottle may spawn in a given act
    private int ketchupSpawnRatio = 10;    
    
    // Controles the number of acts in which ketchup bottles are allowed to spawn
    private int ketchupSpawnCount = 0;
    private int ketchupSpawnLimit = 15;
    
    // Gives a 0.5% chance that an apple may spawn in a given act
    private int appleSpawnRatio = 5;    
    
    // Controles the number of acts in which apples are allowed to spawn
    private int appleSpawnCount = 0;
    private int appleSpawnLimit = 10;
        
    // Controlling actors
    private Score scr;
    private Life  life;
    private MenuButton button;
    private GameOver gameOver;
    
    // Game state
    private enum GameState{MENU,PLAYING,GAMEOVER};    
    private GameState state;
    
    /**
     * Constructor for objects of class MyWorld.
     */
    public RainBurgerWorld()
    {    
        // Create a new world with 600x400 cells with a cell size of 1x1 pixels.
        super(600, 400, 1); 
                
        // Set the initial world state to MENU
        prepareMenu();                    
    }
    
    // ========================================================================== //
    // Preparation methods                                                        //
    // These methods are invoked to change the world from one state to another.   //
    // ========================================================================== //    
    private void prepareMenu()
    {
        // Clear the world
        removeObjects(getObjects(Actor.class));
                
        // Create the menu
        button = new MenuButton();        
        addObject(new MenuBackground(),getWidth()/2,getHeight()/2);
        addObject(button,getWidth()-60,getHeight()-60);
        
        // Set the game state
        state = GameState.MENU;
    }
    
    private void preparePlaying()
    {
        // Clear the world
        removeObjects(getObjects(Actor.class));
        
        // Add score, life, and cannon actors
        scr = new Score();
        addObject(scr,getWidth()/2,15);       
        life = new Life();
        addObject(life,getWidth()-50,15);
        Cannon cannon = new Cannon();
        addObject(cannon, 305, 190);
        
        // Set the game state
        state = GameState.PLAYING;
    }
    
    private void prepareGameOver()
    {
        // Clear the world
        removeObjects(getObjects(Actor.class)); 
      
        // Add gameover screen
        gameOver = new GameOver();
        addObject(gameOver,getWidth()/2,getHeight()/2);
        
        // Add the final score
        int fscore = scr.getScore();
        addObject(new FinalScore(fscore),getWidth()-75,60);
                                
        // Set the game state
        state = GameState.GAMEOVER;           
    }
    
    // ========================================================================== //
    // Game events                                                                //
    // These methods are invoked to proccess main game events.                    //
    // ========================================================================== //   
    public void burgerKilled()
    {
        scr.addScore(5);
    }
    
    public void ketchupKilled()
    {
        life.giveLife();
    }
    
     public void appleKilled()
    {
        life.takeLife();
        
        if (life.isDead())
        {
            prepareGameOver();
        }
    }
    
    public void burgerEscaped()
    {
        life.takeLife();
        
        if (life.isDead())
        {
            prepareGameOver();
        }
    }
    
    // ========================================================================== //
    // ACT                                                                        //
    // These methods are the composition of the world acting.                     //
    // ========================================================================== //
    public void act()
    {
        switch(state)
        {
            case MENU:
            {
                actMenu();
                break;
            }            
            case PLAYING:
            {                  
                actPlaying();   
                break;
            }            
            case GAMEOVER:
            {
                actGameOver();
                break;
            }
        }
    }
    
    public void actMenu()
    {
        if(Greenfoot.mouseClicked(button))
        {
            preparePlaying();
        }
    }
    
    public void actPlaying()
    {
        int random = Greenfoot.getRandomNumber(100);
        
        if (burgerSpawnCount == 0)
        {
            // Gives a burgerSpawnRatio% chance of spawning - increased by 2.5% at every 50 points
            if (random < burgerSpawnRatio + (scr.getScore()/50)*1.5)
            {
                Hamburguer burger = new Hamburguer();
                int y = 20;
                int x = Greenfoot.getRandomNumber(getWidth()-39)+20; // Prevents the burger from spawning at extreme widths
                addObject(burger,x,y);
            }               
        }
        
        // Prevents burgers from spawing every single act
        if (burgerSpawnCount++ == burgerSpawnLimit)
        {
            burgerSpawnCount=0;
        }   
        
        random = Greenfoot.getRandomNumber(100);
        
        if (ketchupSpawnCount == 0)
        {
            // Gives a ketchupSpawnRatio% chance of spawning
            if (random < ketchupSpawnRatio)
            {
                Ketchup ketchup = new Ketchup();
                int y = 20;
                int x = Greenfoot.getRandomNumber(getWidth()-39)+20; // Prevents the burger from spawning at extreme widths
                addObject(ketchup,x,y);
            }               
        }
        
        // Prevents bottles from spawing every single act
        if (ketchupSpawnCount++ == ketchupSpawnLimit)
        {
            ketchupSpawnCount=0;
        }  
        
        random = Greenfoot.getRandomNumber(100);
        
        if (appleSpawnCount == 0)
        {
            // Gives a burgerSpawnRatio% chance of spawning - increased by 2.5% at every 50 points
            if (random < appleSpawnRatio + (scr.getScore()/100))
            {
                Apple apple = new Apple();
                int y = 20;
                int x = Greenfoot.getRandomNumber(getWidth()-39)+20; // Prevents the burger from spawning at extreme widths
                addObject(apple,x,y);
            }               
        }
        
        // Prevents burgers from spawing every single act
        if (appleSpawnCount++ == appleSpawnLimit)
        {
            appleSpawnCount=0;
        }  
        
      
    }
    
    public void actGameOver()
    {
        if(Greenfoot.mouseClicked(gameOver))
        {
            prepareMenu();
        }
    }
}




