#include <Stepper.h>

int spr = 64 ;

Stepper moto (spr,  4, 6 , 5 , 7 );

void setup () {
moto .setSpeed( 500);
}

void loop () {
  moto .step(-500 * spr) ;
}
