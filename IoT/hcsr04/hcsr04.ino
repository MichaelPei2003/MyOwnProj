#include "hcrs04.h"

//Change thse values to reflect your pin setup.
#define PINTRIG 19
#define PINECHO 18

hcrs04 mySensor(PINTRIG, PINECHO);
 
void setup()
{
  Serial.begin(115200);
  Serial.println("Basic HC-SR04 Ultrasonic Sensor Example");
  mySensor.begin();
}

void loop()
{
  //Get results from the sensor
  float DISTANCE = mySensor.read(); 
  Serial.print(DISTANCE);
  Serial.println(" cm");
  delay(500);
}
