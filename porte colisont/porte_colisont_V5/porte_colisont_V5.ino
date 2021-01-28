#include <Stepper.h>

int spr = 64 ;

unsigned long x;    
int trig=3,echo=2;

Stepper moto (spr,  4, 6 , 5 , 7 );

void setup() {
  moto .setSpeed( 500 );

  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

void loop() {
  digitalWrite(trig,LOW);
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  x=pulseIn(echo,HIGH);
  
  if (x<500){
    moto.step(10*spr);
  }

  else if (x>500){
    moto.step(-10*spr);
  }
}
