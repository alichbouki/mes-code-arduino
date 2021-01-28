int rv,gv,bv;

void setup() {
  for (int i=9;i<11;i++){pinMode(13,OUTPUT);}
}

void loop() {
  rv=analogRead(A0);
  bv=analogRead(A1);
  gv=analogRead(A3);
  map(rv,0,1023,0,233);
  map(bv,0,1023,0,233);
  map(gv,0,1023,0,233);
  analogWrite(9,rv);
  analogWrite(10,gv);
  analogWrite(11,bv);
}
