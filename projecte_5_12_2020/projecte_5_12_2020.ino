int x,sw=8;

void setup() {
  Serial.begin(9600);
  for (int i = 2; i < 8; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(sw,INPUT_PULLUP);
}

void loop() {
  x=digitalRead(sw);

  if (x==1){}

  else if (x==0){
    ismail(x);
  }
}

void ismail (int x) {
  for (int x = random(2, 8); x < 8; x++) {
    digitalWrite(x, HIGH);
    delay(100);
    digitalWrite(x, LOW);
  }
}
