int rv=230,bv=230,gv=230;

void setup() {
  for(int i=9;i<12;i++){pinMode(i,OUTPUT);}
}

void loop() {
  analogWrite(9,rv);
  analogWrite(10,gv);
  analogWrite(11,bv);
}
