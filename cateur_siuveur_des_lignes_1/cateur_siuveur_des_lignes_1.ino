int g=8,r=7;

void setup() {
  Serial.begin(9600);
  pinMode(3,INPUT);
  pinMode(11,OUTPUT);
  pinMode(g,OUTPUT);
  pinMode(r,OUTPUT);
}

void loop() {
  int x=digitalRead(3);
  int y=analogRead(A0);
  if (x==1){
    digitalWrite(r,1);
    delay(1000);
    digitalWrite(r,0);
    tone(11,y,1000);
    delay(1000);
  }
  else if (x==0){
    digitalWrite(g,1);
    delay(1000);
    digitalWrite(g,0);
    delay(1000);
  }
  Serial.println(y);
}
