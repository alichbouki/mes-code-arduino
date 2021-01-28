#include <IRremote.h>
#include <Stepper.h>

int spr = 64 ;

IRrecv rec(3);               
decode_results res;
Stepper moto (spr,  4, 6 , 5 , 7 );

void setup() {
  rec.enableIRIn();
  moto .setSpeed( 500 );
}

void loop() {
  if (rec.decode(&res)) {
    if (res.value == 0x511DBB) {moto.step(10*spr);}
    if (res.value == 0xF0C41643) {moto.step(-10*spr);}
    rec.resume();
  }
}
