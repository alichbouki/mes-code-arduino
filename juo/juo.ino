#include <Servo.h>

Servo moto;

int x;

void setup() {
  Serial.begin(9600);
  moto.attach(9);
}

void loop() {
  x=analogRead(A1);
  Serial.println(x);
  x=map(x,0,1024,15,170);

  moto.write(x);
}
