#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 90;    // variable to store the servo position

const int servo_pin = 9;
const int green_pin = 2;  // red button
const int blue_pin = 3; // blue button
const int ledPin = 13;

int green_state = 0;
int blue_state = 0;

void setup() {
  myservo.attach(servo_pin);  // attaches the servo on pin 9 to the servo object

  pinMode(green_pin, INPUT_PULLUP);
  pinMode(blue_pin, INPUT_PULLUP);  

}

void loop() {
  green_state = digitalRead(green_pin);
  blue_state = digitalRead(blue_pin);

  if (green_state == LOW){
    if(pos<180){
      pos += 2;
      myservo.write(pos);
    }
    delay(15);
  }
  if(blue_state == LOW){
    if(pos > 6){
      pos -= 2;
      myservo.write(pos);
    }
    delay(15);
  }
}
