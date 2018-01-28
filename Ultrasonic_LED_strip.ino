/*
** Title: Ultrasonic_LED_strip
** Purpose: To control a strip of NeoPixels by mapping the distance to your hand (measured by an HC-SR04 ultrasonic sensor)
**          to the number of LEDs turned on in the strip.
** Usage:
**
** Created by: Justas Lukosiunas, Ben Cunningham, Kasper Buckbee
*/

//Include required libraries
#include <Adafruit_NeoPixel.h>

//-----------------
//---DEFINITIONS---
//---------------
//Ultrasonic sensor
const int trigPin = 9;
const int echoPin = 10;
const int numb_of_readings = 5;
const int median_index = ceil(numb_of_readings/2);
long Time;
int current_distance;
int dist_read_array[numb_of_readings];
int median_distance;

//LEDS
#define NUM_OF_PIXELS 10
#define LED_PIN 2  
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_OF_PIXELS, LED_PIN);
int controllable_distance = 40; // in cm
int ultrasonic_deadspace = 10; //in cm
int led_counter;
float leds_off_prop;

//-----------------------------------------------------------------
//-----------------SEGMENTS TO BE COMPLETED------------------------
//-----------------------------------------------------------------
uint32_t colour_on = strip.Color(255,127,0); //<-------Insert numbers 0-255 instead of R, G and B.
uint32_t colour_off = strip.Color(0,0,0); //<-------Insert numbers 0-255 instead of R, G and B.

int calculate_distance(long Time) {
  int distance = Time*0.034/2;/*/<-------Insert your equation for calculating the distance instead of the word 'EQUATION'. 
                          Use the variable name 'Time' for the ultrasonic sensor's time duration reading, 
                          '*' for multiplication and '/' for division. */
  return distance;
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------
//-----------------------------------------------------------------

//Function for sorting an array in an increasing order
void sort(int a[], int size) {
    for(int i=0; i<(size-1); i++) {
        for(int o=0; o<(size-(i+1)); o++) {
                if(a[o] > a[o+1]) {
                    int t = a[o];
                    a[o] = a[o+1];
                    a[o+1] = t;
                }
        }
    }
}

//---------------
//---MAIN CODE---
//---------------
void setup() {
  //Ultrasonic
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
  
  //LEDs
  strip.begin(); //initiliase pin
  strip.show(); //all pixels 'off' 
}

void loop() {
  //ULTRASONIC
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  

  for(int j=0;j<numb_of_readings;j++){
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    // Reads the echoPin, returns the sound wave travel Time in microseconds
    Time = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    current_distance = calculate_distance(Time);
    dist_read_array[j] = current_distance;

  }

  //Performing averaging 
  sort(dist_read_array,numb_of_readings);
  
  if (dist_read_array[median_index] < 300)
  {
    median_distance = dist_read_array[median_index] - ultrasonic_deadspace;              
  }
  
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.print(median_distance);
  
  //LEDS 
  if(median_distance < controllable_distance)
  {  
    leds_off_prop = float(median_distance)/float(controllable_distance);

    led_counter = (1-leds_off_prop)*NUM_OF_PIXELS;
  }
  else
  {
    Serial.print(", OUTSIDE OF CONTROLLABLE DISTANCE "); 
    led_counter = 0;
  }

    //Loop that goes through all LEDs and turns them on/off depending on distance
    for(int i=0;i<NUM_OF_PIXELS;i++){
      if(i<led_counter)
        {          
          strip.setPixelColor(i, colour_on);
        }        
      else
        {
          strip.setPixelColor(i, colour_off);
        }      
    }
    strip.show();

  //Printing the internal control signal state for debugging purposes 
  Serial.print(", Number of LEDs on: ");
  Serial.print(led_counter);
  Serial.println(" ");
}
