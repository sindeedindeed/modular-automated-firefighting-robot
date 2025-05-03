#include <AFMotor.h>

// Initial motors pin
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600);
  
  Serial.println("Setting motor speeds...");
  motor1.setSpeed(255);
  motor2.setSpeed(255);
  motor3.setSpeed(255);
  motor4.setSpeed(255);
  Serial.println("Motor speeds set to 255.");

  Serial.println("Running motors forward...");
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);
  Serial.println("Motors are running forward.");
}

void loop() {
  // Loop does nothing, motors should keep running forward
}
