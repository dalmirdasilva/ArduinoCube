import processing.core.*; 
import processing.xml.*; 

import processing.serial.*; 

import java.applet.*; 
import java.awt.Dimension; 
import java.awt.Frame; 
import java.awt.event.MouseEvent; 
import java.awt.event.KeyEvent; 
import java.awt.event.FocusEvent; 
import java.awt.Image; 
import java.io.*; 
import java.net.*; 
import java.text.*; 
import java.util.*; 
import java.util.zip.*; 
import java.util.regex.*; 

public class start extends PApplet {



Serial myPort;  
Timer timer;

public void setup()
{
  println(Serial.list());
  myPort = new Serial(this, Serial.list()[0/*1*/], 38400,'N',8,1);  // first port in list
  myPort.stop();
  size(200,200);
  frame.setAlwaysOnTop(true);
  PFont font = loadFont("CourierNewPS-BoldMT-48.vlw");
  textFont(font,48);
  background(0);
  fill(255);
  text(Serial.list()[0], 45,110);
  open("cube.vbs");
  timer = new Timer(5000);
  timer.start();
}

public void draw()
{
  if (timer.isFinished())  
  {
    exit();
  }
}

class Timer
{
  int savedTime;  //  When Timer started
  int totalTime;    //  How long Timer should last  
  Timer (int tempTotalTime)
  {
    totalTime = tempTotalTime;
  }
  //  Starting the timer
  public void start ()  {
    savedTime = millis();  //  When the Timer starts it stores the current time in milliseconds
  }
  public boolean isFinished ()  
  {
    //  Check how much time has passed
    int passedTime = millis() - savedTime;
    if (passedTime > totalTime)  {
      return true;
    }  else  {
      return false;
    }
  }
}
  static public void main(String args[]) {
    PApplet.main(new String[] { "--bgcolor=#F0F0F0", "start" });
  }
}
