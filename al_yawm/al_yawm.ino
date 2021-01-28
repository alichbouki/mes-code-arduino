int x;

void setup() {
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  x=digitalRead(3);
  Serial.println(x);
  //delay(500);
}
