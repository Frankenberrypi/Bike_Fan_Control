#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

const int servo_pin = 9;
const int red_pin = 2;  // red button
const int blue_pin = 3; // blue button
const int ledPin = 13;

int red_state = 0;
int blue_state = 0;

void setup() {
  myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object

  pinMode(red_pin, INPUT);
  pinMode(blue_pin, INPUT);  

  pinMode(ledPin, OUTPUT);
}

void loop() {
  red_state = digitalRead(red_pin);
  blue_state = digitalRead(blue_pin);

  if(red_state == HIGH){
    digitalWrite(ledPin, HIGH);
  }else{
    digitalWrite(ledPin, LOW);
  }

  if (red_state == HIGH){
    if(pos<180){
      pos += 1;
      myservo.write(pos);
    }
    delay(100);
  }
  if(blue_state == HIGH){
    if(pos > 0){
      pos -=1;
      myservo.write(pos);
    }
    delay(100);
  }
}
