const int16_t minTemperature = -50;
const int16_t maxTemperature = 150;
const int temperaturePin = A1;
float calctemperature(uint16_t sample);

void setup() {
  Serial.begin(115200);
}

void loop() {
  uint16_t value = analogRead(temperaturePin);
  Serial.print("temperature = ");
  Serial.println(calcTemperature(value));
  delay(1000);
}

float calcTemperature(uint16_t sample) {
  uint16_t voltage = map(sample, 0, 4095, 0, 1460);
  float temperature = 0.0;
  temperature = (5.506 - sqrt(pow(-5.506, 2) + 4 * 0.00176*(870.6 - voltage)))/(2*(-0.00176)) + 30.0;
  if(temperature > maxTemperature) {
    return maxTemperature;
  }
  else if(temperature < minTemperature) {
    return minTemperature;
  }
  else {
    return temperature;
  }
}
