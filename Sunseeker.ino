/*
 * Sunseeker: A sketch that uses the values of two photocells to
 * determine the direction of light and control a servo to move
 * in the corresponding direction.
 * 
 * 14.04.2020 by pgroon
 */

int leftEye = A10;
int rightEye = A11;
double valueLeft;
double valueRight;

void setup() {
  // Initialize photocells
  pinMode(leftEye,  INPUT);
  pinMode(rightEye, INPUT);

  // Initialize serial monitor
  Serial.begin(9600);
}

void loop() {
  valueLeft   = analogRead(leftEye);
  valueRight  = analogRead(rightEye);
 
  Serial.print("leftEye: ");
  Serial.println(valueLeft);
  Serial.print("rightEye: ");
  Serial.println(valueRight);
  Serial.print("Ratio: ");
  Serial.println(valueLeft/valueRight);
  
  delay(1500);
}
