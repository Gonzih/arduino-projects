int tmp1 = 0;
int tmp2 = 0;

int prevLed = 9;
int currLed = 10;
int nextLed = 11;

int limit = 160;
int threshold = 50;
int dl = 50;

// fade amount
int fa = 1;

void setup() {
  pinMode(prevLed, OUTPUT);
  pinMode(currLed, OUTPUT);
  pinMode(nextLed, OUTPUT);
}

void loop() {
  for (int i = limit; i >= threshold; i-=fa) {
    analogWrite(prevLed, i);
    delay(dl);
  }

  for (int i = 0; i <= limit; i+=fa) {
    analogWrite(currLed, i);
    delay(dl);
  }

  for (int i = threshold; i >= 0; i-=fa) {
    analogWrite(prevLed, i);
    delay(dl);
  }

  tmp1 = currLed;
  currLed = nextLed;
  tmp2 = prevLed;
  prevLed = tmp1;
  nextLed = tmp2;
}
