# Instructable

Montage plan voor line follower plan B.

Dit plan begeleidt je bij de bouw van een linefollower robot. Het gebruikt een PCB voor een nette en robuuste montage. Volg de stappen zorgvuldig om een goed functionerend systeem te bouwen.

### Stap 1 : Bestel alle componenten

Zorg ervoor dat je alle onderdelen uit de bill of materials (BOM) aanschaft.

### Stap 2 : Controle componenten

Voer proof-of-concept-tests uit om elk onderdeel te testen:

* Verbind componenten tijdelijk en controleer of ze correct functioneren.
* Los eventuele problemen op voordat je verdergaat.

### Stap 3 : PCB voorbereiding

Kies voor een PCB-oplossing voor een nette en permanente montage. Volg de stappen hieronder:

*Soldeer vrouwelijke/mannelijke connectoren (naar jouw voorkeur) op de Arduino Nano screw voor de volgende onderdelen*
- HC05 (Bluethooth communicatie)
- DRV8833 (H-brug motor driver)

*Soldeer  vrouwelijke/mannelijke connectoren (naar jouw voorkeur) op de PCB plaat voor de volgende onderdelen*
- Power LED (Geeft aan of het systeem aan staat)
- Signal LED (Geeft de status weer (bijv. Run/Stop/Calibrating).)
- Power switch (Schakelt het systeem in of uit.)
- Interrupt button (Voor het starten/stoppen van de robot)
- Motor aansluiten (Optioneel: je kunt de motoren direct op de DRV8833 aansluiten.)

### Stap 4 Bedrading volgens schema

Voor een stevig chassis gebruik je een PVC-plaat. Volg de stappen hieronder:

<u>Snijd de PVC-plaat:
Snijd de plaat in een rechthoekige vorm die groot genoeg is om alle componenten te huisvesten. Zorg dat de afmetingen passen bij de motoren, batterijhouder en controller.

<u>Boor gaten:
Markeer de posities voor het bevestigen van motoren, batterijhouder en controller (Arduino Nano).
Boor de benodigde gaten met een geschikte boormaat.
Controleer of de gaten overeenkomen met de schroefgaten van de onderdelen.

<u>Monteer de onderdelen:
Bevestig de motoren stevig met schroeven.
Monteer de batterijhouder op een toegankelijke plaats.
Bevestig de controller en zorg ervoor dat er ruimte is voor de bedrading.


### Stap 5 Bedrading volgens schema

Sluit de component aan zoals op het elektronisch schema.

### Stap 5

Download de code naar je device.

