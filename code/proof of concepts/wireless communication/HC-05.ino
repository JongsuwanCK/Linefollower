//HC-05 Bluethooth module
#include <SoftwareSerial.h>
#define rxPin 11  // RX pin 11 voor SoftwareSerial
#define txPin 12  // TX pin 12 voor SoftwareSerial
SoftwareSerial HC05(rxPin, txPin);

//Variabelen declaratie
const int Nano_Led = 13;
String Data;

// Setup
void setup() {
  // Declaratie van outputs
  pinMode(Nano_Led, OUTPUT);
  pinMode(rxPin, INPUT);   // Stel RX pin in als INPUT
  pinMode(txPin, OUTPUT);  // Stel TX pin in als OUTPUT

  // Startup blink
  delay(1000);

  Serial.begin(9600);  //Communicatie via de seriële monitor
  HC05.begin(9600);    //Communicatie via HC-05

  for (int i = 0; i < 10; i++) {
    digitalWrite(Nano_Led, HIGH);
    delay(100);
    digitalWrite(Nano_Led, LOW);
    delay(100);
  }

  // Einde setup
  delay(1000);
}

// De loop functie wordt continu herhaald
void loop() {

  // Lees van de seriële monitor
  if (Serial.available() > 0) {
    Data = Serial.readStringUntil('\n');  // // Lees de data van de seriële monitor
    HC05.println(Data);
    Serial.println(Data);
  }

  // Lees van de Bluetooth-module
  if (HC05.available() > 0) {
    Data = HC05.readStringUntil('\n');  // Lees de data van de Bluetooth-module
    HC05.println(Data);                 //De HC-05 stuurt altijd data met \n\r
    Serial.println(Data);
  }

  // LED aan/uit logica
  if (Data == "Uit") {
    digitalWrite(Nano_Led, LOW);  // Zet de LED uit
                                  // Serial.println("LED: OFF");
  } else if (Data == "Aan") {
    digitalWrite(Nano_Led, HIGH);  // Zet de LED aan
                                   // Serial.println("LED: ON");
  }
}