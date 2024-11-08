// Motor Links
const int AIN1 = 5;
const int AIN2 = 6;

// Motor Rechts
const int BIN1 = 9;
const int BIN2 = 10;

void setup() {
  Serial.begin(9600);

  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

// MAX 6V 175 !!!!!!!!!
void loop() {

  delay(2000); //Vooruit

  analogWrite(AIN1, 0);
  analogWrite(AIN2, 100);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 100);

  delay(1500);

  analogWrite(AIN1, 0);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 0);

  delay(1500); //Achteruit

  analogWrite(AIN1, 100);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 100);
  analogWrite(BIN2, 0);

  delay(1500);

  analogWrite(AIN1, 0);
  analogWrite(AIN2, 0);
  analogWrite(BIN1, 0);
  analogWrite(BIN2, 0);

  delay(2000);


  /*
  // Voorwaarts versnellen---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  for (int i = 0; i <= 175; i++) {
    analogWrite(AIN1, i);
    analogWrite(AIN2, 0);
    analogWrite(BIN1, i);
    analogWrite(BIN2, 0);
    delay(10);
  }

  delay(2000);

  // Voorwaarts vertragen
  for (int i = 175; i >= 0; i--) {
    analogWrite(AIN1, i);
    analogWrite(AIN2, 0);
    analogWrite(BIN1, i);
    analogWrite(BIN2, 0);
    delay(10);
  }
  delay(2000);


  // Achterwaards versnellen---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  for (int i = 0; i <= 175; i++) {
    analogWrite(AIN1, 0);
    analogWrite(AIN2, i);
    analogWrite(BIN1, 0);
    analogWrite(BIN2, i);
    delay(10);
  }

  delay(2000);

  // Achterwaards vertragen
  for (int i = 175; i >= 0; i--) {
    analogWrite(AIN1, 0);
    analogWrite(AIN2, i);
    analogWrite(BIN1, 0);
    analogWrite(BIN2, i);
    delay(10);
  }
  delay(2000); */
}
