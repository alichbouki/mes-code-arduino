int Trig_Pin=9,Echo_Pin=10;
long x_Value;
int Analog_Value;

int Order;

void setup() {
  Serial.begin(9600);
  
  pinMode(Trig_Pin,OUTPUT);
  pinMode(Echo_Pin,INPUT);

  for (int i=4;i<8;i++){
    pinMode(i,OUTPUT);
  }
  for (int i=4;i<8;i++){
    digitalWrite(i,LOW); 
  }
}

void loop() {
  while (Serial.available()==0){}
  
  Order=Serial.parseInt();

  if (Order==1){
    Serial.println("help:");
    Serial.println("1 --> help");
    Serial.println("2 --> up");
    Serial.println("3 --> don");
    Serial.println("4 --> right");
    Serial.println("5 --> left");
    Serial.println("6 --> stop");
    Serial.println("7 --> scan");
  }
  
  else if (Order==2){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    Serial.println("ok");
  }
  
  else if (Order==3){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    Serial.println("ok");
  }
  
  else if (Order==4){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    Serial.println("ok");
  }
  
  else if (Order==5){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    Serial.println("ok");
  }
  
  else if (Order==6){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    Serial.println("ok");
  }
  
  else if (Order==7){
    Analog_Value=analogRead(A0);
    digitalWrite(Trig_Pin,LOW);    
    delay(2);
    digitalWrite(Trig_Pin,HIGH);
    delayMicroseconds(2);
    digitalWrite(Trig_Pin,LOW);
    x_Value=pulseIn(Echo_Pin,HIGH);
    Serial.println(x_Value);
  }

  else if (Order>7){
    Serial.println("unknown command");
  }
}
