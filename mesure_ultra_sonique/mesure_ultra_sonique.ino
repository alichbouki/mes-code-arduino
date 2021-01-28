unsigned long du;    
int trig=3,echo=2,x;

void setup(){
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);
}

void loop(){  
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  x=pulseIn(echo,HIGH);
  x=x/60;
  x=x/340;
  Serial.print(x);
  Serial.println(" cm");
  delay(500);
}
