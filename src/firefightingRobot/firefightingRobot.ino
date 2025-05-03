#include <Servo.h>
#include <SoftwareSerial.h>   
#include <AFMotor.h>          

Servo myservo;
 
int pos = 0;    
boolean fire = false;

const String PHONE = "+8801704960672"; 

#define rxPin 2
#define txPin 3 
SoftwareSerial sim800L(rxPin, txPin);
#define Forward 6       
#define GAS_SENSOR A0 
#define pump 7  

AF_DCMotor leftMotor1(1); 
AF_DCMotor leftMotor2(2); 
AF_DCMotor rightMotor1(3); 
AF_DCMotor rightMotor2(4); 

void setup()
{
  Serial.begin(9600);
  sim800L.begin(9600);

  sim800L.println("AT");
  delay(1000);
  sim800L.println("AT+CMGF=1");
  delay(1000);
  
  pinMode(Forward, INPUT);
  pinMode(GAS_SENSOR, INPUT);
  pinMode(pump, OUTPUT);

  myservo.attach(10);
  myservo.write(90); 
  
  while (sim800L.available()) {
    Serial.println(sim800L.readString());
  }
}

void put_off_fire()
{
  digitalWrite(pump,HIGH);
  for (pos = 50; pos <= 110; pos += 1) { 
    myservo.write(pos); 
    delay(10);  
  }
  delay(1000); 
  for (pos = 110; pos >= 50; pos -= 1) { 
    myservo.write(pos); 
    delay(10);
  }
  delay(1000); 
  myservo.write(90);
  digitalWrite(pump,LOW);
}

void loop()
{
  myservo.write(90); 
  if (digitalRead(Forward) == 0) 
  {
    delay(500);
    setMotorsSpeed(255, FORWARD);
    delay(2000);
    stopMotors();
    fire = true;
    put_off_fire();
  }
  else if(digitalRead(Forward)==1){
    stopMotors();
  }
  delay(400); 
  
  int gasValue = analogRead(GAS_SENSOR);
  if (gasValue > 70) 
  {
    Serial.println("Gas is Detected.");
    send_sms(); 
  }
}

void make_call()
{
  Serial.println("calling....");
  sim800L.println("ATD" + PHONE + ";");
  delay(500); // 20 sec delay
  sim800L.println("ATH");
  delay(1000); // 1 sec delay
}

void send_sms()
{
  Serial.println("sending sms....");
  delay(50);
  sim800L.print("AT+CMGF=1\r");
  delay(1000);
  sim800L.print("AT+CMGS=\"" + PHONE + "\"\r");
  delay(1000);
  sim800L.print("Gas Detected");
  delay(100);
  sim800L.write(0x1A);
  delay(5000);
}

void setMotorsSpeed(int speed, int direction)
{
  leftMotor1.setSpeed(speed);
  leftMotor2.setSpeed(speed);
  rightMotor1.setSpeed(speed);
  rightMotor2.setSpeed(speed);
  
  leftMotor1.run(direction);
  leftMotor2.run(direction);
  rightMotor1.run(direction);
  rightMotor2.run(direction);
}

void stopMotors()
{
  leftMotor1.run(RELEASE);
  leftMotor2.run(RELEASE);
  rightMotor1.run(RELEASE);
  rightMotor2.run(RELEASE);
}