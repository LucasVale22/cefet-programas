import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.io.*;

/**
 * Write a description of class Show_Points here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Show_Points extends Level
{
    private int points;
    public static int req;
    private String msg="Score: ";
    private String txt="Requiriments";
    private String ttxt=".txt";
    public Show_Points (int points)
    {
        this.points=points;
        checaPontuacao();
    }
    private void checaPontuacao()
    {
        String file=txt+Worlds.actualLevel+ttxt;
        File dir = new File("..\\Woody voador backup");
        File arq = new File(dir,file);   
        FileReader fileReader;
        BufferedReader ln;
         try {
            fileReader = new FileReader(arq);
            ln = new BufferedReader(fileReader);
            String line=ln.readLine();
            req=Integer.parseInt(line);
        }catch(Exception e){
            System.out.println(e);
        }
    }
}