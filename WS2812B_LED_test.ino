/*
** Title: Neopixel (WS2812B) LED test
** Purpose: Testing a strip of WS2812B neopixel LEDs by assigning one colour to each LEDs in the strip.
** Usage: Define NUM_OF_PIXELS, LED_PIN and pixel colour then upload code to Arduino
**
** Created by: Kasper Buckbee
** Edited by: -
*/

// NOTES:
// 1) To define a LED strip: 
//      Adafruit_NeoPixel strip = Adafruit_NeoPixel(param1, param2, param3);
// Where:
//      Parameter 1 = number of pixels in strip
//      Parameter 2 = pin number (most are valid)
//      Parameter 3 = pixel type flags, add the following together as needed:
//
//        NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//        NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//        NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//        NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
// Example:
// Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);

// 2) To set LED colours:
//      a) ledA.setPixelColor(n, red, green, blue);
//      b) ledA.setPixelColor(n, color); 
// Where:
//      n = pixel number along the strip (numbered 0-9 for 10 pixels)
//      color = 32 bit value that combines RGB values as one number
//      red, green, blue: any value between 0 to 255

// 3) Can also save colours: 
//       uint32_t magenta = strip.Color(255, 0, 255);
//    and then just pass in 'magenta' to the 'color' variable.

// 4) setPixelColor() does not have an immediate effect on the LEDs. 
//    To “push” the color data to the strip, call .show()


// * CODE STARTS *
//Include needed libraries
#include <Adafruit_NeoPixel.h>

//Define constant parameters
#define NUM_OF_PIXELS 10
#define LED_PIN 2    

//Define LED strip to be a NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_OF_PIXELS, LED_PIN);


void setup() {
  strip.begin(); //initiliase strip pin for NeoPixel output
  strip.show(); //write all pixels 'off' 
}

void loop() {

  //Set 10 pixels to different colours
  strip.setPixelColor(0, 255, 0, 255);
  //Blank:___________________________ // Fill: the rest of the LED colour definitions

 
  //Push the above values to the pixels
  strip.show();
  
  //Wait a while
  delayMicroseconds(10);

}
