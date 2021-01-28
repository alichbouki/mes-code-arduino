#include <Stepper.h>

int spr = 64 ;

int ledR=7,ledG=6;

int Order;

Stepper moto (spr,  4, 6 , 5 , 7 );

void setup() {
  moto .setSpeed( 500 );

  pinMode(ledR,OUTPUT);
  pinMode(ledG,OUTPUT);
  pinMode(8,INPUT);
  pinMode(9,INPUT);

  Serial.begin(9600);
}

void loop() {
  int val1=digitalRead(8);
  int val2=digitalRead(9);
  
  while (Serial.available()==0){}
  
  Order=Serial.parseInt();

  if (Order=1){
    Serial.println("help:");
    Serial.println("2:open door");
    Serial.println("3:close door");
  }
  if (Order=2){
    if (val1=0){
      digitalWrite(ledR,LOW);
      Blink(ledG);
      
      moto.step(10*spr);
    }

    if (val1=1){
      digitalWrite(ledG,LOW);
      Blink(ledR);
      
      Serial.println("it old redi open");
    }
  }
  else if (Order=3){
    if (val2=0){
      digitalWrite(ledR,LOW);
      Blink(ledG);
      
      moto.step(-10*spr);
    }

    else if (val2=1){
      digitalWrite(ledG,LOW);
      Blink(ledR);
      
      Serial.println("it old redi close");
    }
  }
}

void Blink(int pin){
  for (int i=0;i<3;i++){
    digitalWrite(pin,HIGH);
    delay(50);
    digitalWrite(pin,LOW);
    delay(50);
  }
}
