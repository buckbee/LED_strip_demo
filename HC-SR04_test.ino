/*
** Title: Ultrasonic sensor HC-SR04 Arduino test code.
** Purpose: Prints the distance to an object (to the serial monitor) every 100ms.
** Usage guide: Open serial monitor
**
** Created by Kasper Buckbee
*/

//define digital pins on Arduino to use for hc-sr04 module
const int trigPin = //Blank: ________________________//
const int echoPin = //Blank: ________________________//
                
//define variables
long pulse_duration;
int distance;

void setup() {
  pinMode(trigPin, //Blank: ________________________//); // input/output
  pinMode(echoPin, //Blank: ________________________//); // input/output 
  Serial.begin(9600); // start serial communication at 9600 baud (bits/s)
}

void loop() {
  //Initialise trigPin LOW before sending trigger command
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  
  //Send trigger signal by setting trigPin high for 10us
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  //Read the echoPin response - pulseIn returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  //Calculate the distance to object
  distance= //Blank: ________________________//
  
  //Print the calculated distance to the Serial monitor
  Serial.print("Distance: ");
  Serial.println(distance); //.println adds newline after each reading
  delay(100); //delay 100ms between readings
}
