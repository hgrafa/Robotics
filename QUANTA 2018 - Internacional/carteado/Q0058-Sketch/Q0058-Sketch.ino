#define pinBotaoA 5
#define pinBotaoB 5

#define pinSentido1MotorA 3
#define pinSentido2MotorA 2

#define pinSentido1MotorB 7
#define pinSentido2MotorB 6

byte estadoA = 0;
bool estadoBotaoA = true;
bool estadoAntBotaoA = true;
unsigned long delayBotaoA;

byte estadoB = 0;
bool estadoBotaoB = true;
bool estadoAntBotaoB = true;
unsigned long delayBotaoB;

void setup() {
  pinMode(pinBotaoA, INPUT_PULLUP);
  pinMode(pinBotaoB, INPUT_PULLUP);

  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);
}

void loop() {

  estadoBotaoA = digitalRead(pinBotaoA);
  if (!estadoBotaoA && estadoAntBotaoA) {
     if ((millis() - delayBotaoA) > 20) {
        estadoA++;
        if (estadoA > 2) {
           estadoA = 0;
        }
        delayBotaoA = millis();
     }
  } else if (estadoBotaoA != estadoAntBotaoA) {
        delayBotaoA = millis();    
  }
  estadoAntBotaoA = estadoBotaoA;

  estadoBotaoB = digitalRead(pinBotaoB);
  if (!estadoBotaoB && estadoAntBotaoB) {
     if ((millis() - delayBotaoB) > 20) {
        estadoB++;
        if (estadoB > 2) {
           estadoB = 0;
        }
        delayBotaoB = millis();
     }
  } else if (estadoBotaoB != estadoAntBotaoB) {
        delayBotaoB = millis();    
  }
  estadoAntBotaoB = estadoBotaoB;


  if (estadoA == 0) {
     digitalWrite(pinSentido1MotorA, LOW);
     digitalWrite(pinSentido2MotorA, LOW);    

  } else {    
     if (estadoA == 1) {
        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH);
        
     } else { //estadoA == 2
        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, LOW);      
     }
  } 


  if (estadoB == 0) {
     digitalWrite(pinSentido1MotorB, LOW);
     digitalWrite(pinSentido2MotorB, LOW);

  } else {
     if (estadoB == 1) {
        digitalWrite(pinSentido1MotorB, LOW);
        digitalWrite(pinSentido2MotorB, HIGH);
        
     } else { //estadoB == 2
        digitalWrite(pinSentido1MotorB, HIGH);
        digitalWrite(pinSentido2MotorB, LOW);      
     }
  } 
  
}
