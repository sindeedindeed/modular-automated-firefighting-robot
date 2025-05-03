#define FLAME_SENSOR A1   // Flame sensor (Digital pin 3)
#define GAS_SENSOR A0    // Gas sensor (Analog pin A0)

void setup() {
  Serial.begin(9600);
  pinMode(FLAME_SENSOR, INPUT);
  pinMode(GAS_SENSOR, INPUT);
}

void loop() {
  // Read flame sensor
  int flameValue = analogRead(FLAME_SENSOR);
  
  // Read gas sensor
  int gasValue = analogRead(GAS_SENSOR);
  
  // Print sensor readings
  Serial.print("Flame Sensor: ");
  Serial.print(flameValue);
  Serial.print(", Gas Sensor: ");
  Serial.println(gasValue);
  
  delay(3000); // Adjust delay as needed
}
