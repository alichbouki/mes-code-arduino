#include <Stepper.h>

int spr = 64 ;

int ledR=9,ledG=8,pizo=10;

int Order;

int code_pin=2007;

Stepper moto (spr,  4, 6 , 5 , 7 );

void setup() {
  moto .setSpeed( 500 );

  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(pizo,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  Serial.println("enter code pin");
  
  while (Serial.available()==0){}
  
  Order=Serial.parseInt();

  if (Order=code_pin){
    moto.step(5*64);
    Serial.println("wellcom");

   label1: while (Serial.available()==0){}

    if (Order=1){
      moto.step(-5*64);
    }

    else {
      goto label1;
    }
  }

  else {
    Serial.println("trie again");
  }
}
