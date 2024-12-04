# H-Bridge proof of concept

Minimale hard- & software + stappenplan dat aantoont dat 2 motoren onafhankelijk van elkaar kunnen draaien, en (traploos) regelbaar zijn in snelheid en draairichting.

### Benodigdheden
- Arduino Nano
- 2 Micro metal gear motoren
- DRV8833
- Externe voeding (18650 Batterijen)

### Opmerkingen
De PWM-pinnen van de Arduino Nano worden aangestuurd door interne timers. Voor consistente aansturing is het belangrijk dat je dezelfde timers gebruikt voor vergelijkbare functies (bijvoorbeeld vooruit of achteruit).

![Timers](https://github.com/user-attachments/assets/b6f567d9-8d86-423b-8d85-29b7b3617908)

### Stappenplan
1. Verbind de Arduino Nano, DRV8833, motoren en voeding volgens het elektronische schema.
2. Download de code naar je microcontroller.
3. De motoren zullen geleidelijk versnellen in de voorwaartse richting en daarna in de achterwaartse richting.
4. Pas de code aan om verschillende snelheden en draairichtingen te testen.

![Motor](https://github.com/user-attachments/assets/88b34b6b-6b63-43a5-b84d-b72d0f8fbc60)
