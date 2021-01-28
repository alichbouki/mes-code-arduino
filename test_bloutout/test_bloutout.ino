int d;

void setup() {
  pinMode(3,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  while(Serial.available()==0){}
  d=Serial.parseInt();

  if (d==1){digitalWrite(2,HIGH);}
  else if (d==2){digitalWrite(4,HIGH);}
  else if (d==3){digitalWrite(3,HIGH);}
  else if (d==4){
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
  }
  else if (d==5){
    digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
  }
}
