import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.io.*;
import java.util.*;
import java.lang.Class;
/**
 * Write a description of class Cannon here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Arcade extends Worlds
{
    public Arcade()
    {    
        super(600, 400, 1, false); 
        prepare();
        snd.setVolume(50);
        snd.playLoop();
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
    }

    private boolean checaGround(int y)
    {
        Ground ground=grounds.get(0);
        if(ground.getY()>y+50)
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
    private boolean checaEnemies(int x, int y)
    {
        objs=getObjects(Movers.class);
        for (Movers i: objs)
        {
            if(i.getX()==x&&i.getY()==y)
            {
                return false;
            }
        }
        return true;
    }
    private void randomWindMill()
    {
        y=groundY()-100;
        if(Greenfoot.getRandomNumber(1000)<1)
        {
            int x=Greenfoot.getRandomNumber(600)+650;
            if(checaEnemies(x,y))
            {
                createMill(x,y);
            }
        }
    }
    private void randomCrow()
    {
        if(Greenfoot.getRandomNumber(1000)<4)
        {
            int x=Greenfoot.getRandomNumber(600)+650;
            int y=200-Greenfoot.getRandomNumber(1200)+groundY()-393;
            if(checaEnemies(x,y)&&checaGround(y))
            {
                createCrow(x,y);
            }
        }
    }
    private void randomVulture()
    {
        if(Greenfoot.getRandomNumber(1000)<4)
        {
            int x=Greenfoot.getRandomNumber(600)+650;
            int y=300-Greenfoot.getRandomNumber(1000)+groundY()-393;
            if(checaEnemies(x,y)&&checaGround(y))
            {
                createVulture(x,y);
            }
        }
    }
    private void randomTornado()
    {
        if(Greenfoot.getRandomNumber(1000)<2)
        {
            int x=Greenfoot.getRandomNumber(600)+650;
            int y=300-Greenfoot.getRandomNumber(1500)+groundY()-393;
            if(checaEnemies(x,y)&&checaGround(y))
            {
                createTornado(x,y);
            }
        }
    }
    private void randomRainyCloud()
    {
        if(Greenfoot.getRandomNumber(1000)<1)
        {
            int x=Greenfoot.getRandomNumber(600)+650;
            int y=300-Greenfoot.getRandomNumber(1000)+groundY()-393;
            if(checaCloud(x,y)&&checaGround(y))
            {
                createRainyCloud(x,y);
            }
        }
    }
    private void randomPlane()
    {
        if(Greenfoot.getRandomNumber(1000)<2)
        {
            int x=Greenfoot.getRandomNumber(600)+650;
            int y=-300-Greenfoot.getRandomNumber(1700)+groundY()-393;
            if(checaEnemies(x,y)&&checaGround(y))
            {
                createPlane(x,y);
            }
        }
    }
    private int groundY()
    {
        Ground ground=grounds.get(0);
        return ground.getY();
    }
    private void randomTrampoline()
    {
        y=groundY()-40;
        if(Greenfoot.getRandomNumber(1000)<1)
        {
            int x=Greenfoot.getRandomNumber(600)+650;
            if(checaEnemies(x,y))
            {
                createTrampoline(x,y);
            }
        }
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
    private void createMill(int x,int y)
    {
        addObject(new Windmill_A(),x,y-100);
        addObject(new Windmill_B(),x,y);
    }
    private void createCrow(int x,int y)
    {
        addObject(new Crow(),x,y);
    }
    private void createVulture(int x,int y)
    {
        addObject(new Vulture(),x,y);
    }
    private void createTornado(int x,int y)
    {
        addObject(new Tornado(),x,y);
    }
    private void createRainyCloud(int x,int y)
    {
        addObject(new Rainy_Cloud(),x,y);
    }
    private void createTrampoline(int x,int y)
    {
        addObject(new Trampoline(),x,y);
    }
    private void createPlane(int x,int y)
    {
        addObject(new Plane(),x,y);
    }
    private void standardObjects()
    {
        canon = new Canon(lift,booster,meter,point,this);
        addObject(canon, 60, 328);  
        addObject(new Wheel(),67,336);
        Ground anterior = null;
        Ground primeiro = null;
        Ground ground = null;
        for(int i = -200; i < 800; i+= 200)
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
        setPaintOrder(Wheel.class,Canon.class,Meters.class,Points.class,Lifter.class,Booster.class,Enemy.class,Trampoline.class,
        Hero.class,Movers.class,Rodape.class,Ground.class,Little_Cloud.class,Big_Cloud.class);
    }    
    public void mountLevel()
    {
        if(actualLevel==0)
        {
            inicializeObjects();
            standardObjects();
            grounds=getObjects(Ground.class);
            inicializeClouds();
            actualLevel++;
        }
    }
    public void act()
    {
        randomCloud();
        randomTrampoline();
        randomRainyCloud();
        randomWindMill();
        randomPlane();
        randomCrow();
        randomTornado();
        randomVulture();
    }
}