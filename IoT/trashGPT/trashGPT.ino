#include <Servo.h>

#include "hcrs04.h"

#define PINTRIG 19  // P18
#define PINECHO 18  // P08
#define ADDRESS 0x40
// temperature init
const int16_t minTemperature = -50;
const int16_t maxTemperature = 150;
const int temperaturePin = A1;

// servo function init
hcrs04 Sensor0(PINTRIG, PINECHO);
Servo servo0;
Servo servo1;
int pos;
int servoMax = 140;
int servoMin = 30;
int in_distance = 0;
int msg_flag = 0;

int openbox = 0;
// const int ledPin1 = GREEN_LED;   // 绿色关闭
// const int ledPin2 = YELLOW_LED;  // 黄色打开
const int buttonPin = PUSH1;
volatile bool state = LOW;

void setup() {
    Serial1.begin(115200);
    Serial.begin(115200);
    servo0.attach(5);   // P61
    servo1.attach(30);  // P50
    servo1.write(147);
    servo0.write(27);
    Sensor0.begin();
    // pinMode(ledPin1, OUTPUT);
    // pinMode(ledPin2, OUTPUT);
    // pinMode(RED_LED, OUTPUT);
    // digitalWrite(ledPin1, !state);
    // digitalWrite(ledPin2, state);
    pinMode(buttonPin, INPUT_PULLUP);
    attachInterrupt(buttonPin, forceOpen, RISING);
}

void Open(int flag0, int flag1) {
    if (flag1 == 1) {
        servo0.write(servoMax - 3);
    }
    if (flag0 == 1) {
        servo1.write(servoMin + 12);
    }
}

void Close() {
    servo0.write(servoMin - 3);
    servo1.write(servoMax + 7);
}

void forceOpen() {
    state = !state;
    // digitalWrite(ledPin1, !state);
    // digitalWrite(ledPin2, state);
    if (openbox) {
        Close();
        openbox = 0;
    } else {
        Open(1, 1);
        openbox = 1;
    }
    delay(200);
}

// API for sonic rangefinder
float get_distance() {
    float distance = Sensor0.read();
    return distance;
}

float get_temperature(uint16_t sample) {
    uint16_t voltage = map(sample, 0, 4095, 0, 1460);
    float temperature = 0.0;
    temperature = (5.506 - sqrt(pow(-5.506, 2) + 4 * 0.00176 * (870.6 - voltage))) / (2 * (-0.00176)) + 30.0;
    if (temperature > maxTemperature) {
        return maxTemperature;
    } else if (temperature < minTemperature) {
        return minTemperature;
    } else {
        return temperature;
    }
}

void loop() {
    float DISTANCE;
    int msg = 0;
    DISTANCE = get_distance();
    Serial.println(DISTANCE);
    if (DISTANCE < 10) {
        // digitalWrite(RED_LED, HIGH);
        Serial1.println("c");
    }
    if (Serial1.available() > 0) {
        msg = Serial1.read();
        Serial.print(msg);
        if (msg == 114) { //recycle
            Open(1, 0);
            delay(5000);
        } else if (msg == 117) {
            Open(0, 1);
            delay(5000);
        } else if (msg == 116) {  // ascii for 't'
            uint16_t value = analogRead(temperaturePin);
            float temperature = get_temperature(value);
            Serial1.print("t");
            Serial1.println(temperature);
            Serial.print(temperature);
        }
        Close();
    }
    // digitalWrite(RED_LED, LOW);
    delay(500);
    msg = -1;
}
