#include "CUBE_IMG.h"


#define A0_data 0
#define A1_data 1
#define A2_data 2
#define A3_data 3
#define A4_data 4
#define A5_data 5
#define A6_data 6
#define A7_data 7

#define A0_clock 8
#define A1_clock 9
#define A2_clock 10
#define A3_clock 11
#define A4_clock 12
#define A5_clock 13
#define A6_clock 14
#define A7_clock 15

#define OFFSET 8

#define C0_data 16
#define C0_clock 17

const int x_max = 8;
const int y_max = 8;
const int z_max = 8;

boolean pixels[x_max][y_max][z_max];


void setup(){
  pinMode(A0_clock,OUTPUT);
  pinMode(A0_data,OUTPUT); 
  pinMode(A1_clock,OUTPUT);
  pinMode(A1_data,OUTPUT); 
  pinMode(A2_clock,OUTPUT);
  pinMode(A2_data,OUTPUT); 
  pinMode(A3_clock,OUTPUT);
  pinMode(A3_data,OUTPUT); 
  pinMode(A4_clock,OUTPUT);
  pinMode(A4_data,OUTPUT); 
  pinMode(A5_clock,OUTPUT);
  pinMode(A5_data,OUTPUT); 
  pinMode(A6_clock,OUTPUT);
  pinMode(A6_data,OUTPUT); 
  pinMode(A7_clock,OUTPUT);
  pinMode(A7_data,OUTPUT); 
  pinMode(C0_clock,OUTPUT);
  pinMode(C0_data,OUTPUT);
}

void loop(){
   clearPixels();
   for (int i2 = 0; i2 < 500; i2++){
       writePixels();
   }
  growCubeRachel();
  growCubeRachel();
  growCubeRachel();
  playCube(140);
  playHinges(240); // plays through once
  playHinges(160); // leads into ceiling for layers going down
  playLayer(220); // good - does each layer once
  playSine(280); //280 has good landing for rain
  playRain(50);
  growAndRotateSphere(3,3,4);
  randMoveSphere( 3,3,4, 13);
  playDancingMan();
  playSolidWave();
  playSolidWave();
  playSolidWave();
  playSolidWave();
  scrollMiamiM();
  scrollMiamiM();

}



void animate(int dur){
  playFull(dur);
  playX(dur);
  playCube(dur);
  playSlash1(dur);
  playSlash2(dur);
  playLayer(dur);
  playSine(dur);
  playRain(300);

}


void animateCube2(int width, int duration){
  for (int i = 0; i< duration; i++){
    for (int i2 = 0; i2 < 10; i2++){
      drawCube2(i%8+1);
      writePixels();
    }
  }
}
void drawCube2(int width){
  clearPixels();
  for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        for (int y = 0; y < y_max; y++){
            if( abs((x_max/2)-x) < width && abs((y_max/2)-y) < width && abs((z_max/2)-z) < width){
               pixels[x][y][z] = true;
            }
        }
      }
  }
}

void playSine(int dur){
  for ( int i = 0; i < dur/3; i++){
    for ( int i2 = 0; i2 < 3; i2++ ){
      drawSine(i);
      writePixels();
    }
  }
}
void playLayer(int dur){
  for ( int i = 0; i < dur/25; i++){
    for ( int i2 = 0; i2 < 25; i2++ ){
        drawLayer(7-i%z_max);
        writePixels();
    }
  }
}
void playSlash1(int dur){
  for ( int i2 = 0; i2 < dur/25; i2++){
    for ( int i = 0; i < 25; i++ ){
        drawSlash1(i2%2);
        writePixels();
    }
  }
}
void playSlash2(int dur){
  for ( int i2 = 0; i2 < dur/25; i2++){
    for ( int i = 0; i < 25; i++ ){
        drawSlash2(i2%2);
        writePixels();
    }
  }
}
void playFull(int dur){
  fillPixels();
  for ( int i = 0; i < dur; i++ ){
    writePixels();
  }
}
void playX(int dur){
  drawX();
  for ( int i = 0; i < dur; i++ ){
    writePixels();
  }
}

void playCube(int dur){
  drawCube();
  for ( int i = 0; i < dur; i++){
    writePixels();
  }

}

void writePixels(){
  for (int z = 0; z < z_max; z++){
    groundLayer(-1);  // none are grounded
    for (int x = 0; x < x_max; x++){
      for (int y = 0; y < y_max; y++){
        digitalWrite(x+OFFSET,LOW);
        digitalWrite(x,pixels[x][y][z]);
        digitalWrite(x+OFFSET,HIGH);
        digitalWrite(x+OFFSET,LOW);
      }
    }
    groundLayer(z);
    delay(1);
  }
  groundLayer(-1);  // none are grounded
}

void fillPixels(){
 for (int z = 0; z < z_max; z++){
    for (int x = 0; x < x_max; x++){
      for (int y = 0; y < y_max; y++){
        pixels[x][y][z] = true;
      }
    }
  }
}
void clearPixels(){
 for (int z = 0; z < z_max; z++){
    for (int x = 0; x < x_max; x++){
      for (int y = 0; y < y_max; y++){
        pixels[x][y][z] = false;
      }
    }
  }
}

// this should be the only thing used to ground lights/turn on layers
int groundLayer(int layer){
  if (layer >= z_max || layer < -1)
    return -1;
  switch ( layer ) {
    case -1: shiftOut(C0_data, C0_clock, LSBFIRST, B00000000); break;
    case 0: shiftOut(C0_data, C0_clock, LSBFIRST, B10000000); break;
    case 1: shiftOut(C0_data, C0_clock, LSBFIRST, B01000000); break;
    case 2: shiftOut(C0_data, C0_clock, LSBFIRST, B00100000); break;
    case 3: shiftOut(C0_data, C0_clock, LSBFIRST, B00010000); break;
    case 4: shiftOut(C0_data, C0_clock, LSBFIRST, B00001000); break;
    case 5: shiftOut(C0_data, C0_clock, LSBFIRST, B00000100); break;
    case 6: shiftOut(C0_data, C0_clock, LSBFIRST, B00000010); break;
    case 7: shiftOut(C0_data, C0_clock, LSBFIRST, B00000001); break;
  }
  return 1;
}

void drawCube(){
  clearPixels();
  for (int z = 0; z < z_max; z++){
    for (int x = 0; x < x_max; x++){
      for (int y = 0; y < y_max; y++){
        if  ( ( ( x == 0 || x == x_max-1 ) &&
            ( ( y == 0 || y == y_max-1) || (z == 0 || z == z_max-1)  ) ) || 
            ( ( y == 0 || y == y_max-1 ) &&
            ( ( x == 0 || x == x_max-1) || (z == 0 || z == z_max-1) ) ) ) {
           pixels[x][y][z] = true;     
         } else {
           pixels[x][y][z] = false;
         }
      }
    }
  }
}

int drawX(){
  clearPixels();
  for (int z = 0; z < z_max; z++){
    for (int x = 0; x < x_max; x++){
      for (int y = 0; y < y_max; y++){
        if ( x == z || x_max-(x+1) == z ){
          pixels[x][y][z] = true;
        } else {
          pixels[x][y][z] = false;
        }
      }
    }
  } 
}

int drawSlash1(bool pos){
  clearPixels();
  for (int z = 0; z < z_max; z++){
    for (int x = 0; x < x_max; x++){
      for (int y = 0; y < y_max; y++){
        if ( x == z && pos == true){
          pixels[x][y][z] = true;
        } else if (x_max-(x+1) == z && pos == false){
          pixels[x][y][z] = true;
        } else {
          pixels[x][y][z] = false;
        }
      }
    }
  } 
}
int drawSlash2(bool pos){
  clearPixels();
  for (int z = 0; z < z_max; z++){
    for (int x = 0; x < x_max; x++){
      for (int y = 0; y < y_max; y++){
        if ( x == y && pos == true){
          pixels[x][y][z] = true;
        } else if (x_max-(x+1) == y && pos == false){
          pixels[x][y][z] = true;
        } else {
          pixels[x][y][z] = false;
        }
      }
    }
  } 
}

int drawLayer(int layer){
  clearPixels();
  if ( layer >= z_max || layer < 0 ){
    return -1;
  }
  for (int x = 0; x < x_max; x++){
    for (int y = 0; y < y_max; y++){
      pixels[x][y][layer] = true;
    }
  }
  return 0;
}

//taken from http://www.hownottoengineer.com/projects/lc.html
int drawSine(int phase){
  clearPixels();
  for(int x = 0; x < x_max; x++){
       for(int y = 0; y < y_max; y++){
            double Z = sin(phase + sqrt(pow(cubeMap(x,0,x_max-1,-PI,PI),2) + pow(cubeMap(y,0,y_max-1,-PI,PI),2)));
            Z = round(cubeMap(Z,-1,1,0,z_max-1));
           pixels[x][y][(int)Z] = 1;
        }
    }
   return 1;
}

// taken from http://www.hownottoengineer.com/projects/lc.html
double cubeMap(double in, double inMin, double inMax, double outMin, double outMax){
    double out;
    out = (in-inMin)/(inMax-inMin)*(outMax-outMin) + outMin;
    return out;
}

int animateSnake(int dur){
  int x, y, z;
  x = y = z = 0;
  int prevx, prevy, prevz;
  prevx = prevy = prevz = 0;
  int xdir = 1;
  int ydir = 1;
  int zdir = 1;
  for (int stage = 0; stage < dur; stage++){
    
    clearPixels();
    boolean checkX = false;
    boolean checkY = false;
    
    if (x+xdir+1 > x_max || x+xdir < 0){
      xdir = -1*xdir;
      checkX = true;
    } else {
      x += xdir;
    }
    
    if ((y+ydir+1 > y_max || y+ydir < 0) && checkX){
      ydir = -1*ydir;
      checkY = true;
    } else if (checkX){
      y += ydir;
    }
    
    if ((z+zdir+1 > z_max || z+zdir < 0) && checkX && checkY){
      zdir = -1*zdir;
    } else if (checkX && checkY){
      z += zdir;
    }
    
    pixels[prevx][prevy][prevz] = true;
    pixels[x][y][z] = true;
    for (int i = 0; i < 2; i++){
      writePixels();
    }
    prevx = x;
    prevy = y;
    prevz = z;
  }

}


//RANDOM RAIN EFFECT
void drawRain(){
  for (int x = 0; x < x_max; x++){
    for (int y = 0; y < y_max; y++){
      for (int z = 0; z < z_max; z++){
        if ( z != z_max-1){
          pixels[x][y][z] = pixels[x][y][z+1];
        } 
        else {
          int chance = rand()%25;
          if (chance == 0){
            pixels[x][y][z] = true;
          } 
          else {
            pixels[x][y][z] = false;
          }
        }
      }
    }
  }
}

void playRain(int dur){
 for (int i = 0; i < dur; i++){
   drawRain();
   for (int i2 = 0; i2 < 12; i2++){
    writePixels();
   }
 }
}

void playSphere(int dur){
  for (int i = 0; i < dur; i++){
   //sphere(4,4,4);
   sphere2(2);  
   for (int i2 = 0; i2 < 12; i2++){
    writePixels();
   }
 }
}
void sphere(int x_, int y_, int z_){
    clearPixels();
    double R = 2;
    int X = 0;
    int Y = 0;
    int Z = 0;

    for(int x = 0; x < x_max; x++){
        for(int y = 0; y < y_max; y++){
            for(int z = 0; z < z_max; z++){
                X = cubeMap(x,0,x_max-1,-4,4);
                Y = cubeMap(y,0,y_max-1,-4,4);
                Z = cubeMap(z,0,z_max-1,-4,4);

                if(X*X + Y*Y + Z*Z >= R*R-1 && X*X + Y*Y + Z*Z <= R*R+1){
                    if(x + x_ < x_max && y + y_ < y_max && z + z_ < z_max && x + x_ >= 0 && y + y_ >= 0 && z + z_ >= 0){
                        pixels[x + x_][y + y_][z + z_] = 1;
                    }
                }
            }
        }
    }

  writePixels();
}

void sphere2(int r){
  clearPixels();
  for(int x = 0; x < x_max; x++){
        for(int y = 0; y < y_max; y++){
            for(int z = 0; z < z_max; z++){
              Serial.print(x);Serial.print(",");
              Serial.print(y);Serial.print(",");
              Serial.print(z);Serial.print("     ");
              Serial.println(sqrt( (x_max/2 - x)^2 + (y_max/2 - y)^2 + (z_max/2 - z)^2 ));
              if ( sqrt( (x_max/2 - x)^2 + (y_max/2 - y)^2 + (z_max/2 - z)^2 ) < r){
                pixels[x][y][z] = true;
              }
            }
        }
  }
}
// RACHEL'S NEW STUFF STARTS HERE
void growCubeRachel(){
  int dur = 16;
   for (int i = 0; i<4; i++){
   drawCubeRachel(4+i,4-i-1);
     for (int i2 = 0; i2 < dur; i2++){
       writePixels();
     } 
   }
   for(int i=2; i>=0; i--){
     drawCubeRachel(4+i,4-i-1);
     for (int i2 = 0; i2 < dur; i2++){
       writePixels();
     } 
   }
   clearPixels();
   for (int i2 = 0; i2 < dur; i2++){
       writePixels();
   }
}


void drawCubeRachel(int sizeMax, int sizeMin){
  clearPixels();
  for(int x = 0; x < x_max; x++){
        for(int y = 0; y < y_max; y++){
            for(int z = 0; z < z_max; z++){
              if(x<=sizeMax && x>=sizeMin && y<=sizeMax && y>=sizeMin && z<=sizeMax && z>=sizeMin){
                pixels[x][y][z] = true;                  
              }
            }
        }
  }
}

void randMoveSphere(int x0, int y0, int z0, int times){
  int x=x0;
  int y=y0;
  int z=z0;
  int dur = 8;
  for (int i=0; i<times; i++){
  for (int i = 1; i<5; i++){
   drawSphereRachel(x, y, z, i);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   } 
   x = x + rand()%3 -1;
   y = y + rand()%3 -1;
   z = z + rand()%3 -1;
   if (x<0){
     x=0;
   }
   if (x>=x_max){
     x=x_max-1;
   }
   if (y<0){
     y=0;
   }
   if (y>=y_max){
     y=y_max-1;
   }
   if (z<0){
     z=0;
   }
   if (x>=x_max){
     z=z_max-1;
   }
 }
 for (int i = 3; i>=1; i--){
   drawSphereRachel(x, y, z, i);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   }
   x = x + rand()%3 -1;
   y = y + rand()%3 -1;
   z = z + rand()%3 -1;
   if (x<0){
     x=0;
   }
   if (x>=x_max){
     x=x_max-1;
   }
   if (y<0){
     y=0;
   }
   if (y>=y_max){
     y=y_max-1;
   }
   if (z<0){
     z=0;
   }
   if (z>=z_max){
     z=z_max-1;
   } 
 }
 clearPixels();
   for (int i2 = 0; i2 < dur; i2++){
       writePixels();
   }
  }
}

void growAndRotateSphere(int x0, int y0, int z0){
   int dur = 8;
   drawSphereRachel(x0, y0-1, z0, 1);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   }
  drawSphereRachel(x0-1, y0, z0, 2);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   } 
  drawSphereRachel(x0-1, y0+1, z0, 3);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   } 
  drawSphereRachel(x0, y0+2, z0, 4);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   } 
   drawSphereRachel(x0+1, y0+2, z0, 3);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   }
  drawSphereRachel(x0+2, y0+1, z0, 2);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   } 
  drawSphereRachel(x0+2, y0, z0, 1);
   for (int i2 = 0; i2 < dur; i2++){
     writePixels();
   }
 clearPixels();
   for (int i2 = 0; i2 < dur; i2++){
       writePixels();
   }
}

void growSphereRachel(int x0, int y0, int z0){
 for (int i = 1; i<5; i++){
   drawSphereRachel(x0, y0, z0, i);
   for (int i2 = 0; i2 < 15; i2++){
     writePixels();
   } 
 }
 for (int i = 3; i>=1; i--){
   drawSphereRachel(x0, y0, z0, i);
   for (int i2 = 0; i2 < 15; i2++){
     writePixels();
   } 
 }
 clearPixels();
   for (int i2 = 0; i2 < 15; i2++){
       writePixels();
   }
}

// draws sphere with radius centered at x0 y0 z0 sort of (x0 = 3, y0=3 centers at middle of cube
// radius must be [1,4]
void drawSphereRachel(int x0, int y0, int z0, int radius){
  clearPixels();
  if (radius == 1){
    drawOnLayer(IMG_SPHEREa, x0, y0, IMG_SPHEREa_WIDTH, IMG_SPHEREa_HEIGHT, z0);
  }
  if(radius==2){
    radius=radius-1;
    drawOnLayer(IMG_SPHEREa, x0, y0, IMG_SPHEREa_WIDTH, IMG_SPHEREa_HEIGHT, z0+radius);
    drawOnLayer(IMG_SPHEREb, x0-radius, y0-radius, IMG_SPHEREb_WIDTH, IMG_SPHEREb_HEIGHT, z0);
    drawOnLayer(IMG_SPHEREa, x0, y0, IMG_SPHEREa_WIDTH, IMG_SPHEREa_HEIGHT, z0-radius);
  }
  else if(radius==3){
    radius=radius-1;
    drawOnLayer(IMG_SPHEREa, x0, y0, IMG_SPHEREa_WIDTH, IMG_SPHEREa_HEIGHT, z0+radius);
    drawOnLayer(IMG_SPHEREb, x0-radius+1, y0-radius+1, IMG_SPHEREb_WIDTH, IMG_SPHEREb_HEIGHT, z0+radius-1);
    drawOnLayer(IMG_SPHEREc, x0-radius, y0-radius, IMG_SPHEREc_WIDTH, IMG_SPHEREc_HEIGHT, z0);
    drawOnLayer(IMG_SPHEREb, x0-radius+1, y0-radius+1, IMG_SPHEREb_WIDTH, IMG_SPHEREb_HEIGHT, z0-radius+1);
    drawOnLayer(IMG_SPHEREa, x0, y0, IMG_SPHEREa_WIDTH, IMG_SPHEREa_HEIGHT, z0-radius);
  }
  else if(radius==4){
    radius=radius-1;
    drawOnLayer(IMG_SPHEREa, x0, y0, IMG_SPHEREa_WIDTH, IMG_SPHEREa_HEIGHT, z0+radius);
    drawOnLayer(IMG_SPHEREb, x0-radius+2, y0-radius+2, IMG_SPHEREb_WIDTH, IMG_SPHEREb_HEIGHT, z0+radius-1);
    drawOnLayer(IMG_SPHEREc, x0-radius+1, y0-radius+1, IMG_SPHEREc_WIDTH, IMG_SPHEREc_HEIGHT, z0+radius-2);
    drawOnLayer(IMG_SPHEREd, x0-radius, y0-radius, IMG_SPHEREd_WIDTH, IMG_SPHEREd_HEIGHT, z0);    
    drawOnLayer(IMG_SPHEREc, x0-radius+1, y0-radius+1, IMG_SPHEREc_WIDTH, IMG_SPHEREc_HEIGHT, z0-radius+2);
    drawOnLayer(IMG_SPHEREb, x0-radius+2, y0-radius+2, IMG_SPHEREb_WIDTH, IMG_SPHEREb_HEIGHT, z0-radius+1);
    drawOnLayer(IMG_SPHEREa, x0, y0, IMG_SPHEREa_WIDTH, IMG_SPHEREa_HEIGHT, z0-radius);

  }
  
}

// draws any bool array on any given layer starting at x0, y0 on the layer DOES NOT CLEAR PIXELS
void drawOnLayer(bool img[], int x0, int y0, int img_height, int img_width, int layer){
  if(layer<z_max && layer>-1){
    for (int x=x0; (x<x_max) && (x<img_width+x0); x++){
      for (int y=y0; y<y_max && (y<img_height+y0); y++){
        if(x>=0 && y>=0){
          pixels[x][y][layer]=img[(y-y0)*img_width+(x-x0)];
        }
      }
    } 
  }
}


// scrolls miami M around the whole cube one time
void scrollMiamiM(){ //duration = 20 is best
  int dur=20;
  clearPixels();
  int x,y;
  for (int i=0; i<4; i++) {
    for (int j=0; j<7; j++){
      if(i==0){ //START AT FRONT WALL
        x=0;
        y=j;
      }
      if(i==1){ 
        y=7;
        x=j;
      }
      if(i==2){
        x=7;
        y=7-j;
      }
      if(i==3){
        y=0;
        x=7-j;
      }      
      for (int i = 0; i < dur; i++){
        clearPixels();
        drawOnOuterRing(IMG_MIAMI_M, IMG_MIAMI_M_HEIGHT, IMG_MIAMI_M_WIDTH, x, y, 7);
       // for (int i2 = 0; i2 < 10; i2++){
          writePixels();
        //}
      }
    }
  }
}
// assumes image does not have height greater than 8
void drawOnOuterRing(bool img[], int img_height, int img_width, int x0, int y0, int z0){
  int stoppedOn = drawOnOutsideWall(img, img_height, img_width, x0, y0, z0, 0); 
  int x=x0;
  int y=y0;
  int z=z0;
  int stoppedOn2, stoppedOn3;

  if (stoppedOn <= img_width) {
    if((x==0)&&!(y==0)) {//starting on left wall
      x = 1;
      y = 0;
    }  
    else if((x==7)&&!(y==7)) {//starting on right wall
      x = 6;
      y = 7;
    }
    else if((y==7)&&!(x==0)) {//starting on back wall
      x = 0;
      y = 6;
    }
    else if((y==0)&&!(x==7)) {//starting on front wall
      x = 7;
      y = 1;
    } 
    stoppedOn2 = drawOnOutsideWall(img, img_height, img_width, x, y, z, stoppedOn); 
  }
  if (stoppedOn2 <= img_width) {
    if((x==0)&&!(y==0)) {//starting on left wall
      x = 1;
      y = 0;
    }  
    else if((x==7)&&!(y==7)) {//starting on right wall
      x = 6;
      y = 7;
    }
    else if((y==7)&&!(x==0)) {//starting on back wall
      x = 0;
      y = 6;
    }
    else if((y==0)&&!(x==7)) {//starting on front wall
      x = 7;
      y = 1;
    } 
    stoppedOn3 = drawOnOutsideWall(img, img_height, img_width, x, y, z, stoppedOn2); 
  }
  if (stoppedOn3 <= img_width) {
    if((x==0)&&!(y==0)) {//starting on left wall
      x = 1;
      y = 0;
    }  
    else if((x==7)&&!(y==7)) {//starting on right wall
      x = 6;
      y = 7;
    }
    else if((y==7)&&!(x==0)) {//starting on back wall
      x = 0;
      y = 6;
    }
    else if((y==0)&&!(x==7)) {//starting on front wall
      x = 7;
      y = 1;
    } 
    drawOnOutsideWall(img, img_height, img_width, x, y, z, stoppedOn3); 
  }  
}

// give x0, y0,z0 of top corner of image and it will draw it on the wall to the left of that point
// only works for outside edges right now
// does not verify that you are within the cube in your initial x,y and z...
// DOES NOT CLEAR PIXELS INTENTIONALLY, IF IT DID, drawOnOuterRing WONT WORK
// returns the x we had to stop on in the image file
// HEIGHT OF IMAGE FILE MUST BE 8 FOR z0 TO WORK RIGHT (ALL 0s ON TOP ROWS IN IMG)
int drawOnOutsideWall(bool img[], int img_height, int img_width, int x0, int y0, int z0, int img_0){
  //clearPixels();
  if(x0==0 && !(y0==0)){ // drawing on the left wall
    int y;
    for (y=y0; ((y >= 0) && (y > (y0-img_width+img_0))); y--){ 
      for (int z=z0; ((z >= 0) && (z > (z0-img_height))); z--){
        pixels[0][y][z]=img[(z_max-1-z)*img_width+(y0-y+img_0)];
      }
    }
    return (y0-y)+img_0;
  }
  else if (x0==7 && !(y0==7)) { // drawing on the right wall
    int y;
    for (y=y0; ((y < y_max) && (y < img_width-img_0+y0)); y++){
      for (int z=z0; ((z >= 0) && (z > (z0-img_height))); z--){
        pixels[7][y][z]=img[(z_max-1-z)*img_width+(y-y0+img_0)];
      }
    }    
    return(y-y0)+img_0;
  }
  else if (y0==0 && !(x0==7)) { // drawing on the front wall
    int x;
    for ( x=x0; ((x < x_max) && (x < img_width-img_0+x0)); x++){
      for (int z=z0; ((z >= 0) && (z > (z0-img_height))); z--){
        pixels[x][0][z]=img[(z_max-1-z)*img_width+(x-x0+img_0)];
      }
    }    
    return(x-x0)+img_0;
  }  
  else if (y0==7 && !(x0==0)) { // drawing on the back wall
    int x;
    for (x=x0; ((x >= 0) && (x > x0-img_width+img_0)); x--){
      for (int z=z0; ((z >= 0) && (z > (z0-img_height))); z--){
        pixels[x][7][z]=img[(z_max-1-z)*img_width+(x0-x+img_0)];
      }
    }    
    return(x0-x)+img_0;
  }   
  
}

void playSolidWave(){
  int heights [] = {2,2,3,5,6,7,7,6, 5,3,2,2,4,5,6,6, 5,3,1,0,1,3,5,7, 7,6,4,3,3,2,1,0, 0,1,3,4,4,3,2,2, 3,5,6,7,7};
  for (int i=0; i<38; i++){
    clearPixels();
    drawWallS(0,heights[i]);
    drawWallS(1,heights[i+1]);    
    drawWallS(2,heights[i+2]);
    drawWallS(3,heights[i+3]);
    drawWallS(4,heights[i+4]);
    drawWallS(5,heights[i+5]);
    drawWallS(6,heights[i+6]);
    drawWallS(7,heights[i+7]);
    int howFast = rand()%5+3;
    for (int i2=0; i2<howFast; i2++){
      writePixels(); 
    }
  }

}

// draws any front facing wall solid to the height zIn
// DOES NOT CLEAR PIXELS
void drawWallF(int yIn, int zIn){
    for ( int x=0; (x < x_max); x++){
        for (int z=0; z<=zIn; z++){
          pixels[x][yIn][z]=true;
        }
    }
}

// draws any side facing wall solid to the height zIn
// DOES NOT CLEAR PIXELS
void drawWallS(int xIn, int zIn){
    for ( int y=0; (y < y_max); y++){
        //for (int z=0; z<=zIn; z++){
          pixels[xIn][y][zIn]=true;
        //}
    }
}

void scrollUsToday(){
  int x,y;
  int dur=20;
  for (int i=0; i<4; i++) {
    for (int j=0; j<7; j++){
      if(i==0){ //START AT FRONT WALL
        x=0;
        y=j;
      }
      if(i==1){ 
        y=7;
        x=j;
      }
      if(i==2){
        x=7;
        y=7-j;
      }
      if(i==3){
        y=0;
        x=7-j;
      }      
      for (int i = 0; i < dur; i++){
        clearPixels();
        drawOnOuterRing(IMG_US_TODAY, IMG_US_TODAY_HEIGHT, IMG_US_TODAY_WIDTH, x, y, 7);
        writePixels();
      }
    }
  }
}
// RACHEL'S NEW STUFF ENDS HERE
void playHinges(int dur){ // loops to starting pos at dur = 240
  for (int i=0; i<dur/20; i++){
    drawHinges(i%12);
    for (int i2=0; i2 < 18; i2++){ //20
      writePixels();
    }
  }
  
}

void drawHinges(int stage){
  if(stage==0){ //front wall
      clearPixels();
      for (int z = 0; z < z_max; z++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][0][z] = true;
        }
      }
  }
  else if(stage==1){ // front to floor slash
      clearPixels();
      for (int y = 0; y < y_max; y++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][y][y] = true;
        }
      }  
  }
  else if(stage==2){ // floor
      clearPixels();
      for (int y = 0; y < y_max; y++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][y][0] = true;
        }
      }  
  }
  else if(stage==3){ // floor to left
      clearPixels();
      for (int y = 0; y < y_max; y++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][y][x] = true;
        }
      }  
  }
  else if(stage==4){
      clearPixels(); // left wall
      for (int z = 0; z < z_max; z++){
        for (int y = 0; y < y_max; y++){  
          pixels[0][y][z] = true;
        }
      }  
  }
  else if(stage==5){ // left to back 
      clearPixels();
      for (int z = 0; z < z_max; z++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][(y_max-1)-x][z] = true;
        }
      }  
  }
  else if(stage==6){ // back wall
      clearPixels();
      for (int z = 0; z < z_max; z++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][y_max-1][z] = true;
        }
      }  
  }
  else if(stage==7){ // back to ceiling
      clearPixels();
      for (int y = 0; y < y_max; y++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][y][y] = true;
        }
      }  
  }
  else if(stage==8){ // ceiling
      clearPixels();
      for (int y = 0; y < y_max; y++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][y][z_max-1] = true;
        }
      }  
  }
  else if(stage==9){ // ceiling to right
      clearPixels();
      for (int y = 0; y < y_max; y++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][y][x] = true;
        }
      }  
  }
  else if(stage==10){ // right wall
      clearPixels();
      for (int z = 0; z < z_max; z++){
        for (int y = 0; y < y_max; y++){  
          pixels[x_max-1][y][z] = true;
        }
      }  
  }
  else if(stage==11){ // right to front
    clearPixels();
      for (int z = 0; z < z_max; z++){
        for (int x = 0; x < x_max; x++){  
          pixels[x][(y_max-1)-x][z] = true;
        }
      }
  }
}

// RACHEL'S STUFF ENDS HERE

void playDancingMan(){
  int dur = 525;
   for ( int i = 0; i < dur/25; i++){
    for ( int i2 = 0; i2 < 18; i2++ ){ // was 25
        drawDancingMan(i);
        writePixels();
    }
  }
}

int drawDancingMan(int i)
{
   switch(i){
      
      case 1:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==2 && z==4) || 
        (x==3 && z==1) || (x==3 && z==3) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==0) || (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==1) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==0) || (x==6 && z==3) || (x==6 && z==4)||
        (x==7 && z==4)){
          pixels[x][7][z] = true;
          pixels[x][6][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 2:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==2 && z==4) || 
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==3) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==0) || (x==5 && z==1) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)){
         pixels[x][7][z] = true;
         pixels[x][6][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 3:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==1 && z==4) || 
        (x==2 && z==0) || (x==2 && z==3) || (x==2 && z==4) ||
        (x==3 && z==1) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==0) || (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==1) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)){
          pixels[x][7][z] = true;          
          pixels[x][6][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 4:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==2 && z==4) || 
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==3) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==0) || (x==5 && z==1) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)){
          pixels[x][5][z] = true;
          pixels[x][4][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 5:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==2 && z==4) || 
        (x==3 && z==1) || (x==3 && z==3) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==0) || (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==1) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==0) || (x==6 && z==3) || (x==6 && z==4)||
        (x==7 && z==4)){
          pixels[x][5][z] = true;
          pixels[x][4][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 6:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==2 && z==4) || 
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==3) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==0) || (x==5 && z==1) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)){
          pixels[x][5][z] = true;
          pixels[x][4][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 7:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==1 && z==4) || 
        (x==2 && z==0) || (x==2 && z==3) || (x==2 && z==4) ||
        (x==3 && z==1) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==0) || (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==1) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)){
          pixels[x][5][z] = true;
          pixels[x][4][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 8:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==2 && z==4) || 
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==3) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==0) || (x==5 && z==1) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)){
          pixels[x][3][z] = true;
          pixels[x][2][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
       case 9:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==2 && z==4) || 
        (x==3 && z==1) || (x==3 && z==3) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==0) || (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==1) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==0) || (x==6 && z==3) || (x==6 && z==4)||
        (x==7 && z==4)){
          pixels[x][3][z] = true;
          pixels[x][2][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 10:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==2 && z==4) || 
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==3) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==0) || (x==5 && z==1) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)){
          pixels[x][3][z] = true;
          pixels[x][2][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 11:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==1 && z==4) || 
        (x==2 && z==0) || (x==2 && z==3) || (x==2 && z==4) ||
        (x==3 && z==1) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==0) || (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==1) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 12:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ( (x==1 && z==4) || (x==1 && z==5) || 
        (x==2 && z==0) || (x==2 && z==4) || 
        (x==3 && z==1) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==1) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==0) || (x==6 && z==4)||
        (x==6 && z==0) || (x==6 && z==4)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 13:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ( (x==1 && z==3) || (x==1 && z==4) || 
        (x==2 && z==4) ||
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==2) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==0) || (x==5 && z==1) || (x==5 && z==2) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)||
        (x==7 && z==4) || (x==7 && z==5)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 14:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ( (x==1 && z==4) || (x==1 && z==5) || 
        (x==2 && z==0) || (x==2 && z==4) ||
        (x==3 && z==1) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==1) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==0) || (x==6 && z==4)||
        (x==7 && z==3) || (x==7 && z==4)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
       case 15:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ( (x==1 && z==3) || (x==1 && z==4) || 
        (x==2 && z==4) ||
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==2) || (x==3 && z==4) || (x==3 && z==5) || (x==3 && z==6) || (x==3 && z==7) || 
        (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==4) || (x==4 && z==5) || (x==4 && z==7) || 
        (x==5 && z==0) || (x==5 && z==1) || (x==5 && z==2) || (x==5 && z==4) || (x==5 && z==5) || (x==5 && z==6) || (x==5 && z==7) ||
        (x==6 && z==4)||
        (x==7 && z==4) || (x==7 && z==5)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 16:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ( (x==1 && z==0) || (x==1 && z==2) || (x==1 && z==3) ||
        (x==2 && z==0) || (x==2 && z==2) ||
        (x==3 && z==2) || (x==3 && z==2) || (x==3 && z==4) || (x==3 && z==5) || 
        (x==4 && z==0) || (x==4 && z==1) || (x==4 && z==2) || (x==4 && z==3) || (x==4 && z==5) || 
        (x==5 && z==0) || (x==5 && z==2) || (x==5 && z==3) || (x==5 && z==4) || (x==5 && z==5) ||
        (x==6 && z==0) || (x==6 && z==2) ||
        (x==7 && z==0) || (x==7 && z==2) || (x==7 && z==3)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 17:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==0 && z==2) || (x==0 && z==3) || (x==0 && z==4) ||
        (x==1 && z==2) || (x==1 && z==4) ||
        (x==2 && z==2) || (x==2 && z==3) || (x==2 && z==4) ||
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==2) || 
        (x==4 && z==2) ||
        (x==5 && z==2) ||
        (x==6 && z==1) ||
        (x==7 && z==0)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 18:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==0 && z==1) || (x==0 && z==2) || (x==0 && z==3) || 
        (x==1 && z==1) || (x==1 && z==3) ||
        (x==2 && z==1) || (x==2 && z==2) || (x==2 && z==3) ||
        (x==3 && z==0) || (x==3 && z==1) ||
        (x==4 && z==1) ||
        (x==5 && z==1) ||
        (x==6 && z==1) ||
        (x==7 && z==0)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 19:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==0 && z==2) || (x==0 && z==3) || (x==0 && z==4) ||
        (x==1 && z==2) || (x==1 && z==4) ||
        (x==2 && z==2) || (x==2 && z==3) || (x==2 && z==4) ||
        (x==3 && z==0) || (x==3 && z==1) || (x==3 && z==2) || 
        (x==4 && z==2) ||
        (x==5 && z==2) ||
        (x==6 && z==1) ||
        (x==7 && z==0)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      case 20:
      clearPixels();
      for (int z = 0; z < z_max; z++){
      for (int x = 0; x < x_max; x++){
        if ((x==0 && z==1) || (x==0 && z==2) || (x==0 && z==3) || 
        (x==1 && z==1) || (x==1 && z==3) ||
        (x==2 && z==1) || (x==2 && z==2) || (x==2 && z==3) ||
        (x==3 && z==0) || (x==3 && z==1) ||
        (x==4 && z==1) ||
        (x==5 && z==1) ||
        (x==6 && z==1) ||
        (x==7 && z==0)){
          pixels[x][0][z] = true;
          pixels[x][1][z] = true;
        }
        else{
          pixels[x][0][z] = false;
        }
    }
    }
      break;
      
      
    } 
}
