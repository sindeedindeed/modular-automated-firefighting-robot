// Define sensor pins
int flame_sensor = A1; // Pin 15
int gas_sensor = A0;   // Pin 14
int trigPin = 13;
int echoPin = 12;

int flame_value;
int gas_value;
long duration;
int distance;

void setup() {
  Serial.begin(9600); // Uno typically uses 9600 bps

  pinMode(flame_sensor, INPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  // A0 is analog input by default, no pinMode needed

  Serial.println("Sensor Test Initialized.");
}

void loop() {
  // 1. Read Flame Sensor
  flame_value = digitalRead(flame_sensor);
  Serial.print("Flame: ");
  Serial.print(flame_value); // 1 = No Flame, 0 = Flame

  // 2. Read Gas Sensor
  gas_value = analogRead(gas_sensor);
  Serial.print(" | Gas (0-1023): ");
  Serial.print(gas_value);

  // 3. Read Ultrasonic Sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  Serial.print(" | Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  delay(1000); // Delay for readability
}
