# Gebruiksaanwijzing

### Opladen / Vervangen batterijen
Je hebt twee 18650 li-ion batterijen nodig en een geschikte oplader voor dit type. De oplader kan aangesloten worden op je PC, AC-adapter, of een andere geschikte voeding.

![image](https://github.com/user-attachments/assets/6cc207ea-a630-431f-9ad1-37104d55f0fa)
![image](https://github.com/user-attachments/assets/0afe87f1-53f3-420a-acf9-aef7903ab597)

### Draadloze communicatie
Zie proof of concepts wireless communication
https://github.com/JongsuwanCK/Linefollower/tree/main/code/proof%20of%20concepts/wireless%20communication

![image](https://github.com/user-attachments/assets/d25d12cd-fcf0-4235-b84d-1e9d849035ae)



#### Commando's
- debug [on/off]: Zet debug mode aan of uit om je ingestelde parameters op te vragen.
- run: Start de line follower.
- stop: Stop de line follower.
- set cycle [µs]: Stel de cycle time in. Zorg ervoor dat deze hoger is dan de calculation time.
- set power [0..255]: Stel de snelheid van de line follower in. Hoe hoger de waarde, hoe sneller de robot.
- set diff [0..1]: Stel het differentieel in. Dit bepaalt hoeveel de robot afremt in bochten.
- set kp [0..]: Stel de proportionele correctie in. Hoe hoger de waarde, hoe meer de robot zich zelf corrigeert om de lijn in het midden te houden. Te hoog kan leiden tot schokkende bewegingen van links naar rechts.
- set ki [0..]: Stel de integrerende correctie in. Hoe langer de fout duurt, hoe sterker de correctie.
- set kd [0..]: Stel de afgeleide correctie in. Dit kijkt naar de fout in de vorige cyclus en past de correctie aan. Als de fout groot was, wordt de correctie sterker.
- calibrate black: Kalibreer de zwarte kleur.
- calibrate white: Kalibreer de witte kleur.

### Kalibratie
Voor de kalibratie van de QTR-8A sensoren moet je de volgende stappen volgen:

1. Plaats de line follower met zijn sensoren over een zwarte lijn op je parcours. Zorg ervoor dat alle sensoren over het zwarte deel van de lijn hangen.
2. Geef het commando calibrate black in via je smartphone.
3. Wacht op de melding calibrate black done.
4. Herhaal dezelfde procedure voor de witte kleur door het commando calibrate white in te voeren.

![image](https://github.com/user-attachments/assets/c4ca1e0e-b1dc-48ed-b370-6e63920a9b8f)
Voorbeeld : Calibrate black

### Settings
De robot rijdt stabiel met de volgende parameters:

- cycle time = 2000 µs
- power = 150
- diff = 0.35
- kp = 10.00
- ki = 0.00
- kd = 0.90

### Start/Stop button
Je kunt de line follower zowel draadloos starten en stoppen als handmatig via een knop. Het is echter gemakkelijker om de robot draadloos te bedienen via de Bluetooth-verbinding.

![power](https://github.com/user-attachments/assets/81607dc4-aa71-4108-b858-470b9792114c)
