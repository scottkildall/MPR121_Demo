# MPR121_Demo
by Scott Kildall

www.kildall.com

January 18th 2017

--------------------

A simple Arudino sketch that uses the Adafruit LED backpack hooked to a MPR221 Touch Capacitance board by AdaFruit.

This uses all 12 inputs and displays the results, as a binary sequence on the LED backpack, e.g.

if no sensors are on, the value = 0
if pin 0 is pressed down, value = 1
if pin 1 is pressed down, value = 2
if pin 0 and 1 is pressed down, value = 3

etc..


Their GitHub repos for their libraries are here:
https://github.com/adafruit/Adafruit_LED_Backpack
https://github.com/adafruit/Adafruit_MPR121

These need to be copied into the Arduino/libraries folder.

Refer to hookup_image.jpg to see how the demo looks

