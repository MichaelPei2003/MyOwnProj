int state = 0;
int ledState = LOW;
unsigned long previousMillis = 0;
unsigned long currentMillis = 0;
long interval = 1000;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(YELLOW_LED, OUTPUT);
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
  digitalWrite(RED_LED, LOW);
  pinMode(PUSH2, INPUT_PULLUP);
  attachInterrupt(PUSH2, blink, RISING);
  currentMillis = millis();
  previousMillis = millis();
}

void allBlink() {
  int cnt = 0;
  if((currentMillis - previousMillis) > interval) {
    previousMillis = currentMillis;
    if(ledState==LOW)
      ledState = HIGH;
    else
      ledState = LOW;
    digitalWrite(GREEN_LED, ledState);
    digitalWrite(YELLOW_LED, ledState);
    digitalWrite(RED_LED, ledState);
  }
  currentMillis = millis();
}

void marquee() {
  previousMillis = 0;
  
  digitalWrite(RED_LED, LOW);
  digitalWrite(YELLOW_LED, LOW);
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

  digitalWrite(RED_LED, LOW);
}

void loop() {
  if(state == 1)
    marquee();
  else
    allBlink();
}

void blink() {
  delay(20);
  if(state == 1) {
    state = 0;
  }
  else {
    state = 1;
  }
}
