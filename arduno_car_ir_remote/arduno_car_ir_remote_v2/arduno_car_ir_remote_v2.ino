#include <IRremote.h>

IRrecv rec(4);               
decode_results res;

//************************//

int trig=3,echo=2;
long x;
int droit1=6,droit2=7,gauch1=8,gauch2=9;
int lup=12,ldo=11,br=10;
bool p;
int v;

//************************//

void setup() {
  Serial.begin(9600);
  pinMode(gauch1, OUTPUT);      
  pinMode(gauch2, OUTPUT);
  pinMode(droit2, OUTPUT);
  pinMode(droit1, OUTPUT); 
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(lup,OUTPUT);
  pinMode(ldo,OUTPUT);
  pinMode(br,OUTPUT);
  rec.enableIRIn();
}

//************************//

void loop() {
  v=analogRead(A0);
  digitalWrite(trig,LOW);    
  delay(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(2);
  digitalWrite(trig,LOW);
  x=pulseIn(echo,HIGH);
  if (x<1000) {
    stope(droit2, droit1);stope(gauch1, gauch2);
    p=1;
  } 
  if (rec.decode(&res)) {
    if (res.value == 0xFD609F) {up(droit2, droit1);up(gauch1, gauch2);p=0;}
    if (res.value == 0xFD5AA5) {up(droit2, droit1);stope(gauch1, gauch2);p=0;}          
    if (res.value == 0xFDD827) {up(gauch1, gauch2);stope(droit2, droit1);p=0;}   
    if (res.value == 0xFD6897) {down(droit2, droit1);down(gauch1, gauch2);p=0;}
    if (res.value == 0xFD58A7) {stope(droit2, droit1);stope(gauch1, gauch2);p=1;} 
    if (res.value == 0xFD4AB5){digitalWrite(lup,HIGH);digitalWrite(ldo,HIGH);}
    if (res.value == 0xFD0AF5){digitalWrite(lup,HIGH);digitalWrite(ldo,LOW);}
    if (res.value == 0xFD08F7){digitalWrite(lup,LOW);digitalWrite(ldo,HIGH);}
    if (res.value == 0xFD6A95){digitalWrite(lup,LOW);digitalWrite(ldo,LOW);}
    Serial.println(res.value, HEX);
    rec.resume();
  }
  if (p==0){digitalWrite(br,LOW);}
  else if (p==1){digitalWrite(br,HIGH);}
}

//************************//

void up(int out1, int out2){
  digitalWrite(out1, HIGH);
  digitalWrite(out2, LOW);
}

void down(int out1, int out2) { 
  digitalWrite(out1, LOW);
  digitalWrite(out2, HIGH);
}

void stope(int out1, int out2) {
  digitalWrite(out1, LOW);
  digitalWrite(out2, LOW);
}
