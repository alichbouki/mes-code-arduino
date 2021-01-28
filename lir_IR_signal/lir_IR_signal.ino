#include <IRremote.h>
 
IRrecv recv(3);  
decode_results res;

void setup() {
  Serial.begin(9600);
  recv.enableIRIn();
}

void loop() {
  if (recv.decode(&res)) {
    Serial.println(res.value, HEX);
    recv.resume();}
  delay(100);
}
