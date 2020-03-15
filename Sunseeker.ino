/*
 * Sunseeker: A sketch that uses the values of two photocells to
 * determine the direction of light and control a servo to move
 * in the corresponding direction.
 * 
 * 14.04.2020 by pgroon
 */

#include <Servo.h>

Servo myservo;
int leftEye = A0;
int rightEye = A1;
int pos = 90;   // Servo position
double valueLeft;
double valueRight;
double ratioLR;

void setup() {
  // Initialize photocells
  pinMode(leftEye,  INPUT);
  pinMode(rightEye, INPUT);

  // Initialize serial monitor
  Serial.begin(9600);

  // Initialize Servo
  myservo.attach(52);
}

void loop() {
  valueLeft   = analogRead(leftEye);
  valueRight  = analogRead(rightEye);
 
  //Serial.print("leftEye: ");
  //Serial.println(valueLeft);
  //Serial.print("rightEye: ");
  //Serial.println(valueRight);
  
  ratioLR = valueLeft/valueRight;
  Serial.print("Ratio: ");
  Serial.println(ratioLR);

  if (ratioLR <= 1.0) {
    pos--;
  } else if (ratioLR >= 1.2) {
    pos++;
  }
  delay(50);
  myservo.write(pos);
}
