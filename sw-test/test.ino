#define X1   6
#define X2   5
#define X3   4

#define Y1   7
#define Y2   8
#define Y3   9

#define BTN_UP   A3
#define BTN_DOWN   A2
#define BTN_LEFT   A1
#define BTN_RIGHT   A0

#define BTN_PLAY   2

#define SPEED   60
// the setup function runs once when you press reset or power the board
void setup() {
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

  pinMode(BTN_UP, INPUT_PULLUP);
  pinMode(BTN_DOWN, INPUT_PULLUP);   
  pinMode(BTN_LEFT, INPUT_PULLUP);
  pinMode(BTN_RIGHT, INPUT_PULLUP); 
  pinMode(BTN_PLAY, INPUT_PULLUP);  
}

// the loop function runs over and over again forever
void loop() {
if (digitalRead(BTN_DOWN)==0) down(); 
if (digitalRead(BTN_UP)==0) up(); 
if (digitalRead(BTN_LEFT)==0) left(); 
if (digitalRead(BTN_RIGHT)==0) right(); 
if (digitalRead(BTN_PLAY)==0) play(); 
}

void play ()
{
 up();
 up();
 up();
 up();

  down();
  down();
  down();
  down();
}
void right ()
{

  digitalWrite(Y1, HIGH); 
  delay(SPEED);             
  digitalWrite(Y1, LOW);  
  digitalWrite(Y2, HIGH); 
  delay(SPEED);             
  digitalWrite(Y2, LOW); 
  digitalWrite(Y3, HIGH); 
  delay(SPEED);             
  digitalWrite(Y3, LOW); 
}

void left ()
{
  digitalWrite(Y3, HIGH); 
  delay(SPEED);             
  digitalWrite(Y3, LOW);  
  digitalWrite(Y2, HIGH); 
  delay(SPEED);             
  digitalWrite(Y2, LOW); 
  digitalWrite(Y1, HIGH); 
  delay(SPEED);             
  digitalWrite(Y1, LOW); 
}
void down ()
{

 // digitalWrite(Y1, HIGH); 

  digitalWrite(X1, HIGH); 
  delay(SPEED);             
  digitalWrite(X1, LOW);  
  digitalWrite(X2, HIGH); 
  delay(SPEED);             
  digitalWrite(X2, LOW); 
  digitalWrite(X3, HIGH); 
  delay(SPEED);             
  digitalWrite(X3, LOW); 

 //   digitalWrite(Y1, LOW); 
}

void up ()
{
//  digitalWrite(Y1, HIGH); 
 
  digitalWrite(X3, HIGH); 
  delay(SPEED);             
  digitalWrite(X3, LOW);  
  digitalWrite(X2, HIGH); 
  delay(SPEED);             
  digitalWrite(X2, LOW); 
  digitalWrite(X1, HIGH); 
  delay(SPEED);             
  digitalWrite(X1, LOW);

           
 
  
//  digitalWrite(X3, HIGH); 
//  delay(SPEED);             
//  digitalWrite(X3, LOW);  
//
//
//  digitalWrite(X3, HIGH); 
//  digitalWrite(X2, HIGH); 
//  delay(SPEED);             
//  digitalWrite(X3, LOW);  
//  digitalWrite(X2, LOW); 
//
//  digitalWrite(X2, HIGH); 
//  delay(SPEED);             
//  digitalWrite(X2, LOW);
//
//
//  digitalWrite(X2, HIGH); 
//  digitalWrite(X1, HIGH); 
//  delay(SPEED);             
//  digitalWrite(X1, LOW);  
//  digitalWrite(X2, LOW); 
//
//  digitalWrite(X1, HIGH); 
//  delay(SPEED);             
//  digitalWrite(X1, LOW); 
//
//
//
//  digitalWrite(X3, HIGH); 
//  digitalWrite(X1, HIGH); 
//  delay(SPEED);             
//  digitalWrite(X1, LOW);  
//  digitalWrite(X3, LOW); 

}


//  digitalWrite(X3, HIGH); 
//  delay(SPEED);             
//  digitalWrite(X3, LOW);  
//  digitalWrite(X2, HIGH); 
//  delay(SPEED);             
//  digitalWrite(X2, LOW); 
//  digitalWrite(X1, HIGH); 
//  delay(SPEED);             
// 



//  for(byte i = 1; i <255; i++){  
//  digitalWrite(X1, HIGH); 
//    delayMicroseconds(3*(255-i)); 
//   digitalWrite(X1, LOW); 
//  digitalWrite(X2, HIGH); 
//   delayMicroseconds(3*i);
//   digitalWrite(X2, LOW);         
//  }
//  for(byte i = 1; i <255; i++){  
//  digitalWrite(X2, HIGH); 
//    delayMicroseconds(3*(255-i)); 
//   digitalWrite(X2, LOW); 
//  digitalWrite(X3, HIGH); 
//   delayMicroseconds(3*i);
//   digitalWrite(X3, LOW);         
//  }
//  for(byte i = 1; i <255; i++){  
//  digitalWrite(X3, HIGH); 
//    delayMicroseconds(3*(255-i)); 
//   digitalWrite(X3, LOW); 
//  digitalWrite(X1, HIGH); 
//   delayMicroseconds(3*i);
//   digitalWrite(X1, LOW);         
//  } 
