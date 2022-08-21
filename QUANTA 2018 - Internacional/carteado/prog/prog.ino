//--------------------------------------------------------------
// Hugo Rafael de Lima
// código das rodinha
//  A = direita e B = esquerda
//--------------------------------------------------------------

#include <NewPing.h>

//--------------------------------------------------------------
// definindo os pinos

// lado A
#define pinFrente_dir  25
#define pinTras_dir  22
#define pinEnable_dir 2

// lado B
#define pinFrente_esq  53
#define pinTras_esq 52
#define pinEnable_esq 3


#define trigger_pin 50
#define echo_pin 51
#define max_dis 200

NewPing sonar( trigger_pin , echo_pin , max_dis );

//--------------------------------------------------------------
// função que faz ir pra frente

void frente( void ) {



  Serial.println("Estou indo pra frente");

  //lado A
  analogWrite(pinEnable_dir, 255);
  digitalWrite(pinFrente_dir, HIGH);
  digitalWrite(pinTras_dir, LOW);

  // lado B
  analogWrite(pinEnable_esq, 255);
  digitalWrite(pinFrente_esq, HIGH);
  digitalWrite(pinTras_esq, LOW);



}

//--------------------------------------------------------------
// função que faz ir pra trás

void tras( void ) {

  unsigned long long temp = millis();

  while ( (millis() - temp) < 1000 ) {

    Serial.println("Estou indo pra tras");

    // lado A
    analogWrite(pinEnable_dir, 255);
    digitalWrite(pinFrente_dir, LOW);
    digitalWrite(pinTras_dir, HIGH);

    // lado B
    analogWrite(pinEnable_esq, 255);
    digitalWrite(pinFrente_esq, LOW);
    digitalWrite(pinTras_esq, HIGH);
  }

}

//--------------------------------------------------------------

void direita( void ) {


  Serial.println("To virando pra direita");

  // lado A (OFF)
  analogWrite(pinEnable_dir, 25);
  digitalWrite(pinFrente_dir, LOW);
  digitalWrite(pinTras_dir, HIGH);

  // lado B (ON)
  analogWrite(pinEnable_esq, 255);
  digitalWrite(pinFrente_esq, HIGH);
  digitalWrite(pinTras_esq, LOW);


}

//--------------------------------------------------------------

void esquerda( void ) {

  unsigned long long temp = millis();

  while ( (millis() - temp) < 1900 ) {

    Serial.println("To virando pra direita");

    // lado A (OFF)
    analogWrite(pinEnable_dir, 200);
    digitalWrite(pinFrente_dir, HIGH);
    digitalWrite(pinTras_dir, LOW);

    // lado B (ON)
    analogWrite(pinEnable_esq, 0);
    digitalWrite(pinFrente_esq, LOW);
    digitalWrite(pinTras_esq, LOW);
  }

}

void parar() {
  unsigned long int anterior;
  anterior = millis();
  while ((millis() - anterior < 100)) {
    // lado A (OFF)
    analogWrite(pinEnable_dir, 0);
    digitalWrite(pinFrente_dir, LOW);
    digitalWrite(pinTras_dir, LOW);

    // lado B (ON)
    analogWrite(pinEnable_esq, 0);
    digitalWrite(pinFrente_esq, LOW);
    digitalWrite(pinTras_esq, LOW);
  }
}
//--------------------------------------------------------------

void desvia() {
  while ( (sonar.ping_cm() < 50) and (sonar.ping_cm() > 0) )
  //  parar();
  direita();
  delay(500);

}

//--------------------------------------------------------------

void setup( void ) {

  // lado A
  analogWrite(pinEnable_dir, OUTPUT);
  digitalWrite(pinFrente_dir, OUTPUT);
  digitalWrite(pinTras_dir, OUTPUT);

  // lado B
  analogWrite(pinEnable_esq, OUTPUT);
  digitalWrite(pinFrente_esq, OUTPUT);
  digitalWrite(pinTras_esq, OUTPUT);

}

//--------------------------------------------------------------

void loop( void ) {

  frente();

  desvia();

}

//--------------------------------------------------------------
