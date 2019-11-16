int tmp = 0; // temporary pin storage var
int prevLed = 9; // previous led to fade out
int currLed = 10; // current let to fade in
int nextLed = 11; // next led, ignored in the cycle itself

int fa = 1; // fade amount
int limit = 255; // brightness limit
int dl = 20; // delay between ticks

void setup() {
  /* Serial.begin(9600); */
  pinMode(prevLed, OUTPUT);
  pinMode(currLed, OUTPUT);
  pinMode(nextLed, OUTPUT);
  analogWrite(prevLed, limit);
  analogWrite(currLed, 0);
}

void log() {
  Serial.print("prevLed: ");
  Serial.println(prevLed);
  Serial.print("currLed: ");
  Serial.println(currLed);
  Serial.print("nextLed: ");
  Serial.println(nextLed);
  Serial.println("=============");
}

void fade() {
  for (int i = limit; i >= 0; i-=fa) {
    analogWrite(prevLed, limit-i);
    analogWrite(currLed, i);
    delay(dl);
  }
  delay(1000);
}

void swap() {
  tmp = prevLed;
  prevLed = currLed;
  currLed = nextLed;
  nextLed = tmp;
}

void loop() {
  /* log(); */
  fade();
  swap();
}
