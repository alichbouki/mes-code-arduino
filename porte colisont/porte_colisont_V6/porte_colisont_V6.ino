#include <Stepper.h>

int spr = 64 ;
   
int M=3;

Stepper moto (spr,  4, 6 , 5 , 7 );

void setup() {
  moto .setSpeed( 500 );

  pinMode(M,INPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);
}

void loop() {
  int x=digitalRead(M);
  
  if (x<1){
    if (digitalRead(8)==0){
      moto.step(10*spr);
    }
    else if (digitalRead(8)==1){}
  }

  else if (x>0){
    if (digitalRead(9)==0){
      moto.step(-10*spr);
    }
    else if (digitalRead(9)==1){}
  }
}
