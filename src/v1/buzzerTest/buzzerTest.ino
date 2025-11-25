int buzzer = 4;

void setup() {
  Serial.begin(9600);
  
  // Set the buzzer pin as an output
  pinMode(buzzer, OUTPUT);
  Serial.println("Buzzer Test: Toggling ON/OFF");
}

void loop() {
  Serial.println("Buzzer ON");
  digitalWrite(buzzer, HIGH); // Turn buzzer ON
  delay(1000);                // Wait 1 second

  Serial.println("Buzzer OFF");
  digitalWrite(buzzer, LOW);  // Turn buzzer OFF
  delay(1000);                // Wait 1 second
}