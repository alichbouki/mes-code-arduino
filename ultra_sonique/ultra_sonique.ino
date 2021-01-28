unsigned long x;    
int trig=6,echo=5,sp=11;

void setup(){
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(sp,OUTPUT);
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
  if (x<500){tone(sp,1500,50);delay(100);}
  else if (x<1000){tone(sp,1000,100);delay(200);}
  else if (x<1500){tone(sp,950,150);delay(300);}
  else if (x<2000){tone(sp,900,200);delay(400);}
  else if (x<2500){tone(sp,850,250);delay(500);}
  else if (x<3000){tone(sp,800,300);delay(600);}  
  else if (x<3500){tone(sp,750,350);delay(900);}
  else if (x<4000){tone(sp,700,400);delay(800);}
}
