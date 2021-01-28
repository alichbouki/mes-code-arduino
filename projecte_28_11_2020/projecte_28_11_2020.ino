int led1 = 2, led2 = 3, led3 = 4, led5 = 5;
int sw = 7, val, x = 2;

void setup() {
  for (int i = 2; i < 6; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(sw, INPUT_PULLUP);
}

void loop() {
  val = digitalRead(sw);
  if (val == 1) {}

  else if (val == 0) {
    while (x < 6) {
      digitalWrite(x, HIGH);
      delay(500);
      digitalWrite(x, LOW);
      x++;
    }
    x = 2;
  }
}
