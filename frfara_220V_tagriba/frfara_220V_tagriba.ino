int d;

void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()==0){}
  d=Serial.parseInt();

  if (d==1){digitalWrite(2,HIGH);}
  else if (d==0){digitalWrite(2,LOW);}
}
