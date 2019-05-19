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

#define SPEED   40

int xpos = 1000;
int ypos = 1000;



void setup() {
  SerialUSB.begin(115200);
  
//  while (!SerialUSB);
  SerialUSB.println("FreeTouch test");
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

  if (! qt_up.begin())  
    SerialUSB.println("Failed to begin qt on pin 1");
  if (! qt_down.begin())  
    SerialUSB.println("Failed to begin qt on pin 2");
  if (! qt_left.begin())  
    SerialUSB.println("Failed to begin qt on pin 3");
  if (! qt_right.begin())  
    SerialUSB.println("Failed to begin qt on pin 4");
  if (! qt_play.begin())  
    SerialUSB.println("Failed to begin qt on pin 5");

    
}



void loop() {
  int counter, result = 0;
  
  // DIY
//  SerialUSB.println("\n*************************************");
//
//  counter = millis();
//  result = qt_1.measure(); 
//  SerialUSB.print("QT 1: "); SerialUSB.print(result);
//  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");
//
//  counter = millis();
//  result = qt_2.measure(); 
//  SerialUSB.print("QT 2: "); SerialUSB.print(result);
//  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");
//
//  counter = millis();
//  result = qt_3.measure(); 
//  SerialUSB.print("QT 3: "); SerialUSB.print(result);
//  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");
//  
//  counter = millis();
//  result = qt_4.measure(); 
//  SerialUSB.print("QT 4: "); SerialUSB.print(result);
//  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");
//
//  result = qt_5.measure(); 
//  SerialUSB.print("QT 5: "); SerialUSB.print(result);
//  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");
//  
//  delay(200);


if (qt_down.measure()>850) down_step(); 
if (qt_up.measure()>850) up_step(); 
if (qt_left.measure()>850) left_step(); 
if (qt_right.measure()>850) right_step(); 
if (qt_play.measure()>850) play(); 
  
}

void play ()
{

  digitalWrite(COIL, HIGH); 

             
  digitalWrite(COIL, LOW);  
}


void x_step (int xx)
{
switch (xx%3){
 case 0:
   digitalWrite(X1, HIGH); 
  break;
 case 1:
   digitalWrite(X2, HIGH); 
  break;
 case 2:
   digitalWrite(X3, HIGH);
  break;    
}
}

void y_step (int yy)
{
switch (yy%3){
 case 0:
   digitalWrite(Y1, HIGH); 
  break;
 case 1:
   digitalWrite(Y2, HIGH); 
  break;
 case 2:
   digitalWrite(Y3, HIGH);
  break;    
}
}

void right_step (){
  xpos++;
  y_step (ypos);  
  x_step (xpos);
  delay (SPEED);
  off_all() ;
}

void left_step (){
  xpos--;
  y_step (ypos);  
  x_step (xpos);
  delay (SPEED);
  off_all() ;  
}


void down_step ()
{
  ypos--;
  y_step (ypos);  
  x_step (xpos);
  delay (SPEED);
  off_all() ;
}

void up_step ()
{
  ypos++;
  y_step (ypos);  
  x_step (xpos);
  delay (SPEED);
  off_all() ;
}

void off_all ()
{
  digitalWrite(X1, LOW);
  digitalWrite(X2, LOW);
  digitalWrite(X3, LOW);  
  digitalWrite(Y1, LOW);
  digitalWrite(Y2, LOW);
  digitalWrite(Y3, LOW);

}
