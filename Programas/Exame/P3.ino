#include <ESP32Servo.h>
#include "ABlocks_DHT.h"

double Humidade;
double Temperatura;
Servo servo_18;
DHT dht23(23,DHT11);
Servo servo_26;

void setup()
{
  	servo_18.attach(18);
	pinMode(23, INPUT);
	servo_26.attach(26);

	Serial.begin(115200);
	Serial.flush();
	while(Serial.available()>0)Serial.read();

	dht23.begin();

	servo_18.write(3);

}


void loop()
{
	yield();

  	Humidade = dht23.readHumidity();
  	Temperatura = dht23.readTemperature();
  	Serial.println(String("Humidade:")+String(Humidade));
  	Serial.println(String("Temperatura:")+String(Temperatura));
  	if (((Humidade > 40) || (Temperatura > 25))) {
  		servo_18.write(90);
  	}
  	else {
  		servo_26.write(3);
  	}

  	delay(2000);

}