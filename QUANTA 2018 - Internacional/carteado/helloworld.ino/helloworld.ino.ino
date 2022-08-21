#define pinfrente_esq 53
#define pintras_esq 52
#define pinpwm_esq 3
//===========================================================================
void frente1() {
  unsigned long int anterior;
  anterior = millis();

  while ((millis() - anterior) < 2000) {
    Serial.println("estou em a");
    digitalWrite(pinfrente_esq, LOW);
    digitalWrite(pintras_esq, HIGH);
    analogWrite(pinpwm_esq, 255);
  }
}
//===========================================================================

void frente2() {
  unsigned long int anterior;
  anterior = millis();
  while ((millis() - anterior) < 2000) {
    Serial.println("estou em b");
    digitalWrite(pinfrente_esq, HIGH);
    digitalWrite(pintras_esq, LOW);
    analogWrite(pinpwm_esq, 255);
  }
}
//===========================================================================

void setup() {

  pinMode(pinfrente_esq, OUTPUT);
  pinMode(pintras_esq, OUTPUT);
  pinMode(pinpwm_esq, OUTPUT);
  Serial.begin(9600);
}
//===========================================================================

void loop() {


  frente1();
  frente2();

}
