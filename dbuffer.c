#define sr Serial
int bufferofinps[64];

void setup() {
  sr.begin(9600); // opens sr port, sets data rate to 9600 bps
  pinMode(13, OUTPUT);
  digitalWrite(13,HIGH);
  delay(1000);
  digitalWrite(13,LOW);
  sr.println("Ready.");
  
}

int hold() {
  bool inloop = true;
  while(inloop) {
    if (sr.available()) {
      int incomingByte = sr.read();
      //sr.println(incomingByte, DEC);
      return incomingByte;
}
}
}



void loop() {
  int incomingByte = hold();
  //sr.print("Stage 1: ");
  //sr.print(incomingByte, DEC);

  if (incomingByte == 67) {
    int ticker = 0;
    bool go = true;
    int bufferofinps[64];
    sr.println("Writing all future inputs (until C) to buffer...");
    //sr.println(ic);
    while (go) {
      int icc = hold();
      if (icc != 67) {
      bufferofinps[ticker] = icc;
      ticker++;
      } else {
        go = false;
      }
    }
    sr.println("Buffer: ");
    for (int i=0; i < ticker; i++) {
      sr.println(bufferofinps[i]);
    }
  }
}
