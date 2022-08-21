//----------------------------------------------
// Hugo Rafael de Lima
// Programa pra entender o funcionamento do Servo motor
//----------------------------------------------
// bibliotecas e definições

#include <Servo.h>

Servo myServo;
int pos = 0;

//----------------------------------------------

void setup( void ){

  Serial.begin(9600);

  myServo.attach(9);
  myServo.writeMicroseconds(1500);

}

//----------------------------------------------

void loop( void ){

	if(pos == 180){

		Serial.println("ta no limite");
		pos = 179;
		myServo.write(pos);
		delay(1000);


		Serial.println("girou tudo, agora volta do zero");
		pos = 0;
		myServo.write(pos);
		delay(1000);
	}

	Serial.print("agora vem com ");
	Serial.println(pos);
	pos += 30;
	myServo.write(pos);	
	delay(1000);

}

//----------------------------------------------
