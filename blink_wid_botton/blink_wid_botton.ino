int B=7,led=3;
int x;
int Doff=1000,Don=250;

void setup() {
  pinMode(B,INPUT_PULLUP);
  pinMode(led,OUTPUT);
}

void loop() {
  x=digitalRead(B);
  if (x==1){
    digitalWrite(led,HIGH);
    delay(Doff);
    digitalWrite(led,LOW);
    delay(Doff);
  }
  else if (x==0){
    digitalWrite(led,HIGH);
    delay(Don);
    digitalWrite(led,LOW);
    delay(Don);
  }
}
