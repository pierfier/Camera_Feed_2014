package com.team20.camera;

import java.net.HttpURLConnection;
import java.net.Url;
import javax.swing.JPanel;

//this class has the camera feed image and the crosshairs
public class Display extends JPanel{
        
        int width, height;

        //the url from the camera feed
        Url url;
 
        //image from the camera feed
        Image cameraFeed;

        //the crosshairs are just very thin rectangles
        CrossHair horizontalCrossHair, verticalCrossHair;
        

        //constructor
        public Display(int w, int h, URL url){
                this.width = w;
                this.height = h;
                this.url = url;
        }
        
        //the meat of the Display
        //uses an httpURlConnection, grabs the image       
        public void grabImage(){
  
        }
 
        public void paint(Graphics g){
                //draws the camera feed image
                g.drawImage(CameraFeed, 0 , 0, this);


                //draws the crosshairs
                horizontalCrossHair.draw(g);
                verticalCrossHair.draw(g);
        }

        //this is the method that is going to be called
        public void update(){
                grabImage();
                repaint();

        }
}
