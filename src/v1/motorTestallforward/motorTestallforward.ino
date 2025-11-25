// Right Motor
int IN1 = 7;
int IN2 = 8;

// Left Motor
int IN3 = 9;
int IN4 = 10;

void setup() {
  // Set all pins to sends signals out
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  // --- TEST START: Spin Motors ---
  
  // Right Motor Forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  // Left Motor Forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  
  delay(2000); // Wait 2 seconds

  // --- TEST STOP: Stop Motors ---
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  
  delay(2000); // Wait 2 seconds
}