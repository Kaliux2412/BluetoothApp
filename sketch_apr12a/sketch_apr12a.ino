#include <SoftwareSerial.h>
SoftwareSerial BT(1, 0); //Los pines donde se ecnuetran 1RX, 0TX (no sé exactamente donde, así que modificalo)

char DataBluetooth = ' ';
byte led_1 = 5; //Pon el pin que tenga el led para probar la conectividad
char CharIN = ' ';

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);
  Serial.println("Iniciando Programa ...");
  pinMode(led_1, OUTPUT);


}
void loop()
{
  if(BT.available())
  {
    ChatIN = BT.read();
    Serial.print(CharIN);
    if(CharIN == 'a'){digitalWrite(led_1, HIGH);}
    if(CharIN == 'b'){digitalWrite(led_1, LOW);}
  }
}