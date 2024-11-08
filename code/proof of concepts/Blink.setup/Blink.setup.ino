//Variabelen declaratie
const int Nano_Led = 13;

// Setup
void setup() {
  // Declaratie van outputs
  pinMode(Nano_Led, OUTPUT);

  // Startup blink
  delay(1000);

  for (int i = 0; i < 10; i++) {
    digitalWrite(Nano_Led, HIGH);
    delay(150);
    digitalWrite(Nano_Led, LOW);
    delay(150);
  }

  // Einde setup
  delay(1000);
}

// De loop functie wordt continu herhaald
void loop() {

}