String inputString = "";
boolean stringComplete = false;

void setup() {
  Serial.begin(115200);
  inputString.reserve(200);
}

void serialEvent() {
  while(Serial.available() {
    char inChar = (char)Serial.read();
    inputString += inChar;
    if(inChar == '\n') {
      stringComplete = true;
    }
  }
}

void loop() {
  if(stringComplete) {
    Serial.println(inputString);
    inputString = "";
    stringComplete = false;
  }
}
