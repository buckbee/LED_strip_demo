/*
** Title: Neopixel (WS2812B) LED test
** Purpose: Testing a strip of WS2812B neopixel LEDs by assigning one colour to each LEDs in the strip.
** Usage: Define NUM_OF_PIXELS, LED_PIN and pixel colour then upload code to Arduino
**
** Created by: Kasper Buckbee
** Edited by: -
*/


//Include needed libraries
#include <Adafruit_NeoPixel.h>

//Define constant parameters
#define NUM_OF_PIXELS //Blank: ________________________//
#define LED_PIN //Blank: ________________________//  

//Define LED strip to be a NeoPixel strip
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_OF_PIXELS, LED_PIN);


void setup() {
  strip.begin(); //initiliase strip pin for NeoPixel output
  strip.show(); //write all pixels 'off' 
}

void loop() {

  //Set 10 pixels to different colours
  strip.setPixelColor(0, 255, 0, 255); // setPixelColor(Pin#, R, G, B)
  //Blank: ________________________//
  //Blank: ________________________//
  //Blank: ________________________//
  //Blank: ________________________//
  //Blank: ________________________//
  //Blank: ________________________//
  //Blank: ________________________//
  //Blank: ________________________//
  //Blank: ________________________//
 
  //Push the above values to the pixels
  strip.show();
  
  //Wait a while
  delayMicroseconds(10);

}
