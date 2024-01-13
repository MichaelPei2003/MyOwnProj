#include <Energia.h>
#include <WiFi.h>

char targetSSID[] = "Xperia PRO-I";

int signalStrengthValues[30];

void scanWiFi() {
  Serial.println("Scanning for WiFi networks");
  for(int i = 0; i < 30;) {
  int numNetworks = WiFi.scanNetworks();
  delay(100);
  for (int j = 0; j < numNetworks; j++) {
    if (strcmp(WiFi.SSID(j), targetSSID) == 0) {
      signalStrengthValues[i] = WiFi.RSSI(j);
      Serial.print(", Signal Strength: ");
      Serial.println(signalStrengthValues[i]);
      i++;
      }
    }
  }
  delay(1000);
}
void setup() {
  // 初始化串口通信
  Serial.begin(115200);

  scanWiFi();

  int sum = 0;

  for (int i = 0; i < 30; i++) {
    sum += signalStrengthValues[i];
  }

  int average = sum / 30;

  Serial.print("Average Signal Strength for WiFi ");
  Serial.print(targetSSID);
  Serial.print(": ");
  Serial.println(average);
}

void loop() {
 
 }
