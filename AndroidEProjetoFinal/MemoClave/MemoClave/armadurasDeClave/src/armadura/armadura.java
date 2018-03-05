package armadura;

import processing.core.PImage;
import processing.core.PApplet;
import arb.soundcipher.*;


public class armadura extends PApplet {
	PImage clave;
	int i,j;
	
	
	int value = 0;


	public void mouseMoved() {
	  value = value + 5;
	  if (value > 255) {
	    value = 0;
	  }
	}
	
	
	
	
	
	
	public void setup() {
		clave = loadImage("sol.gif");
		size(600, 600);
		background(255);
		rect(25, 25, 50, 50);
		copy(clave, 0, 0, 178, 497, 0, 82, 150, 350);
		for(i=1;i<=5;i++) {
			line(0, 200+(i*30),600, 200+(i*30));
		}
	}
	
	public void draw() {
		
		 	
		 
		
		  if (mousePressed && (mouseButton == LEFT)) {
			  rect(mouseX-10, mouseY-10, 55, 55);
		  } else if (mousePressed && (mouseButton == RIGHT)) {
			  rect(mouseX-10, mouseY-10, 55, 55);
			  fill(value);
		  } else {
		 //   fill(126);
		  }
		  
		}


}



