# Draadloze Bluetooth-communicatie met de Arduino Nano
Deze handleiding beschrijft hoe je draadloze communicatie via Bluetooth kunt opzetten met een Arduino Nano en een HC-05 module.

### Benodigdheden
Arduino Nano
HC-05
LED
Weerstanden
Android Smartphone

### Opmerkingen
Met behulp van de SoftwareSerial-library kun je een extra seriële communicatiepoort creëren. Dit maakt het mogelijk om zowel met de computer (via de Serial Monitor) als met een Bluetooth-app te communiceren.

### Stappenplan
1. Voorbereiding
Download en installeer de Serial Bluetooth Terminal-app op je Android-smartphone.
2. Aansluiten van de componenten
Sluit de Arduino Nano, HC-05, LED en weerstanden aan zoals weergegeven in het elektrisch schema. Zorg ervoor dat de juiste pinnen worden gebruikt volgens het schema.
3. Code uploaden
Download de Arduino-code (PoF Wireless Communication HC-05) en upload deze naar de Arduino Nano met behulp van de Arduino IDE.
4. Testen van de communicatie
Maak via de Serial Bluetooth Terminal-app verbinding met de HC-05 module.
Gebruik de commando's "Aan" en "Uit" om draadloos de LED aan en uit te schakelen.


![HC05](https://github.com/user-attachments/assets/fc04386a-dca5-478b-a3b9-22b0b7f29cf5)
