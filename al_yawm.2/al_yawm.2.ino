int x;

void setup() {
  pinMode(3,OUTPUT);
}

void loop() {
  x=analogRead(A0);
  map(x,0,1024,0,255);
  constrain(x,0,255);
  analogWrite(3,x);
}
