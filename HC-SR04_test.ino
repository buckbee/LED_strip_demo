/*
** Title: Ultrasonic sensor HC-SR04 Arduino test code.
** Purpose: Prints the distance to an object (to the serial monitor) every 100ms.
** Usage guide: Open serial monitor
**
** Created by Kasper Buckbee
*/

//define digital pins on Arduino to use for hc-sr04 module
const int trigPin = //Blank:___________________________ //Fill:  9;
const int echoPin = //Blank:___________________________ //Fill: 10;
                
//define variables
long pulse_duration;
int distance;

void setup() {
  pinMode(trigPin, OUTPUT); // set trigPin as an Output
  pinMode(echoPin, INPUT); // set echoPin as an Input
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
  distance = //Blank:___________________________ //Fill: duration*0.034/2; 
  
  //Print the calculated distance to the Serial monitor
  Serial.print("Distance: ");
  Serial.println(distance); //.println adds newline after each reading
  delay(100); //delay 100ms between readings
}
