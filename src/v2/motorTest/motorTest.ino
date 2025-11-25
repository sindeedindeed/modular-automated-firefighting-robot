#include <SoftwareSerial.h>

// --- HC-05 Bluetooth Configuration ---
const int bluetoothRxPin = 2; // HC-05 TX → Arduino RX
const int bluetoothTxPin = 3; // HC-05 RX → Arduino TX
SoftwareSerial BTSerial(bluetoothRxPin, bluetoothTxPin);

char command;

// --- Motor Pins ---
const int in1 = 7;
const int in2 = 8;
const int in3 = 9;
const int in4 = 10;

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  Serial.begin(9600);
  Serial.println("Robot Ready (500ms auto movement)");
  Serial.println("Commands: f=forward, b=backward, l=left, r=right, s=stop");

  BTSerial.begin(38400);  // Change to 9600 for data mode later

  stopRobot();
}

// ----- MOVEMENT FUNCTIONS -----

void turnRight() {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("FORWARD");
}

void turnLeft() {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("BACKWARD");
}

void moveForward() {
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("LEFT");
}

void moveBackward() {
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("RIGHT");
}

void stopRobot() {
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
  Serial.println("STOP");
}


void executeMove(void (*movementFunc)()) {
  movementFunc();    // run desired movement
  delay(200);       
  stopRobot();      
}

// ----- MAIN LOOP -----

void loop() {
  if (BTSerial.available()) {
    command = BTSerial.read();

    Serial.print("RAW RECEIVED CHAR: '");
    Serial.print(command);
    Serial.println("'");

    switch (command) {
      case 'f': executeMove(moveForward); break;
      case 'b': executeMove(moveBackward); break;
      case 'l': executeMove(turnLeft); break;
      case 'r': executeMove(turnRight); break;
      case 's': stopRobot(); break;
      default:
        Serial.println("--- Unrecognized Command ---");
        break;
    }
  }

  // Optional Serial → Bluetooth echo
  if (Serial.available()) {
    BTSerial.write(Serial.read());
  }
}
