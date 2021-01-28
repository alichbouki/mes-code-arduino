int x;

void setup() {
  pinMode(11,OUTPUT);
  pinMode(3,INPUT_PULLUP);
  
}

void loop() {
  x=digitalRead(3);
  if (x==0){
    tone(11,500,1000);
    delay(2000);
  }
  else if (x==1){}
}
