int d;

void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
  Serial.println("bonjour povait-vous me doner le temp de activation(on ms)...");
  while(Serial.available()==0){}
  d=Serial.parseInt();
  Serial.println("merci,voila le blink comme que vous vouler.");
  Serial.println("si vous voulais fair un redemarage apuiser sur le bouton jonne");
}

void loop() {
  digitalWrite(3,HIGH);
  delay(d);
  digitalWrite(3,LOW);
  delay(d);
}
