int x;

void setup() {
  pinMode(3,INPUT_PULLUP);
  pinMode(13,OUTPUT);
}

void loop() {
  x=digitalRead(3);
  if (x==0){
    digitalWrite(13,1);
    delay(1000);
    digitalWrite(13,0);
    delay(1000);
  }
  else if (x==1){
    digitalWrite(13,1);
    delay(2000);
    digitalWrite(13,0);
    delay(2000);
  }
}
