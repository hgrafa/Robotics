//-----------------------------------------------------
// Programa para corrigir o caminho do barco
// Feito por Hugo Rafael de Lima
// 05 de novembro de 2018
//-----------------------------------------------------
// bibliotecas e definições

#include <Wire.h>

const int MPU = 0x68;

//-----------------------------------------------------
// variáveis

double acelerometroX, acelerometroY, acelerometroZ;
int temperatura;
double giroscopioX, giroscopioY, giroscopioZ;

//-----------------------------------------------------

void setup( void ){

  Serial.begin(9600); 

  Wire.begin();
  Wire.beginTransmission(MPU);
  
  Wire.write(0x6B);    
  Wire.write(0); 
  Wire.endTransmission(true);

}

//-----------------------------------------------------

void loop( void ){

  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);

  //Solicita os dados do sensor
  Wire.requestFrom(MPU,14,true);  
  
  //Armazena o valor dos sensores nas variaveis correspondentes
  acelerometroX = Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  acelerometroY = Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  acelerometroZ = Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  temperatura = Wire.read()<<8|Wire.read();  //0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  giroscopioX = Wire.read()<<8|Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  giroscopioY = Wire.read()<<8|Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  giroscopioZ = Wire.read()<<8|Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
  
  Serial.print("giroscopioX = ");
  Serial.println( ((giroscopioX)*(giroscopioX))/acelerometroX );
  

  delay(500); 

}

//-----------------------------------------------------
