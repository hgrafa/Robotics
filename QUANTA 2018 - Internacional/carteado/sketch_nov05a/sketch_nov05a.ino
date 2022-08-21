#include <Servo.h> //Incluimos a livraria servo.h
    
Servo servo1;  // Cria um Objeto servo chamado Servo1 
int pos;  // Definimos a variável que indica a posição do servo 
    
void setup() 
{ 
  servo1.attach(9);  // Selecionamos o pino 9 como o pino de controlo para o servo 
} 
    
void loop()
// Com a função MAP establecemos uma relação proporcional
// entre a pulsação minima (0) com o grau minimo (0 grau)
// e tambem a pulsação maxima (1023) com o grau maximo (180 graus)
{ 
   
  pos = 0;                                  // Estabelecemos o valor da posição a 0 graus
  pos = map(pos, 0, 1023, 0, 180);     // Estabelecemos a relação entre os graus de rotação e o PWM 
  servo1.write(pos);                // Escrevemos a posição com o mapa de valores ao servo 
  delay(2000);                           //  Damos um tempo para que seja capaz de se mover
  pos= 90;                                // Estabelecemos o valor de la posição a 90 graus
  pos = map(pos, 0, 1023, 0, 180);    // Estabelecemos a relação entre os graus de rotação e o PWM 
  servo1.write(pos);                // Escrevemos a posição com o mapa de valores ao servo 
  delay(2000);                           //  Damos um tempo para que seja capaz de se mover 
  pos = 180;                                // Estabelecemos o valor de a posição a 180 graus
  pos = map(pos, 0, 1023, 0, 180);     // Estabelecemos a relação entre os graus de rotação e o PWM 
  servo1.write(pos);                // Escrevemos a posição com o mapa de valores ao servo 
  delay(2000);                           //  Damos um tempo para que seja capaz de se mover
 
}
