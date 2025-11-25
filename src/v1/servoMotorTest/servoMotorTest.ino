#include <Servo.h> 

Servo myservo; // Create servo object
int servoPin = 10;

void setup() {
  Serial.begin(9600);
  myservo.attach(servoPin);
  Serial.println("Servo Test: Sweeping 0 -> 90 -> 180");
}

void loop() {
  Serial.println("Moving to 0 degrees");
  myservo.write(0);    // Tell servo to go to 0 degrees
  delay(1000);         // Wait 1 second

  Serial.println("Moving to 90 degrees");
  myservo.write(90);   // Tell servo to go to 90 degrees
  delay(1000);         // Wait 1 second

  Serial.println("Moving to 180 degrees");
  myservo.write(180);  // Tell servo to go to 180 degrees
  delay(1000);         // Wait 1 second
}