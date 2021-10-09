void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  pinMode(13, OUTPUT);
}

void ledblink(int ms = 500) {
    digitalWrite(13, HIGH);
    delay(ms);          
    digitalWrite(13, LOW);
    delay(ms);
}

int hold() {
  bool inloop = true;
  while(inloop) {
    if (Serial.available()) {
      int incomingByte = Serial.read();
      Serial.println(incomingByte, DEC);
      return incomingByte;
}
}
}

int holdspecific(int value) {
  while (true) {
  int tv = hold();
  if (tv == value) {
    return true;
  } else {
    int a = 0;
  }
}
}

void loop() {
  int incomingByte;
  holdspecific(66);
  ledblink(); ledblink(); ledblink();
}
