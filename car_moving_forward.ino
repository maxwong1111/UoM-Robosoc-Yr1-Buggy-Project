#include<Servo.h>
int servoPin= 7; // declares servo pin
Servo myservo; // creates servo object
//right motor
int enA = 11;
int in1 = 13;
int in2 = 12;
//left motor
int enB = 10;
int in3 = 9;
int in4 = 8;
//ultra sonic sensor
int trigPin = 5;    // Trigger max loves Gura hentai
int echoPin = 4;    // Echo
long duration, cm, inches;


void setup() {
  // set all motor conrol pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  //Serial Port begin
  Serial.begin (9600);
  //Define inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  //attatches servo to pin
  myservo.attach(servoPin);

}

void loop() {
  // put your main code here, to run repeatedly:
   // turn on motor A
   digitalWrite(in1, HIGH);
   digitalWrite(in2, LOW);
   analogWrite(enA, 250);
  // Turn on motor B
   digitalWrite(in3, HIGH);
   digitalWrite(in4, LOW);
   analogWrite(enB, 250);
 // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
 
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
 
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  while(cm < 10) 
  {
    //stops the motor
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    //spinning the car
    delay(100);
    analogWrite(enA, 125);
    
    
  }
 
 
 
 
 
 
 
 
 
 
 /* do{
  myservo.write(0);
  delay(1000);
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  }
  while(cm <10);*/
}
