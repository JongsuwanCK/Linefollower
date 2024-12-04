#include "SerialCommand.h"
#include "EEPROMAnything.h"

#define SerialPort Serial
#define Baudrate 9600

//Read commands from SerialPort
SerialCommand sCmd(SerialPort);

//Global variables
bool debug;
unsigned long previous, calculationTime;
const int Led13 = 13;
const int LED = 3;
const int Drukknop = 2;

//Linefollower
bool run;
bool stop;

//interupt:
volatile bool runState = false;
volatile unsigned long lastDebounceTime = 0;  // Debounce time reference
unsigned long debounceDelay = 500;            // Debounce time in ms

//EEPROM variables
struct param_t {
  unsigned long cycleTime;
  unsigned int Hertz;
} params;


//Setup
void setup() {
  SerialPort.begin(Baudrate);

  sCmd.addCommand("set", onSet);
  sCmd.addCommand("debug", onDebug);
  sCmd.setDefaultHandler(onUnknownCommand);

  EEPROM_readAnything(0, params);

  pinMode(Led13, OUTPUT);
  pinMode(LED, OUTPUT);
  SerialPort.println("ready");

  //Interupt
  pinMode(Drukknop, INPUT);
  attachInterrupt(digitalPinToInterrupt(Drukknop), Interrupt, RISING);
  pinMode(LED, OUTPUT);
}

//Loop
void loop() {

  //Read command
  sCmd.readSerial();

  //Cycle interval
  unsigned long current = micros();
  if (current - previous >= params.cycleTime) {
    previous = current;

    //Led frequency
    analogWrite(Led13, params.Hertz);  //Schrijf de gewenste frequentie in voor de LED.
  }

  //Cycle time
  unsigned long difference = micros() - current;
  if (difference > calculationTime) calculationTime = difference;
}
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

//Default handler for unknown commands
void onUnknownCommand(char* command) {
  SerialPort.print("unknown command: \"");
  SerialPort.print(command);
  SerialPort.println("\"");
}

//Commando param data : set XXX YYY
void onSet() {
  char* param = sCmd.next();
  char* value = sCmd.next();
  char* led = sCmd.next();

  //Cycle time
  if (strcmp(param, "cycle") == 0) params.cycleTime = atol(value);

  //Led frequency
  if (strcmp(param, "led") == 0) params.Hertz = atoi(value);  //Stel de gewenste frequentie in voor de LED.

  EEPROM_writeAnything(0, params);
}

//Commando : debug (data)
void onDebug() {
  //Cycle time
  SerialPort.print("cycle time: ");
  SerialPort.println(params.cycleTime);

  //Led frequency
  SerialPort.print("led frequency: ");
  SerialPort.println(params.Hertz);

  //Cycle time
  SerialPort.print("calculation time: ");
  SerialPort.println(calculationTime);
  calculationTime = 0;
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

void Interrupt() {

  // Debounce time interrupt
  if ((millis() - lastDebounceTime) > debounceDelay) {
    run = !run;
    runState = run;
    if (run) digitalWrite(LED, HIGH);
    else digitalWrite(LED, LOW);
  }
}
