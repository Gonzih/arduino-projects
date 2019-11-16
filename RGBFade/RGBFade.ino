int tmp = 0;

int prevLed = 9;
int currLed = 10;
int nextLed = 11;

int limit = 255;
int dl = 100;

// fade amount
int fa = 1;

void setup() {
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

  tmp = prevLed;

  prevLed = currLed;
  currLed = nextLed;
  nextLed = tmp;
}
