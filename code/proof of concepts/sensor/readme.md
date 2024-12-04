# Uitlezen van de QTR-8A met de Arduino Nano
Minimale hard- en software die aantoont dat minimaal 6 sensoren onafhankelijk van elkaar kunnen uitgelezen worden (geen calibratie, normalisatie of interpolatie). Hierbij moet een zo groot mogelijk bereik van de AD converter benut worden (indien van toepassing)

### Benodigdheden
- Arduino Nano
- QTR-8A reflectiesensor

### Opmerkingen
Het is niet nodig om de LEDON-pin op 5V aan te sluiten; de interne pull-up weerstand is voldoende.

### Stappenplan
1. Aansluiten van de componenten
Sluit de Arduino Nano en de QTR8A aan zoals weergegeven in het elektrisch schema. Zorg ervoor dat de juiste pinnen worden gebruikt volgens het schema.
3. Code uploaden
Download de Arduino-code (Analog sensors QTR8-A) en upload deze naar de Arduino Nano met behulp van de Arduino IDE.
4. Uitlezen via de Seriële Monitor
Bekijk de waarden van A0 t/m A5(A7), waarbij A0 overeenkomt met de meest linkse sensor.


![QTR8-A](https://github.com/user-attachments/assets/7f45a2da-f77e-469a-a8e7-22852398f231)
