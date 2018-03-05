
import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.io.*;
import java.util.*;
/**
 * Write a description of class Cannon here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Cannon extends Worlds
{
    private boolean isPlayed=false;
    public Cannon()
    {    
        super(600, 400, 1, false); 
        prepare();
    }
    private void removeWorld()
    {
        obj=getObjects(N_Hero.class);
        removeObjects(obj);
        removeObject(canon.woody);
        removeObject(canon);
    }
    

    private void prepare()
    {
        try{
            mountLevel();
        }
        catch (Exception e)
        {
            System.out.println(e);
        }
        snd.setVolume(50);
        snd.playLoop();
    }

    private boolean checaGround(int y)
    {
        if(rodape.getY()>y+50)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    private boolean checaCloud(int x, int y)
    {
        List <Cloud> objs=getObjectsAt(x,y,Cloud.class);
        if(objs.isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    private void randomCloud()
    {
        if(Greenfoot.getRandomNumber(100)<1)
        {
            int x=Greenfoot.getRandomNumber(700)+650;
            int y=Greenfoot.getRandomNumber(800)-200;
            if(checaGround(y)&&checaCloud(x,y))
            {
                addObject(new Big_Cloud(),x,y);
            }
        }
        if(Greenfoot.getRandomNumber(100)<5)
        {
            int x=Greenfoot.getRandomNumber(700)+650;
            int y=Greenfoot.getRandomNumber(800)-200;
            if(checaGround(y)&&checaCloud(x,y))
            {
                addObject(new Little_Cloud(),x,y);
            }
        }
    }
    private void inicializeObjects()
    {
        lift = new Lifter();
        addObject(lift, 300, 15);
        booster = new Booster();
        addObject(booster, 300, 35);
        meter = new Meters ();
        addObject(meter,565,405);
        point =new Points ();
        addObject(point,135,405);
    }    
    private void inicializeClouds()
    {
        int i=Greenfoot.getRandomNumber(25);
        for (x=0;x<=i;x++)
        {
            if(x%2==0)
            {
                int x=Greenfoot.getRandomNumber(600);
                int y=Greenfoot.getRandomNumber(400);
                if(checaGround(y)&&checaCloud(x,y))
                {
                    addObject(new Big_Cloud(),x,y);
                }
            }
            else
            {
                int x=Greenfoot.getRandomNumber(600);
                int y=Greenfoot.getRandomNumber(400);
                if(checaGround(y)&&checaCloud(x,y))
                {
                    addObject(new Little_Cloud(),x,y);
                }
            }
        }
    }
    private void standardObjects()
    {
        canon = new Canon(lift,booster,meter,point,this);
        addObject(canon, 60, 328);  
        addObject(new Wheel(),67,336);
        Ground anterior = null;
        Ground primeiro = null;
        Ground ground = null;
        for(int i = -50; i < 650; i+= 50)
        {
            ground = new Ground();
            addObject(ground, i, 393);
            ground.setAnterior(anterior);
            anterior = ground;
            if(primeiro == null)
            {
                primeiro = ground;
            }
        }
        primeiro.setAnterior(ground);
        rodape=new Rodape();
        addObject(rodape, 390, 348);
        //addObject(new Trampoline(),1200,353);
        //addObject(new Tornado(),1200,200);
        //addObject(new Crow(),1200,200);
        //addObject(new Vulture(),1300,250);
        //addObject(new Plane(),1200,-100);
        //addObject(new Rainy_Cloud(),1200,-300);
        setPaintOrder(Wheel.class,Canon.class,Level.class,Meters.class,Points.class,Lifter.class,Booster.class,Enemy.class,Crow.class,Vulture.class,Trampoline.class,
        Hero.class,Rodape.class,Ground.class,Little_Cloud.class,Big_Cloud.class);
    }
    
    public void mountLevel() throws Exception
    {
        if(isPlayed)
        {
            removeWorld();
        }
        else
        {
            inicializeObjects();
        }
        List <Level> lvl=getObjects(Level.class);
        for (Level i: lvl)
        {
            removeObject (i);
        }
        snd.setVolume(50);
        snd.playLoop();
        isPlayed=true;
        standardObjects();
        grounds=getObjects(Ground.class);
        inicializeClouds();
        actualLevel++;
        String file=levelS+actualLevel+levelE;
        File dir = new File("..\\Woody voador backup");
        File arq = new File(dir,file);   
        FileReader fileReader;
        BufferedReader ln;
         try {
            fileReader = new FileReader(arq);
            ln = new BufferedReader(fileReader);
            line=ln.readLine();
            while(line!=null)
                {
                while(i<line.length())
                {
                    char a =line.charAt(i);
                    switch(a){
                        case '1':
                                addObject(new Crow(),x+((int)(Math.random()*800+605)),y-((int)(Math.random()*900+70)));
                        break;
                        case '2':
                            int p = (int)(Math.random()*400+350); 
                            addObject(new Windmill_A(),x+p,y-165);
                            addObject(new Windmill_B(),x+p,y-75);
                        break;
                        case '3':
                            addObject(new Vulture(),x+((int)(Math.random()*800+605)),y-((int)(Math.random()*900+70)));
                        break;
                        case '4':
                            addObject(new Trampoline(),x+((int)(Math.random()*400+350)),y);
                        break;
                        case '5':
                            addObject(new Rainy_Cloud(),x+((int)(Math.random()*800+500)),y-((int)(Math.random()*700+70)));
                        break;
                    }
                    i++;
                    x+=50;
                }
                x=0;
                y+=50;
                i=0;
                line=ln.readLine();
            }
            y=0;
        }
        catch (Exception e) {
            System.out.println(e);
        } 
    }
    public void act()
    {
        randomCloud();
    }
}