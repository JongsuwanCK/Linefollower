//HC-05 Bluethooth module
#include <SoftwareSerial.h>
#define rxPin 11  // RX pin 11 voor SoftwareSerial
#define txPin 12  // TX pin 12 voor SoftwareSerial
SoftwareSerial HC05(rxPin, txPin);

const int Nano_Led = 13;

const int QTRA0 = 0;
const int QTRA1 = 1;
const int QTRA2 = 2;
const int QTRA3 = 3;
const int QTRA4 = 4;
const int QTRA5 = 5;
const int QTRA6 = 6;
const int QTRA7 = 7;

void setup() {

  Serial.begin(9600);
  pinMode(Nano_Led, OUTPUT);

  //Bluethooth communicatie
  HC05.begin(9600);        //Communicatie via HC-05
  pinMode(rxPin, INPUT);   // Stel RX pin in als INPUT
  pinMode(txPin, OUTPUT);  // Stel TX pin in als OUTPUT

  //Initialisatie
  for (int i = 0; i < 10; i++) {
    digitalWrite(Nano_Led, HIGH);
    delay(100);
    digitalWrite(Nano_Led, LOW);
    delay(100);
  }
}

void loop() {
  Serial.print("A0 : ");
  Serial.println(analogRead(QTRA0));
  Serial.print("A1 : ");
  Serial.println(analogRead(QTRA1));
  Serial.print("A2 : ");
  Serial.println(analogRead(QTRA2));
  Serial.print("A3 : ");
  Serial.println(analogRead(QTRA3));
  Serial.print("A4 : ");
  Serial.println(analogRead(QTRA4));
  Serial.print("A5 : ");
  Serial.println(analogRead(QTRA5));
  Serial.print("A6 : ");
  Serial.println(analogRead(QTRA6));
  Serial.print("A7 : ");
  Serial.println(analogRead(QTRA7));

  HC05.print("A0 : ");
  HC05.println(analogRead(QTRA0));
  HC05.print("A1 : ");
  HC05.println(analogRead(QTRA1));
  HC05.print("A2 : ");
  HC05.println(analogRead(QTRA2));
  HC05.print("A3 : ");
  HC05.println(analogRead(QTRA3));
  HC05.print("A4 : ");
  HC05.println(analogRead(QTRA4));
  HC05.print("A5 : ");
  HC05.println(analogRead(QTRA5));
  HC05.print("A6 : ");
  HC05.println(analogRead(QTRA6));
  HC05.print("A7 : ");
  HC05.println(analogRead(QTRA7));

  delay(2000);
}