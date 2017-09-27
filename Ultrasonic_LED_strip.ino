/*
** Title: Ultrasonic_LED_strip
** Purpose: To control a strip of NeoPixels by mapping the distance to your hand (measured by an HC-SR04 ultrasonic sensor)
**          to the number of LEDs turned on in the strip.
** Usage:
**
** Created by: Justas Lukosiunas
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
int practical_distance;
int dist_read_array[numb_of_readings];
int median_distance;

//LEDs
#define NUM_OF_PIXELS 10
#define LED_PIN 2  
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_OF_PIXELS, LED_PIN);
int controllable_distance = 40; // in cm
int ultrasonic_deadspace = 5; //in cm
int led_counter;
float leds_off_prop;
uint32_t color_off = strip.Color(0, 0, 0);
//**************************************************************
// The line above shows the definition of the colour of the LED when
// it is in its OFF state. The function strip.Color() takes three input
// arguments, which represent a particular colour code in the RGB scheme.
// Hence (0, 0, 0) is equivalent to 'black' or, in practical case, the 
// LED being OFF.
//
// Your task here is to insert an identical statement to make the LEDs
// light up in yellow colour when they are on. To achieve that you will
// need to find out which RGB values encode the yellow colour. Finally,
// you should call the variable 'colour_on'.
//
// INSERT A LINE OF CODE BELOW:

//
//**************************************************************



//---------------
//---MAIN CODE---
//---------------
void setup() {
//**************************************************************
// Following the examples from the individual LED and Ultrasonic sensor 
// codes, you will have to initialize both devices with corresponding
// statements.
//  
// INSERT CODE BELOW:

//
//**************************************************************
}

void loop() {
  //ULTRASONIC
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  // The loop below takes in 5 distance readings and stores them in an array
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

  // Here the array with 5 recent distance readings is sorted in ascending order
  sort(dist_read_array,numb_of_readings);

  // The median of the array is taken to achieve an averaging effect
  // and discard any faulty readings.
  if (dist_read_array[median_index] < practical_distance)
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

    // The variable led_counter stores how many LEDs, counting from the start of the strip,
    // have to be turned on, in order to follow the distance reading.
    led_counter = (1-leds_off_prop)*NUM_OF_PIXELS;
  }
  else
  {
    Serial.print(", OUTSIDE OF CONTROLLABLE DISTANCE "); 
    led_counter = 0;
  }

//**************************************************************
// Now that you have the number of LEDs that have to be turned on (led_counter)
// and the number of LEDs in the strip (NUM_OF_PIXELS), you will need to form
// another loop that will go through all LEDs and turn them on or off. In other words,
// if the index of an LED is less than the value stored in 'led_counter', turn the LED on,
// otherwise turn it off. To achieve this use a 'for' loop, similar to the one used in line 77
// of this code. The function for changing the colour of the LEDs should be taken from the
// individual LED code you've already worked on.
//  
// INSERT CODE BELOW:

//
//**************************************************************
    strip.show();
  

  //Informational message showing, how many LEDs are on
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

