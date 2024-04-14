#include <SoftwareSerial.h>


// RX y TX de HC-06 a pines 0 y 1 de Arduino

SoftwareSerial BTSerial(0, 1); // RX, TX


void setup() {

  // Comenzar comunicación serie con la velocidad predeterminada de 9600 bps

  Serial.begin(9600);

  Serial.println("BT Enabled");


  // Comenzar comunicación serie con el módulo Bluetooth a la velocidad predeterminada de 9600 bps

  BTSerial.begin(9600);

}


void loop() {

  // Comprobar si hay datos disponibles en la comunicación serie

  if (BTSerial.available()) {

    // Leer los datos recibidos

    String data = BTSerial.readString();


    // Enviar los datos a la página web

    if (data == "GET") {

      // Enviar una solicitud GET con los datos del sensor

      BTSerial.println("GET /page?sensor_data=23");

    } else if (data == "POST") {

      // Enviar una solicitud POST con los datos del sensor

      BTSerial.println("POST /page HTTP/1.1");

      BTSerial.println("Host: example.com");

      BTSerial.println("Content-Type: application/x-www-form-urlencoded");

      BTSerial.println("Content-Length: 15");

      BTSerial.println("sensor_data=23");

    }

  }


  // Comprobar si hay datos disponibles en la comunicación serie desde la página web

  if (Serial.available()) {

    // Leer los datos recibidos

    String data = Serial.readString();


    // Enviar los datos al módulo Bluetooth

    BTSerial.println(data);

  }

}