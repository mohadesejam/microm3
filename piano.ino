#define T_C 262
#define T_D 294
#define T_E 330
#define T_F 349
#define T_G 392
#define T_A 440
#define T_B 493
const int A = 5;
const int B = 6;
const int C = 7;
const int D= 8;
const int Burr = 11;


void setup() {
 
    pinMode(A, INPUT);
    digitalWrite(A, HIGH);
    pinMode(B, INPUT);
    digitalWrite(B, HIGH);
    pinMode(C, INPUT);
    digitalWrite(C, HIGH);
    pinMode(D, INPUT);
    digitalWrite(D, HIGH);
  }


void loop() {

  while (digitalRead(A) == LOW) {
    tone(Burr,T_C);
  }
  while (digitalRead(B) == LOW) {
    tone(Burr,T_D);
  }
  while (digitalRead(C) == LOW) {
    tone(Burr,T_E);
  }
  while (digitalRead(D) == LOW) {
    tone(Burr,T_F);
  }
  noTone(Burr);
}
