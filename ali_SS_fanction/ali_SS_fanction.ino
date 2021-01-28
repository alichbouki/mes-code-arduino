int a = 2, b = 3, c = 4, d = 5, e = 6, f = 7, g = 8;
int res;
void setup() {
  for (int i = 2; i < 9; i++) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  aliSS(res);
  res++;
  if (res == 10) {
    res = 0;
  }
  delay(1000);
}

void aliSS(int n) {
  if (n ==  1) {
    digitalWrite(d, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(b, LOW);
    digitalWrite(c, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
  }
  else if (n == 2) {
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(a, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
  }
  else if (n == 3) {
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(a, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
  }
  else if (n == 4) {
    digitalWrite(c, LOW);
    digitalWrite(d, HIGH);
    digitalWrite(a, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  }
  else if (n == 5) {
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  }
  else if (n == 6) {
    digitalWrite(c, HIGH);
    digitalWrite(d, LOW);
    digitalWrite(a, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  }
  else if (n == 7) {
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(e, LOW);
    digitalWrite(f, LOW);
    digitalWrite(g, HIGH);
    digitalWrite(b, LOW);
  }
  else if (n == 8) {
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(a, HIGH);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  }
  else if (n == 9) {
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(a, HIGH);
    digitalWrite(e, LOW);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  }
  else if (n == 0) {
    digitalWrite(c, HIGH);
    digitalWrite(d, HIGH);
    digitalWrite(a, LOW);
    digitalWrite(e, HIGH);
    digitalWrite(f, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
  }
}
