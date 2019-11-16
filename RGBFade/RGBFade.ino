int tmp = 0;

int prevLed = 11;
int currLed = 10;
int nextLed = 9;

int limit = 255;
int dl = 100;

// fade amount
int fa = 1;

void setup() {
  /* Serial.begin(9600); */
  pinMode(prevLed, OUTPUT);
  pinMode(currLed, OUTPUT);
  pinMode(nextLed, OUTPUT);
}

void loop() {
  for (int i = 0; i <= limit; i+=fa) {
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
