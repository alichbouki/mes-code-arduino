#include <IRremote.h>
#include <Servo.h>

IRrecv rec(3);               
decode_results res;
Servo moto;

void setup() {
  moto.attach(2);
  rec.enableIRIn();
}

void loop() {
  if (rec.decode(&res)) {
    if (res.value == 0x511DBB) {moto.write(170);}
    if (res.value == 0xF0C41643) {moto.write(10);}
    rec.resume();
  }
}
