#include <Servo.h> 

Servo servo1;

// measure flex sensor position:
const int flexpin = 0; 


void setup() 
{ 
   
  Serial.begin(9600);
  servo1.attach(9);
} 


void loop() 
{ 
  int flexposition;    // Input value from the analog pin.
  int servoposition;   // Output value to the servo.

  // Read the position of the flex sensor
  
  flexposition = analogRead(flexpin);

  
  
  //servoposition = map(flexposition, 0, 1023, 0, 180);
  //servoposition = map(flexposition, 600, 900, 0, 180);
  servoposition = map(flexposition, 600, 700, 0, 180);
  servoposition = constrain(servoposition, 0, 180);

  //Back to original position
  servo1.write(servoposition);

 //Debug  
  Serial.print("sensor: ");
  Serial.print(flexposition);
  Serial.print("  servo: ");
  Serial.println(servoposition);
  
   delay(200);
} 


