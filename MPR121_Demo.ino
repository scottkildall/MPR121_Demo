/*********************************************************
    Adafruit Capacitance Touch Sensor Example
 
    Written by Scott Kildall
    www.kildall.com
   
   A simple Arudino sketch that uses the Adafruit LED backpack hooked to a MPR221 Touch Capacitance board by AdaFruit.

  This uses all 12 inputs and displays the results, as a binary sequence on the LED backpack, e.g.

  if no sensors are on, the value = 0
  if pin 0 is pressed down, value = 1
  if pin 1 is pressed down, value = 2
  if pin 0 and 1 is pressed down, value = 3

  if the capacitance sensor isn't working, it will display an error of 9999

  Adafruit GitHub repos for their libraries are here:
  https://github.com/adafruit/Adafruit_LED_Backpack
  https://github.com/adafruit/Adafruit_MPR121

  These need to be copied into the Arduino/libraries folder.

**********************************************************/

#include <Wire.h>
#include "Adafruit_MPR121.h"
#include "Adafruit_LEDBackpack.h"

//-- this is the LED backpack
Adafruit_7segment matrix = Adafruit_7segment();

//-- capacitance touch sensor
Adafruit_MPR121 cap = Adafruit_MPR121();

void setup() {
  //-- initalize the 7-segment LED
  matrix.begin(0x70);
  matrix.print(9999, DEC);
  matrix.writeDisplay();
    
  // Use 0x5A for 5V from Arduino, 0x5B for 3.3V
  // try to init the capacitance sensor, keep at it until it works, but likely you will have to reset the Arduino
  if (!cap.begin(0x5A)) {
    matrix.writeDisplay();
    delay(100);
  }
  
  // 0 = normal state (nothing pressed)
  matrix.print(0, DEC);
  matrix.writeDisplay();
}

//-- get the touched status, which is a bitmask, i.e. pin 0 = 1 (if touched), pin 1 = 2 =
void loop() {
  //-- store in a local var for legibility
  uint16_t capBitmask = cap.touched();

   matrix.begin(0x70);
   matrix.print(capBitmask, DEC);
   matrix.writeDisplay();
}
