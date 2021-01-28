unsigned long x;
int trig=6,echo=5;

void setup(){
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT); 
}

void loop(){  
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  x=pulseIn(echo,HIGH);
  Serial.println("\n");
  Serial.println(x);
}
