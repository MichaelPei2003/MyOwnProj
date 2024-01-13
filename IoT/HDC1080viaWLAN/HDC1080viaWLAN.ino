#include <WiFi.h>
#include <Wire.h>

// WiFi网络凭据
char ssid[] = "PXY";
char password[] = "qazwsxedc";
int keyIndex = 0;

WiFiServer server(80);

// HDC1080传感器定义
#define HDC1080_ADDRESS 0x40
#define REG_TEMPERATURE 0x00
#define REG_HUMIDITY 0x01
#define REG_CONFIGURATION 0x02
#define NORMAL_OPERATION 0x0000

void write(uint8_t regAddress, uint8_t *pdata, uint8_t length) {
    Wire.beginTransmission(HDC1080_ADDRESS);
    Wire.write(regAddress);
    Wire.write(pdata, length);
    Wire.endTransmission();
}

uint16_t read(uint8_t regAddress) {
    uint16_t data = 0;
    Wire.beginTransmission(HDC1080_ADDRESS);
    Wire.write(regAddress);
    Wire.endTransmission();
    delay(40);
    Wire.requestFrom(HDC1080_ADDRESS, 2);
    if (Wire.available() >= 2) {
        data = Wire.read() << 8;
        data |= Wire.read();
    }
    return data;
}

void hdc1080_init() {
    Wire.begin();
    uint8_t data[2] = {0x00, 0x00};
    data[0] = (NORMAL_OPERATION >> 8) & 0xFF;
    data[1] = NORMAL_OPERATION & 0xFF;
    write(REG_CONFIGURATION, data, 2);
}

float hdc1080_getTemperature() {
    uint16_t temperature = read(REG_TEMPERATURE);
    return (temperature / 65536.0) * 165.0 - 40.0;
}

float hdc1080_getHumidity() {
    uint16_t humidity = read(REG_HUMIDITY);
    return (humidity / 65536.0) * 100.0;
}

void printWifiStatus() {
    Serial.print("网络名称：");
    Serial.println(WiFi.SSID());
    IPAddress ip = WiFi.localIP();
    Serial.print("IP地址：");
    Serial.println(ip);
    long rssi = WiFi.RSSI();
    Serial.print("信号强度（RSSI）:");
    Serial.print(rssi);
    Serial.println(" dBm");
}

void setup() {
    Serial.begin(115200);

    Serial.print("尝试连接到网络: ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        Serial.print(".");
        delay(300);
    }

    Serial.println("\n已连接到网络");
    Serial.println("等待获取IP地址");

    while (WiFi.localIP() == INADDR_NONE) {
        Serial.print(".");
        delay(300);
    }

    printWifiStatus();

    Serial.println("在端口80上启动Web服务器");
    server.begin();
    Serial.println("Web服务器已启动！");
    hdc1080_init();
}

void loop() {
    WiFiClient client = server.available();
    if (client) {
        Serial.println("新的客户端");
        boolean currentLineIsBlank = true;
        while (client.connected()) {
            if (client.available()) {
                char c = client.read();
                Serial.write(c);

                if (c == '\n' && currentLineIsBlank) {
                    client.println("HTTP/1.1 200 OK");
                    client.println("Content-Type: text/html");
                    client.println("Connection: close");
                    client.println("Refresh: 5");
                    client.println();
                    client.println("<!DOCTYPE HTML>");
                    client.println("<html>");
                    client.print("Temperature:");
                    client.print(hdc1080_getTemperature());
                    client.println("<br />");
                    client.print("Humidity:");
                    client.print(hdc1080_getHumidity());
                    client.println("<br />");
                    client.println("</html>");
                    break;
                }

                if (c == '\n') {
                    currentLineIsBlank = true;
                } else if (c != '\r') {
                    currentLineIsBlank = false;
                }
            }
        }
        delay(5);
        client.stop();
        Serial.println("客户端断开连接");
    }
}
