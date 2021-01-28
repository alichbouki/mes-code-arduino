#include <Servo.h>
Servo moto1;
Servo moto2;
int x,y;


void setup() {
  Serial.begin(9600);
  moto1.attach(7);
  moto2.attach(8);
}
void loop() {
  x=analogRead(A0);
  x=map(x,0,1023,15,170);
  moto1.write(x);
  y=analogRead(A2);
  y=map(x,0,1023,15,170);
  moto2.write(y);
  Serial.print(x);
  Serial.print("    ");
  Serial.println(y);
}
