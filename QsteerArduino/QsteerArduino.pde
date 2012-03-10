#define LED 10

int data [15];
int g = 0;
byte b = B001111;

void setpwm(int pwm) {
  data[g] = pwm;
  g++;
}

void runpwm() {
  for (int i = 5; i >= 0; i--) {
    setpwm(400);
    int pwm = (bitRead(b, i) == 1) ? 900 : 430;
    setpwm(pwm);
  }
}

void sendpwm() {
  for (int cnt = 0; cnt < sizeof(data) / sizeof(int) - 1; cnt++) {
    unsigned long len = data[cnt];
    unsigned long us = micros();
    do {
      digitalWrite(LED, 0 + (cnt & 1));
      delayMicroseconds(8);
      digitalWrite(LED, 0);
      delayMicroseconds(7);
    } while (long (us + len - micros()) > 0);
  }
}

void execpwm() {
  g = 0;
  int pwm = 7540;
  int ch1 = bitRead(b, 4);
  int ch2 = bitRead(b, 5);
  if (ch1 == 0 && ch2 == 0) pwm = 7540;
  if (ch1 == 0 && ch2 == 1) pwm = 21860;
  if (ch1 == 1 && ch2 == 0) pwm = 36200;
  if (ch1 == 1 && ch2 == 1) pwm = 50570;

  setpwm(pwm);
  setpwm(1740);
  runpwm();
  sendpwm();
}

void setch(byte bb) {
  bitWrite(b, 4, bitRead (bb, 0));
  bitWrite(b, 5, bitRead (bb, 1));
}

void setbit(byte bb) {
  for (int i = 0; i < 4; i++) {
    bitWrite(b, i, bitRead(bb, i));
  }
  execpwm();
}

void setup() {
  Serial.begin(9600);
  Serial.println("Ready"); 
  pinMode(LED, OUTPUT); 
}

void loop() {
  static int v = 0;
  if (Serial.available()> 0) {
    char ch = Serial.read();
    switch (ch) {
      case '1':
        setbit(B0001); // forward
        break;
      case '2':
        setbit(B0010); // backward
        break;
      case '3':
        setbit(B0110); // forward left
        break;
      case '4':
        setbit(B0111); // forward right
        break;
      case '5':
        setbit(B1010); // backward left
        break;
      case '6':
        setbit(B1011); // backward right
        break;
      case '7':
        setbit(B0011); // wheels left
        break;
      case '8':
        setbit(B0100); // wheels right
        break;
      case '0':
        setbit(B1111); // mb "turbo" button
        break;
      case 'a':
        setbit(B0101); // forward fast
        break;
      case 'b':
        setbit(B1100); // backward fast
        break;
      case 'c':
        setbit(B1000); // forward left fast
        break;
      case 'd':
        setbit(B1001); // forward right fast
        break;
      case 'e':
        setbit(B1101); // backward left fast
        break;
      case 'f':
        setbit(B1110); // backward right fast
        break;
      case 'A':
        setch(B00); // set channel to A
        break;
      case 'B':
        setch(B01); // set channel to B
        break;
      case 'C':
        setch(B10); // set channel to C
        break;
      case 'D':
        setch(B11); // set channel to D
        break;
    }
  }
}
