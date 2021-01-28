

void setup() {
  for (int i=4;i<14;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(2,INPUT);
  pinMode(3,INPUT);
}

void loop() {
  int swOn=digitalRead(2);
  int swOff=digitalRead(3);
  if (swOn==1 && swOff==0){
    for (int x1=4;x1<14;x1++){
      digitalWrite(x1,HIGH);
      delay(100);
    }
  }
  else if (swOn==0 && swOff==1){
    for (int x1=4;x1<14;x1++){
      digitalWrite(x1,LOW);
      delay(100);
    }
  }
}
