# Instructable

Montage plan voor deze line follower.

Dit plan begeleidt je bij de bouw van een linefollower robot. Het gebruikt een PCB voor een nette en robuuste montage. Volg de stappen zorgvuldig om een goed functionerend systeem te bouwen.

### Stap 1 : Bestel alle componenten

Zorg ervoor dat je alle onderdelen uit de bill of materials (BOM) aanschaft.

https://github.com/JongsuwanCK/Linefollower/tree/main/bill%20of%20materials

### Stap 2 : Controle componenten

Voer proof-of-concept-tests uit om elk onderdeel te testen:

https://github.com/JongsuwanCK/Linefollower/tree/main/code/proof%20of%20concepts

* Verbind componenten tijdelijk en controleer of ze correct functioneren.
* Los eventuele problemen op voordat je verdergaat.

### Stap 3 : PCB voorbereiding

Kies voor een PCB-oplossing voor een nette en permanente montage. Volg de stappen hieronder:

*Soldeer vrouwelijke/mannelijke connectoren (naar jouw voorkeur) op de Arduino Nano screw terminal voor de volgende onderdelen*
- HC05 (Bluethooth communicatie)
- DRV8833 (H-brug motor driver)

*Soldeer  vrouwelijke/mannelijke connectoren (naar jouw voorkeur) op de PCB plaat voor de volgende onderdelen*
- Power LED (Geeft aan of het systeem aan staat)
- Signal LED (Geeft de status weer (bijv. Run/Stop/Calibrating).)
- Power switch (Schakelt het systeem in of uit.)
- Interrupt button (Voor het starten/stoppen van de robot)
- Motor aansluiten (Optioneel: je kunt de motoren direct op de DRV8833 aansluiten.)

#### Prototype PCB
![image](https://github.com/user-attachments/assets/135539e1-9cce-4a57-a907-c6fafda5c847) ![image](https://github.com/user-attachments/assets/d0207764-e1f5-4d56-ba7e-5dffd97f70c5)

![image](https://github.com/user-attachments/assets/4c13a013-9df3-428c-8c48-38c2cc964e31)

#### Arduino nano screw terminal
![image](https://github.com/user-attachments/assets/fdfb9a1a-8de1-44ea-843e-780993983630) ![image](https://github.com/user-attachments/assets/765180ae-e483-4cb9-af57-899a7f809782)


### Stap 4 : Bouw van de line follower

Voor een stevig chassis gebruik je een polulu chassis (zie BOM), of een custom PVC plaat. Volg de stappen hieronder:

Monteer de onderdelen:

1. Bevestig de motoren en wielen (met behulp van de motor houder) stevig met schroeven op het chassis.
2. Monteer de Pololu bal caster stevig met schroeven op het chassis.
3. Bevestig de Arduino Nano Screw Terminal met schroeven aan het chassis.
4. Zet de PCB vast op het chassis met schroeven en lijm voor extra stabiliteit.
5. Monteer de batterijhouder aan de achterzijde van de Arduino Nano Terminal.

### Stap 5 : Bedrading volgens schema

Sluit de component aan zoals op het elektronisch schema.

![image](https://github.com/user-attachments/assets/510c215f-5ca3-4905-854c-ae2e89ea5c17) ![image](https://github.com/user-attachments/assets/7a14c5d3-e99b-4fe0-8705-f27297cf3fca)

### Stap 6 : Code

Download de finale code naar je device (Arduino Nano).

https://github.com/JongsuwanCK/Linefollower/blob/main/code/finaal/Linefollower.ino

