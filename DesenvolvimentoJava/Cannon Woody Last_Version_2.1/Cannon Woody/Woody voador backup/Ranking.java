import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)
import java.util.*;
import java.io.*;
/**
 * Write a description of class Ranking here.
 * 
 * @author (your name) 
 * @version (a version number or a date)
 */
public class Ranking extends World
{
    private int points;
    private int i=0;
    private String msg="Ranking.txt";
    private String places;
    private String scores;
    private String line;
    private boolean isTrue=true;
    private File arq;
    private List <Integer> point;
    public Ranking(int points)
    {    
        super(600, 400, 1);
        this.points=points;
        prepare();
    }
    public int checaPlace()
    {
        int count=0;
        for(Integer i: point)
        {
            if(points>i)
            {
                break;
            }
            count++;
        }
        return count;
    }
    public  void replaceRanking(int place)
    {
        int i=4;
        int aux;
        String linha;
        String all="";
        while(i>=0)
        {
            if(i==place)
            {
                point.remove(i);
                point.add(i,points);
                break;
            }
            aux=point.get(i-1);
            point.remove(i);
            point.add(i,aux);
            i--;
        }
        try{
            FileWriter writer = new FileWriter(arq,false);    
            BufferedWriter bw = new BufferedWriter(writer);    
            for(Integer a: point)
            {
                all=a.toString();
                all+="\r\n";
                bw.write(all);
            }
            BufferedReader leitor = new BufferedReader(new FileReader(arq));  
            linha = leitor.readLine();  
            leitor.close();  
            bw.newLine();    
            bw.flush();    
            bw.close();
        }catch(IOException e){
            e.printStackTrace();
        }
    }
    public void mountRanking()
    {
        int x=390;
        int y=135;
        for(Integer i: point)
        {
            addObject(new List_Rankings(i.toString()),x,y);
            y+=60;
        }
    }
    public void prepare()
    {
        String file="Ranking.txt";
        String score="";
        String name="";
        boolean isTrue=true;
        int aux=0;
        File dir = new File("..\\Woody voador backup");
        arq = new File(dir,file);  
        FileReader fileReader;
        BufferedReader ln;
        point=new ArrayList<Integer>();
         try {
            fileReader = new FileReader(arq);
            ln = new BufferedReader(fileReader);
            line=ln.readLine();
            while(line!=null)
                {
                while(i<line.length())
                {
                    char a=line.charAt(i);
                    score+=a;
                    i++;
                }
                point.add(new Integer(score));
                i=0;
                name="";
                score="";
                line=ln.readLine();
                aux++;
                }
                fileReader.close();
                ln.close();
        }
        catch (Exception e) {
            System.out.println(e);
        } 
        if(checaPlace()==5)
        {
            mountRanking();
        }
        else
        {
            replaceRanking(checaPlace());
            mountRanking();
        }
    }
    public void act()
    {
        if(Greenfoot.isKeyDown("enter"))
        {
            Greenfoot.setWorld(new Menu());
        }
    }
}
