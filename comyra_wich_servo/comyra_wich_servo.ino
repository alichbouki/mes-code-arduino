#include <Servo.h>
Servo moto;
int v;
int sw;
int x;

void setup() {
  moto.attach(7);
  Serial.begin(9600);
  pinMode(3,INPUT_PULLUP);
}
void loop() {
  v=analogRead(A0);
  x=analogRead(A5);
  sw=digitalRead(3);
  if (sw==1){
    v=map(v,0,1023,10,170);
    moto.write(v);
    x=map(x,0,1023,30,5000);
  }
  else if (sw==0){
    moto.write(170);
    delay(1000);
    moto.write(160);
    delay(x);
    moto.write(150);
    delay(x);
    moto.write(140);
    delay(x);
    moto.write(130);
    delay(x);
    moto.write(120);
    delay(x);
    moto.write(110);
    delay(x);
    moto.write(100);
    delay(x);
    moto.write(90);
    delay(x);
    moto.write(80);
    delay(x);
    moto.write(70);
    delay(x);
    moto.write(60);
    delay(x);
    moto.write(50);
    delay(x);
    moto.write(40);
    delay(x);
    moto.write(30);
    delay(x);
    moto.write(20);
    delay(x);
    moto.write(10);
    delay(1000);
    moto.write(20);
    delay(x);
    moto.write(30);
    delay(x);
    moto.write(40);
    delay(x);
    moto.write(50);
    delay(x);
    moto.write(60);
    delay(x);
    moto.write(70);
    delay(x);
    moto.write(80);
    delay(x);
    moto.write(90);
    delay(x);
    moto.write(100);
    delay(x);
    moto.write(110);
    delay(x);
    moto.write(120);
    delay(x);
    moto.write(130);
    delay(x);
    moto.write(140);
    delay(x);
    moto.write(150);
    delay(x);
    moto.write(160);
    delay(x);
  }
}
