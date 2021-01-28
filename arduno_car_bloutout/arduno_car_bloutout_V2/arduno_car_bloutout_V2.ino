int Trig_Pin=9,Echo_Pin=10;
long x_Value;
int Analog_Value;

char Order;

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

  if (Order==63){
    Serial.println("help:");
    Serial.println("? --> help");
    Serial.println("U --> up");
    Serial.println("D --> don");
    Serial.println("R --> right");
    Serial.println("L --> left");
    Serial.println("S --> stop");
    Serial.println("s --> scan");
  }
  
  else if (Order==85){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    Serial.println("ok");
  }
  
  else if (Order==68){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    Serial.println("ok");
  }
  
  else if (Order==82){
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    Serial.println("ok");
  }
  
  else if (Order==76){
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    Serial.println("ok");
  }
  
  else if (Order==83){
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    Serial.println("ok");
  }
  
  else if (Order==115){
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
