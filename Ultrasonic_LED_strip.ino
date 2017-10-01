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
long duration;
int current_distance;
int dist_read_array[numb_of_readings];
int median_distance;

//LEDs
#define NUM_OF_PIXELS 10
#define LED_PIN 2  
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_OF_PIXELS, LED_PIN);
int controllable_distance = 40; // in cm
int ultrasonic_deadspace = 5; //in cm
uint32_t colour_on = strip.Color(255, 255, 255);
uint32_t colour_off = strip.Color(0, 0, 0);
uint32_t colour_30 = strip.Color(30, 30, 0);
uint32_t colour_5 = strip.Color(5, 0, 5);
int led_counter;
float leds_off_prop;



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
    
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    
    // Calculating the distance
    current_distance = duration*0.034/2;
    
    dist_read_array[j] = current_distance;

  }

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
    strip.setPixelColor(led_counter, colour_30);
    strip.setPixelColor(led_counter+1, colour_5);
    strip.show();
  

  
  Serial.print(", Number of LEDs on: ");
  Serial.print(led_counter);
  Serial.println(" ");
  
}

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

//Function 
