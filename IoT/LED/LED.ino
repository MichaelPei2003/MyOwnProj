int ledState = LOW;
unsigned long previousMillis = 0;
long interval = 1000;

void setup(){
  pinMode(GREEN_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
}

void allBlink() {
  int cnt = 0;
  previousMillis = 0;
  while(cnt < 3) {
    unsigned long currentMillis = millis();
    if((currentMillis - previousMillis) > interval) {
      previousMillis = currentMillis;
      if(ledState==LOW) {
        ledState = HIGH;
      }
      else {
        ledState = LOW;
        cnt++;
      }
      digitalWrite(GREEN_LED, ledState);
      digitalWrite(YELLOW_LED, ledState);
      digitalWrite(RED_LED, ledState);
    }
  }
}

void marquee() {
  previousMillis = 0;
  int cnt = 0;
  while(cnt < 4) {
    digitalWrite(RED_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    
    previousMillis = millis();
    while((millis() - previousMillis) < 1000);
    digitalWrite(GREEN_LED, LOW);
    digitalWrite(YELLOW_LED, HIGH);
    
    previousMillis = millis();
    while((millis() - previousMillis) < 1000);
    digitalWrite(YELLOW_LED, LOW);
    digitalWrite(RED_LED, HIGH);
    
    previousMillis = millis();
    while((millis() - previousMillis) < 1000);
    cnt++;
  }
  digitalWrite(RED_LED, LOW);
}

void loop(){
  allBlink();
  previousMillis = millis();
  while((millis() - previousMillis) < 1000);
  marquee();
  
  previousMillis = millis();
  while((millis() - previousMillis) < 1000);
  allBlink();
  
  digitalWrite(RED_LED, LOW);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  previousMillis = millis();
  while((millis() - previousMillis) < 2000);
}
