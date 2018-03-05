import greenfoot.*;
import java.awt.Color;
import java.awt.Font;
public class List_Rankings extends Scores
{
    private int width=250;
    private int height=50;
    private float fontSize=20;
    private String msg;
    private GreenfootImage img;
    private Font font1;
    private Font font2;
    public List_Rankings (String msg)
    {
        this.msg=msg;
        changeImg();
    }
    private void changeImg()
    {
        img= new GreenfootImage (width,height);
        font1=img.getFont();
        font2=font1.deriveFont(fontSize);
        img.setFont(font2);
        img.setColor(Color.WHITE);
        img.drawString(msg,0,15);
        setImage(img);
    }
}
