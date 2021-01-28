int rv,bv,gv;

void setup() {for(int i=9;i<12;i++){pinMode(i,OUTPUT);}}

void loop() {
  rv=random(0,256);
  bv=random(0,256);
  gv=random(0,256);
  analogWrite(11,rv);
  analogWrite(10,gv);
  analogWrite(9,bv);
  delay(1000);
  Blink();
}

void Blink( ){
  digitalWrite(11,LOW);
  digitalWrite(10,LOW);
  digitalWrite(9,LOW);
  delay(1000);
  for (int i; i<4; i++){
    analogWrite(11,rv);
    analogWrite(10,gv);
    analogWrite(9,bv);
    delay(1000);
    digitalWrite(11,LOW);
    digitalWrite(10,LOW);
    digitalWrite(9,LOW);
    delay(1000);
  }
}
