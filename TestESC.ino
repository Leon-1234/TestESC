#include <Servo.h>

Servo M_FR;
Servo M_FL;
Servo M_RR;
Servo M_RL;

// For Motor Pins
int motorFR_Pin = 7; 
int motorFL_Pin = 4; 
int motorRR_Pin = 5; 
int motorRL_Pin = 6;


// Control Variables
int throttle = 0;

void setup() {

  delay(100); // Wait for Sensors to initialize

  Serial.begin(57600);

  M_FR.attach(motorFR_Pin);
  M_FL.attach(motorFL_Pin);
  M_RR.attach(motorRR_Pin);
  M_RL.attach(motorRL_Pin);
  
  delay(100);
    
}

void loop() {

  if(Serial.available()) {
    throttle = Serial.parseInt();
    Serial.println(throttle);
  }
  
  int ang = throttle;
  
  //M_FR.write(ang);
  //M_FL.write(ang);
  //M_RR.write(ang);
  M_RL.write(ang);

  //delay(10); 
}

//To configure ESC first connect power and apply full throttle. A beep will be heard. 
//Turn down to minimum power and new beeps will be heard. This configures the new
//minimum and maximum throttle.

//
