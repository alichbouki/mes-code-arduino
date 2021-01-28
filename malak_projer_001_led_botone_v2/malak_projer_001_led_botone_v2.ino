

void setup() {
  for (int i=0;i<20;i++){
    pinMode(i,OUTPUT);
  }
  pinMode(22,INPUT);
  pinMode(23,INPUT);
}

void loop() {
  int swOn=digitalRead(22);
  int swOff=digitalRead(23);
  if (swOn==1 && swOff==0){
    for (int x1=0;x1<20;x1++){
      digitalWrite(x1,HIGH);
      delay(100);
    }
  }
  else if (swOn==0 && swOff==1){
    for (int x1=0;x1<20;x1++){
      digitalWrite(x1,LOW);
      delay(100);
    }
  }
}
