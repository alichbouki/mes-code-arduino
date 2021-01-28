void setup() {
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);

  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);

  delay(3000);

  digitalWrite(2,LOW);
  digitalWrite(3,LOW);

  delay(1000);

  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);

  delay(3000);

  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
}

void loop() {}
