  //----------------------------------------------
  // Hugo Rafael de Lima
  // Programa pra testar no rôbo novo
  //----------------------------------------------
  // bibliotecas e definições
  
  #include <Servo.h>
  
  #define pinMyServo 9
  #define pinPotenciometro A8
  
  Servo myServo;
  int pos = 0;
  
  //----------------------------------------------
  
  void setup( void ){
  
  	// vel do bagulho
  	Serial.begin(9600);
  
    // definindo potenciometro
    pinMode( pinPotenciometro, INPUT );
  
    // definindo myServo
    myServo.attach( pinMyServo );
  
    myServo.write(0);
  
  }
  
  //----------------------------------------------
  
  void loop( void ){
  
    int angulo = map( analogRead(pinPotenciometro), 0, 1023, 0, 179);
  
    myServo.write( angulo );

    delay(500);
 
  
    Serial.print("o angulo ta:");
    Serial.print(angulo);
    Serial.print(" || o servo variou: ");
    Serial.println( myServo.read() );
  
  }
  
  //----------------------------------------------
