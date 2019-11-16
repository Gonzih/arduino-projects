int tmp = 0;

int prevLed = 9;
int currLed = 10;
int nextLed = 11;

int limit = 255;
int dl = 200;

// fade amount
int fa = 1;

void setup() {
  /* Serial.begin(9600); */
  pinMode(prevLed, OUTPUT);
  pinMode(currLed, OUTPUT);
  pinMode(nextLed, OUTPUT);
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

void loop() {
  /* log(); */
  for (int i = limit; i >= 0; i-=fa) {
    analogWrite(prevLed, limit-i);
    analogWrite(currLed, i);
    delay(dl);
  }
  delay(1000);

  tmp = prevLed;
  prevLed = currLed;
  currLed = nextLed;
  nextLed = tmp;
}
