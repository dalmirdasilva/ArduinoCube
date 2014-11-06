import processing.serial.*;

Serial myPort;  
Timer timer;

void setup()
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

void draw()
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
  void start ()  {
    savedTime = millis();  //  When the Timer starts it stores the current time in milliseconds
  }
  boolean isFinished ()  
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
