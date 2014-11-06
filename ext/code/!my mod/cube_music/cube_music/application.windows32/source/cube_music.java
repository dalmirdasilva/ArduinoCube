import processing.core.*; 
import processing.xml.*; 

import ddf.minim.analysis.*; 
import ddf.minim.*; 
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

public class cube_music extends PApplet {

//By Kevmatic
//This is a heavily modified version of this code by MattyHild:
//http://www.youtube.com/watch?v=ELtsEPXV2xE
//Designed for Processing. Uses minim.
//Hardware is Chr's design with stock firmware.
//http://www.instructables.com/id/Led-Cube-8x8x8/



//http://code.compartmental.net/tools/minim/

//http://www.processing.org/reference/libraries/serial/index.html
Serial port;
Minim minim;
AudioInput in;
FFT fftLog;
int[] bandAmp = new int[8];
byte[][] cube = new byte[8][8];

public void setup ()
{
  size(1024, 512, P3D);
  minim = new Minim(this);
  minim.debugOn();
  in = minim.getLineIn(Minim.STEREO, 1024);
  fftLog = new FFT(in.bufferSize(), in.sampleRate());
  fftLog.logAverages(48,1);
  rectMode(CORNERS);
  fftLog.window(FFT.HAMMING);
  println(Serial.list());
  port = new Serial(this, Serial.list()[0/*1*/], 38400,'N',8,1);  // first port in list
  PFont font = loadFont("CourierNewPS-BoldMT-48.vlw");
  textFont(font,24);
}

public void draw()
{
  background(0);
  fill(255);
  text(Serial.list()[0],1,20);
  fftLog.forward(in.mix);
  stroke(0);
  int w = PApplet.parseInt(width/8);
  for(int i = 0; i < 8; i++)
  {
    fill(i*32, 255 - 32*i,0);
    if(i > 1)
    {
      rect(i*w, height, i*w + w, height - (fftLog.getAvg(i)*i*i*10));
      bandAmp[i] =PApplet.parseInt(fftLog.getAvg(i)*(i*1.5f*10));
    }
    else
    {
      rect(i*w, height, i*w + w, height - fftLog.getAvg(i)*2*10);
      bandAmp[i] =PApplet.parseInt(fftLog.getAvg(i)*1.3f*10);
    }  
  }
  shiftback();
  clearX();
  for(int i = 0; i < 8; i++)
  {
    for(int y = 0; y < 8; y++)
    {
      if((bandAmp[i]/16) > y)
      setvoxel(i,0,y);
    }
  }  
  writecube();  
}

public void shiftback()
{
  for(int hght=0;hght<7;hght++)
  {
    for(int y=6; y>-1; y--)
    {      
      cube[hght][y+1]=cube[hght][y];
    }
  }
}

public void clearX()
{
  //clear X
  for(int x=0;x<8;x++)
  {
    cube[x][0]=(byte)0x00;
  }
}

public void setvoxel(int x, int y, int z)
{
  cube[z][y] |= (byte)(0x01 << x);
}

public void writecube()
{
  int x,y,i;
  i= 0;
  byte[] buffer = new byte[150];   
  buffer[i++] = (byte)0xff; // escape
  buffer[i++] = (byte)0x00; // reset to 0,0
  for (x=0;x<8;x++)
  {
    for (y=0;y<8;y++)
    {
      buffer[i++] = (cube[x][y]);
      // 0xFF is escape char and must be double transmitted. On plus side, sets up compatible additions to the protocol! 
      if (cube[x][y] == (byte)0xFF)
      {
        buffer[i++] = (cube[x][y]);
      }
    }
  }
  //You can't send the data a byte at a time in Windows or you'll only get about an fps. But iterators and buffers and stuff don't like working with primitives and I'm lazy
  //So I just create a new array the correct size each time, since you don't know how much data will be sent each time.
  //Since each 0xFF is sent twice, biggest buffer size is (64 * 2) + 2 = 130 bytes if you're sending a solid cube.
  byte[] buffer2 = new byte[i];
  for (int s = 0; s<i; s++) buffer2[s]=buffer[s];
  port.write(buffer2);
}
  static public void main(String args[]) {
    PApplet.main(new String[] { "--bgcolor=#F0F0F0", "cube_music" });
  }
}
