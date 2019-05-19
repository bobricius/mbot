#include "Adafruit_FreeTouch.h"

Adafruit_FreeTouch qt_up = Adafruit_FreeTouch(8, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_down = Adafruit_FreeTouch(A3, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_left = Adafruit_FreeTouch(A4, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_right = Adafruit_FreeTouch(42, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_play = Adafruit_FreeTouch(9, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);

#define X1   3
#define X2   2
#define X3   5

#define Y1   12
#define Y2   10
#define Y3   11

#define COIL   4

#define SPEED  25

int xpos = 1000;
int ypos = 1000;



void setup() {
//  SerialUSB.begin(115200);
  
//  while (!SerialUSB);
//  SerialUSB.println("FreeTouch test");
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(X1, OUTPUT);
  pinMode(X2, OUTPUT);
  pinMode(X3, OUTPUT);
  digitalWrite(X1, LOW);
  digitalWrite(X2, LOW);
  digitalWrite(X3, LOW);

  pinMode(Y1, OUTPUT);
  pinMode(Y2, OUTPUT);
  pinMode(Y3, OUTPUT);
  digitalWrite(Y1, LOW);
  digitalWrite(Y2, LOW);
  digitalWrite(Y3, LOW);

  pinMode(COIL, OUTPUT);
  digitalWrite(COIL, LOW);

qt_up.begin(); 
qt_down.begin(); 
qt_left.begin();  
qt_right.begin();  
qt_play.begin(); 

   analogWriteResolution(8) ;
}



void loop() {
if (qt_down.measure()>850) down_step(1); 
if (qt_up.measure()>850) up_step(1); 
if (qt_left.measure()>850) left_step(1); 
if (qt_right.measure()>850) right_step(1); 
if (qt_play.measure()>850) play(); 
  
}

void play ()
{
  digitalWrite(COIL, HIGH); 
right_step(20);
down_step(20);
left_step(20);
up_step(20);             

right_step(10);
down_step(10);
left_step(10);
up_step(10);   
  digitalWrite(COIL, LOW);  
}


void x_step (int xx, char pwr)
{
switch (xx%6){
 case 0:
   analogWrite(X1, pwr); 
  break;
 case 1:
   analogWrite(X1, pwr);
   analogWrite(X2, pwr);  
  break;
 case 2:
   analogWrite(X2, pwr);
  break;
 case 3:
   analogWrite(X2, pwr);
   analogWrite(X3, pwr); 
  break;
 case 4:
   analogWrite(X3, pwr); 
  break;
 case 5:
   digitalWrite(X3, pwr);
   digitalWrite(X1, pwr);   
  break;     
}
}

void y_step (int yy, char pwr)
{
switch (yy%6){
 case 0:
   analogWrite(Y1, pwr); 
  break;
 case 1:
   analogWrite(Y1, pwr);
   analogWrite(Y2, pwr);  
  break;
 case 2:
   analogWrite(Y2, pwr);
  break;
 case 3:
   analogWrite(Y2, pwr);
   digitalWrite(Y3, pwr); 
  break;
 case 4:
   digitalWrite(Y3, pwr); 
  break;
 case 5:
   analogWrite(Y3, pwr);
   analogWrite(Y1, pwr);   
  break;     
}
}

void right_step (int i){
  for (int a = 0 ; a < i;  a++) {
  xpos++;
  y_step (ypos,10);  
  x_step (xpos,255);
  delay (SPEED);
  off_all() ;  
//  delay (SPEED); 
  }
  
}

void left_step (int i){
  for (int a = 0 ; a < i;  a++) {
  xpos--;
  y_step (ypos,10);  
  x_step (xpos,255);
  delay (SPEED);
  off_all() ;  
//  delay (SPEED);
  } 

}


void down_step (int i)
{
  for (int a = 0 ; a < i;  a++) {
  ypos--;
  y_step (ypos,255);  
//  x_step (xpos,10);
  delay (SPEED*2);
  off_all() ;  

  
  } 
  
}

void up_step (int i)
{
  for (int a = 0 ; a < i;  a++) {
  ypos++;
  y_step (ypos,255);  
//  x_step (xpos,10);
  delay (SPEED*2);
  off_all() ;  
//  delay (SPEED);
  } 
 
}

void off_all ()
{
  analogWrite(X1, 0);
  analogWrite(X2, 0);
  analogWrite(X3, 0);  
  analogWrite(Y1, 0);
  analogWrite(Y2, 0);
  analogWrite(Y3, 0);
}
