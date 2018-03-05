import greenfoot.*;
import java.awt.Color;
import java.awt.Font;
public class NewRanking extends Scores
{
    private int width=250;
    private int height=50;
    private float fontSize=20;
    private String msg="Digite seu nome: ";
    public String recept=null;
    private GreenfootImage img;
    private Font font1;
    private Font font2;
    public NewRanking ()
    {
        changeImg();
    }
    private void changeImg()
    {
        img= new GreenfootImage (width,height);
        font1=img.getFont();
        font2=font1.deriveFont(fontSize);
        img.setFont(font2);
        img.setColor(Color.BLACK);
        img.drawString(msg+recept,0,15);
        setImage(img);
    }
    public String returnStr(String name)
    {
        recept+=name;
        changeImg();
        return recept;
    }
}
