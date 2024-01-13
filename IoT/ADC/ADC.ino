int analogInPin = A3;//A0, A1, A2, A3

void setup() {
  Serial.begin(9600);
}

void loop() {
  int val = analogRead(analogInPin);
  Serial.println(val);
  delay(1000);
}
