#include <Servo.h>
Servo moto;
int x,a;
bool y;

void setup() {
  pinMode(3,INPUT_PULLUP);
}

void loop() {
  x=analogRead(A0);
  a=digitalRead(3);
  if (a==1){y=0;}
  else if(a==0){y=1;}
  if (y==1){
    moto.attach(6);
  }
  else if (y==0){
    moto.attach(7);
  }
  x=map(x,0,1023,15,170);
  moto.write(x);
  
}
