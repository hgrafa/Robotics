//------------------------------------------------------------------
// Hugo Rafael de Lima
// acelerometro através de botão
// obs.: duas rodas ligadas também por um botão
//------------------------------------------------------------------
// DEFINIÇÕES

//pinos que ligam as rodas aqui
//como eu quero que elas sejam ligadas juntas
//vou passar o mesmo pino pra ser lido
#define pinBotao 5

//pino que vai olhar o botão substitutivo do potenciometro
#define pinAcelerometro 12

//os pinos novos que estavam tampados quando a vel era fixa
#define pinEnableMotorA 9      //Porta Digital PWM~
#define pinEnableMotorB 10     //Porta Digital PWM~

//pinos que vão para o motor A
#define pinSentido1MotorA 3
#define pinSentido2MotorA 2

//pinos que vão para o motor B
#define pinSentido1MotorB 7
#define pinSentido2MotorB 6

//------------------------------------------------------------------
// CONFIGURANDO ESTADOS DOS BOTÕES

// parando pra entender essa parte
// percebi que o estado atual depende do estado anterior
// fazendo uma tabela pra chechar isso e definir o sentido atual:

// ant + atual = sentido
// true + true = off 
// true + false = on (ré)
// false + true = on (frente)
// reinicio os dois pra true e repito os 3 estados

byte estadoA = 0;
bool estadoBotaoA = true;
bool estadoAntBotaoA = true;
unsigned long delayBotaoA;

byte estadoB = 0;
bool estadoBotaoB = true;
bool estadoAntBotaoB = true;
unsigned long delayBotaoB;

// vou repetir o processo e criar estados do botao
// pro meu potenciometro ser um acelerometro

bool estadoAcel = true;
bool estadoAntAcel = true;

//------------------------------------------------------------------
// CONFIGURANDO ESTADOS DOS BOTÕES TAMBÉM

void setup() {
  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinBotao, INPUT_PULLUP);
  pinMode(pinEnableMotorA, OUTPUT);
  pinMode(pinEnableMotorB, OUTPUT);

  pinMode(pinSentido1MotorA, OUTPUT);
  pinMode(pinSentido2MotorA, OUTPUT);
  pinMode(pinSentido1MotorB, OUTPUT);
  pinMode(pinSentido2MotorB, OUTPUT);
}

//------------------------------------------------------------------
// DEFININDO PROCESSOS ATRAVÉS DOS BOTÕES

void loop() {

  //----------------------------------------------------------------
  // aqui vamos configurar basicamente os 3 estados do botão A

  estadoBotaoA = digitalRead(pinBotao);
  
  if(not estadoBotaoA and estadoAntBotaoA){

     if( (millis() - delayBotaoA) > 20){    
        estadoA++;
        if (estadoA > 3) estadoA = 0;
        delayBotaoA = millis();
     }

  }else if(estadoBotaoA != estadoAntBotaoA) delayBotaoA = millis();    

  estadoAntBotaoA = estadoBotaoA;

  //----------------------------------------------------------------
  // aqui vamos configurar basicamente os 3 estados do botão B

  estadoBotaoB = digitalRead(pinBotao);

  if(not estadoBotaoB and estadoAntBotaoB){

     if( (millis() - delayBotaoB) > 20){
        estadoB++;
        if (estadoB > 3) estadoB = 0;
        delayBotaoB = millis();
     }

  }else if(estadoBotaoB != estadoAntBotaoB) delayBotaoB = millis();    
  

  estadoAntBotaoB = estadoBotaoB;

  //----------------------------------------------------------------

  if(estadoA == 0){
     
     analogWrite(pinEnableMotorA, 0);
     analogWrite(pinEnableMotorB, 0);
     
  }else if(estadoA == 2){
     
     analogWrite(pinEnableMotorA, 255); 
     digitalWrite(pinSentido1MotorA, HIGH);
     digitalWrite(pinSentido2MotorA, HIGH);    

     analogWrite(pinEnableMotorB, 255); 
     digitalWrite(pinSentido1MotorB, HIGH);
     digitalWrite(pinSentido2MotorB, HIGH);
     
  }else{        
    
    int velAcelerometro = 31;

    estadoAcel = digitalRead(pinAcelerometro);

    if(estadoAcel != estadoAntAcel){

      velAcelerometro += 32;
      if(velAcelerometro > 255) velAcelerometro = 31;
      estadoAntAcel = estadoAcel;
    
    }

    digitalWrite( pinEnableMotorA, velAcelerometro);
    digitalWrite( pinEnableMotorB, velAcelerometro);

     if (estadoA == 1) {

        digitalWrite(pinSentido1MotorA, LOW);
        digitalWrite(pinSentido2MotorA, HIGH);
        digitalWrite(pinSentido1MotorB, LOW);
        digitalWrite(pinSentido2MotorB, HIGH);   

     }else{ // estadoA == 3

        digitalWrite(pinSentido1MotorA, HIGH);
        digitalWrite(pinSentido2MotorA, LOW);      
        digitalWrite(pinSentido1MotorB, HIGH);
        digitalWrite(pinSentido2MotorB, LOW);      

     }
  }

  //----------------------------------------------------------------

}

//------------------------------------------------------------------
