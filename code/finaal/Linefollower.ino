#include "SerialCommand.h"
#include "EEPROMAnything.h"

#define SerialPort Serial
#define Baudrate 9600

#define MotorLeftForward 9
#define MotorLeftBackward 5
#define MotorRightForward 10
#define MotorRightBackward 6


//GLobal variables
const int Drukknop = 2;                                   //Interupt
const int LED = 3;                                        //Signal LED
const int sensor[] = { A7, A6, A5, A4, A3, A2, A1, A0 };  //8 Analog sensors

bool debug;
bool run;
unsigned long previous, calculationTime;

int normalised[8];
float debugposition;
float output;
float error;
float iTerm = 0;
float lastErr;

//interupt:
volatile bool runState = false;
volatile unsigned long lastDebounceTime = 0;  // Debounce time reference
unsigned long debounceDelay = 500;            // Debounce time in ms

SerialCommand sCmd(SerialPort);

//EEPROM variables
struct param_t {
  unsigned long cycleTime;
  int black[8];
  int white[8];
  float diff;
  int power;
  float kp;
  float ki;
  float kd;

} params;

void setup() {

  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);

  SerialPort.begin(Baudrate);

  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.addCommand("calibrate", onCalibrate);
  sCmd.addCommand("run", onRun);
  sCmd.addCommand("stop", onStop);
  sCmd.setDefaultHandler(onUnknownCommand);

  EEPROM_readAnything(0, params);
  SerialPort.println("Ready");

  //Interupt
  pinMode(Drukknop, INPUT);
  attachInterrupt(digitalPinToInterrupt(Drukknop), Interrupt, RISING);
  pinMode(LED, OUTPUT);
}


void loop() {
  sCmd.readSerial();

  unsigned long current = micros();
  if (current - previous >= params.cycleTime) {
    previous = current;
    //Normalize
    for (int i = 0; i < 8; i++) {
      normalised[i] = map(analogRead(sensor[i]), params.black[i], params.white[i], 0, 1000);
    }

    //Interpolation
    int index = 0;
    float position;

    for (int i = 1; i < 8; i++)
      if (normalised[i] < normalised[index]) index = i;

    if (normalised[index] > 700) run = false;  //Automatische stop linefollower
    if (!run) digitalWrite(LED, false);


    if (index == 0) position = -30;
    else if (index == 7) position = 30;
    else {
      int sNul = normalised[index];
      int sMinEen = normalised[index - 1];
      int sPlusEen = normalised[index + 1];

      float b = sPlusEen - sMinEen;
      b = b / 2;
      float a = sPlusEen - b - sNul;

      position = -b / (2 * a);
      position += index;
      position -= 3.5;
      position *= 9.525;  //Distance between each IR sensor
    }

    debugposition = position;

    //P-control
    error = -position;
    output = error * params.kp;

    //I-control
    iTerm += params.ki * error;
    iTerm = constrain(iTerm, -510, 510);
    output += iTerm;

    //D-control
    output += params.kd * (error - lastErr);
    lastErr = error;

    output = constrain(output, -510, 510);

    int powerLeft = 0;
    int powerRight = 0;


    if (run)
      if (output >= 0) {
        powerLeft = constrain(params.power + params.diff * output, -255, 255);
        powerRight = constrain(powerLeft - output, -255, 255);
        powerLeft = powerRight + output;
      } else {
        powerRight = constrain(params.power - params.diff * output, -255, 255);
        powerLeft = constrain(powerRight + output, -255, 255);
        powerRight = powerLeft - output;
      }

    analogWrite(MotorLeftForward, powerLeft > 0 ? powerLeft : 0);
    analogWrite(MotorLeftBackward, powerLeft < 0 ? -powerLeft : 0);
    analogWrite(MotorRightForward, powerRight > 0 ? powerRight : 0);
    analogWrite(MotorRightBackward, powerRight < 0 ? -powerRight : 0);
  }

  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
}

//Unknown command handler
void onUnknownCommand(char* command) {
  SerialPort.print("unknown command: \"");
  SerialPort.print(command);
  SerialPort.println("\"");
}

//Set command
void onSet() {
  char* param = sCmd.next();
  char* value = sCmd.next();

  if (strcmp(param, "cycle") == 0) {
    long newCycleTime = atol(value);
    float ratio = ((float)newCycleTime) / ((float)params.cycleTime);

    params.ki *= ratio;
    params.kd /= ratio;

    params.cycleTime = newCycleTime;
  }

  else if (strcmp(param, "ki") == 0) {
    float cycleTimeInSec = ((float)params.cycleTime) / 1000000;
    params.ki = atof(value) * cycleTimeInSec;
  }

  else if (strcmp(param, "kd") == 0) {
    float cycleTimeInSec = ((float)params.cycleTime) / 1000000;
    params.kd = atof(value) / cycleTimeInSec;
  }

  else if (strcmp(param, "power") == 0) params.power = atol(value);
  else if (strcmp(param, "diff") == 0) params.diff = atof(value);
  else if (strcmp(param, "kp") == 0) params.kp = atof(value);

  EEPROM_writeAnything(0, params);
}

//Show command settings
void onDebug() {
  SerialPort.print("cycle time: ");
  SerialPort.println(params.cycleTime);

  SerialPort.print("black: ");
  for (int i = 0; i < 8; i++) {
    SerialPort.print(params.black[i]);
    SerialPort.print(" ");
  }
  SerialPort.println(" ");

  SerialPort.print("white: ");
  for (int i = 0; i < 8; i++) {
    SerialPort.print(params.white[i]);
    SerialPort.print(" ");
  }
  SerialPort.println(" ");

  SerialPort.print("Normalised: ");
  for (int i = 0; i < 8; i++) {
    SerialPort.print(normalised[i]);
    SerialPort.print(" ");
  }
  SerialPort.println(" ");

  SerialPort.print("position: ");
  SerialPort.println(debugposition);

  SerialPort.print("Power: ");
  SerialPort.println(params.power);

  SerialPort.print("diff: ");
  SerialPort.println(params.diff);

  SerialPort.print("Kp: ");
  SerialPort.println(params.kp);

  float cycleTimeInSec = ((float)params.cycleTime) / 1000000;
  float ki = params.ki / cycleTimeInSec;
  SerialPort.print("Ki: ");
  SerialPort.println(ki);

  float kd = params.kd * cycleTimeInSec;
  SerialPort.print("Kd: ");
  SerialPort.println(kd);

  SerialPort.print("calculation time: ");
  SerialPort.println(calculationTime);
  calculationTime = 0;
}

//Calibrate sensors white/black
void onCalibrate() {
  char* param = sCmd.next();

  if (strcmp(param, "black") == 0) {
    SerialPort.print("start calibrating black...");
    for (int i = 0; i < 8; i++) params.black[i] = analogRead(sensor[i]);
    SerialPort.println("done");
  } else if (strcmp(param, "white") == 0) {
    SerialPort.print("start calibrating white...");
    for (int i = 0; i < 8; i++) params.white[i] = analogRead(sensor[i]);
    SerialPort.println("done");
  }

  EEPROM_writeAnything(0, params);
}

//Run command
void onRun() {
  run = true;
  digitalWrite(LED, HIGH);
}

//Stop command
void onStop() {
  run = false;
  digitalWrite(LED, LOW);
}


//Interupt RUN/STOP
void Interrupt() {

  // Debounce time interrupt
  if ((millis() - lastDebounceTime) > debounceDelay) {
    run = !run;
    runState = run;
    if (run) digitalWrite(LED, HIGH);
    else digitalWrite(LED, LOW);
  }

  // Update debounce time
  lastDebounceTime = millis();
}
