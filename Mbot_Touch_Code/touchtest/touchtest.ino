#include "Adafruit_FreeTouch.h"

Adafruit_FreeTouch qt_1 = Adafruit_FreeTouch(A3, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_2 = Adafruit_FreeTouch(A4, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_3 = Adafruit_FreeTouch(8, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_4 = Adafruit_FreeTouch(9, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);
Adafruit_FreeTouch qt_5 = Adafruit_FreeTouch(42, OVERSAMPLE_4, RESISTOR_50K, FREQ_MODE_NONE);


void setup() {
  SerialUSB.begin(115200);
  
  while (!SerialUSB);
  SerialUSB.println("FreeTouch test");
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);

  if (! qt_1.begin())  
    SerialUSB.println("Failed to begin qt on pin 1");
  if (! qt_2.begin())  
    SerialUSB.println("Failed to begin qt on pin 2");
  if (! qt_3.begin())  
    SerialUSB.println("Failed to begin qt on pin 3");
  if (! qt_4.begin())  
    SerialUSB.println("Failed to begin qt on pin 4");
  if (! qt_5.begin())  
    SerialUSB.println("Failed to begin qt on pin 5");
}



void loop() {
  int counter, result = 0;
  
  // DIY
  SerialUSB.println("\n*************************************");

  counter = millis();
  result = qt_1.measure(); 
  SerialUSB.print("QT 1: "); SerialUSB.print(result);
  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");

  counter = millis();
  result = qt_2.measure(); 
  SerialUSB.print("QT 2: "); SerialUSB.print(result);
  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");

  counter = millis();
  result = qt_3.measure(); 
  SerialUSB.print("QT 3: "); SerialUSB.print(result);
  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");
  
  counter = millis();
  result = qt_4.measure(); 
  SerialUSB.print("QT 4: "); SerialUSB.print(result);
  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");

  result = qt_5.measure(); 
  SerialUSB.print("QT 5: "); SerialUSB.print(result);
  SerialUSB.print(" (");  SerialUSB.print(millis() - counter); SerialUSB.println(" ms)");
  
  delay(200);
}
