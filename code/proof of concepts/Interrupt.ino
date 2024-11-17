const int DK = 3;   // Drukknop op pin 3
const int Led = 4;  // LED op pin 4
const int anLed = 13;  // LED op pin 13

volatile bool ledState = false;                 // Huidige status van de LED
volatile unsigned long debounceStartReset = 0;  // Tijd voor debouncing
const unsigned long debounceDelay = 500;         // Debounce-tijd in milliseconden

void setup() {
  pinMode(DK, INPUT);    // Configureer buttonPin als ingang
  pinMode(Led, OUTPUT);  // Configureer ledPin als uitgang
   pinMode(anLed, OUTPUT);  // Configureer ledPin als uitgang

  attachInterrupt(digitalPinToInterrupt(DK), Interrupt, RISING);  // Koppel de interrupt-functie aan de opgaande flank van de drukknop
}

void loop() {
  // Doe hier andere taken die onafhankelijk zijn van de drukknopstatus
  Serial.println(millis());
  delay(1000);
}

void Interrupt() {
  // Lees de status van de drukknop
  int buttonState = digitalRead(DK);

  // Debounce de drukknop met millis
  if ((millis() - debounceStartReset) > debounceDelay) {
    // Wissel de status van de LED als de knop opgaand is
    if (buttonState == HIGH) {
      ledState = !ledState;

      // Schakel de LED in of uit op basis van de nieuwe status
      digitalWrite(Led, ledState);
      digitalWrite(anLed, ledState);
    }
    // Update de tijd van de laatste debouncing
    debounceStartReset = millis();
  }
}
