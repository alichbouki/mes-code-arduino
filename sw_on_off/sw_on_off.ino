int v;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(7,INPUT_PULLUP);
}

void loop() {
  v=digitalRead(7);
  if (v==0){
    digitalWrite(3,HIGH);
  }
  else if (v==1){
    digitalWrite(3,LOW);
  }
}
