int sequence[][7] = {
  {1, 0, 0, 0, 1, 1, 1},
  {1, 1, 1, 0, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 1},
  {0, 1, 1, 0, 1, 1, 1},
  {1, 0, 0, 1, 1, 1, 0},
  {0, 0, 0, 1, 1, 1, 0},
  {1, 1, 0, 0, 1, 1, 1},
 };
  void printNumber(int number) {
    for (int i = 0; i < 7; i++) {
      digitalWrite(1 + i,sequence[number][i]);

    }
  }






void setup() {
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(1, OUTPUT);
}





void loop() {
 for(int i=0;i<10;i++){
  printNumber(i);
  delay(1000);

 }}
