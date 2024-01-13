#include <Energia.h>
#include <WiFi.h>

char ssid[] = "Xperia PRO-I";
char pass[] = "qazwsxedc";

int signalStrengthValues[30];

void setup() {
  Serial.begin(115200);

  connectToWiFi();

  for (int i = 0; i < 30; i++) {
    signalStrengthValues[i] = WiFi.RSSI();
    delay(1000);
  }

  int minValue = signalStrengthValues[0];
  int maxValue = signalStrengthValues[0];
  int sum = signalStrengthValues[0];

  for (int i = 1; i < 30; i++) {
    if (signalStrengthValues[i] < minValue) {
      minValue = signalStrengthValues[i];
    }
    if (signalStrengthValues[i] > maxValue) {
      maxValue = signalStrengthValues[i];
    }
    sum += signalStrengthValues[i];
  }
  int average = (sum - minValue - maxValue) / 28;
  Serial.print("Average Signal Strength: ");
  Serial.print(average);
  Serial.println("dBm");
}

void loop() {

}

void connectToWiFi() {
  Serial.println("Connecting to WiFi");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi");
}
