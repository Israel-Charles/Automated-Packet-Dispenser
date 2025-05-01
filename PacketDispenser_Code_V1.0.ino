/*//////////////////////////////////////////////////////////////////////////////////////////////////////
* Project:              Packet Dispenser
* File Name:            PacketDispenser_Code_V1.0.ino
* Version:              1.0
* File Author:          Israel Charles
* Created On:           10/24/2023
* Last Modified On:     10/24/2023
* Modified By:          Israel Charles
* //////////////////////////////////////////////////////////////////////////////////////////////////////

Description:
This is the code for a packet dispenser that uses a digital touch sensor as an action trigger, an LED to 
indicate a press of the touch sensor, a 5-volt servo to push the packets, and a 5-volt motor to move the 
packets away. 
When the touch sensor is triggered, the LED will turn on, the servo will rotate 180 degrees to push 
the packets, and return 180 degrees. Then the gear motor will spin for 10 seconds before it stops. A 
cycle is composed of the actions that start at the touch sensor trigger to the end of the gear motor 
spinning period. A cycle is to be repeated each time the button is pressed

*////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <Servo.h>                          // Importing the servo library

const int touchSensorPin = 7;               // Touch Sensor is connected to Pin 7
const int servoPin = 9;                     // Servo is connected to Pin 9
const int motorPin = 12;                    // Motor is connected to Pin 12
const int ledPin = 11;                      // Led is connected to Pin 11

int touchSensorState;                       // Variable to hold values read from the Touch Sensor

Servo myServo;                              // Creating a Servo object called myServo

void setup() {
  pinMode(touchSensorPin, INPUT);           // Configuring Touch Sensor pin as an Input
  pinMode(motorPin, OUTPUT);                // Configuring Gear Motor pin as an Output
  pinMode(ledPin, OUTPUT);                  // Configuring LED pin as an Output
  myServo.attach(servoPin);                 // Configuring the pin that will send instructions to Servo
  myServo.write(0);                         // Set the servo to the initial position (0 degree)
}

/** Infinite Loop that runs until unplugged or turned off **/
void loop() {

  // Assigning current state of sensor to variable
  touchSensorState = digitalRead(touchSensorPin);

  // Actions when touch sensor is triggered
  if (touchSensorState == HIGH) { 
    digitalWrite(ledPin, HIGH);             // Turn on the LED
    myServo.write(180);                     // Move the servo to 180 degrees
    delay(1000);                            // Wait for 1 second (1000 milliseconds)
    myServo.write(0);                       // Return the servo to its initial position (90 degrees)
    delay(500);                             // Wait for 1 second (500 milliseconds)
    digitalWrite(motorPin, HIGH);           // Start the gear motor
    delay(10000);                           // Run the motor for 10 seconds (10000 milliseconds)
    digitalWrite(motorPin, LOW);            // Stop the gear motor
    digitalWrite(ledPin, LOW);              // Turn off the LED
  }
}
