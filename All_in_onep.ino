#include<dht.h>
dht DHT;
#define DHT11_PIN 3
////////////////////////
int moisture=A0;
int moisture1 =0;
///////////////////////
const int ledPin = 13;

const int ldrPin = A3;

void setup() 
{

  Serial.begin(9600);
  pinMode(moisture,INPUT);
  pinMode(ldrPin, INPUT);
  pinMode(ledPin, OUTPUT);
  // put your setup code here, to run once:

}

void loop() {
int chk = DHT.read11(DHT11_PIN);
Serial.print(" Humidity " );

Serial.println(DHT.humidity, 1);
Serial.println("x");
delay(1000);

Serial.print(" Temparature ");

Serial.println(DHT.temperature, 1);
Serial.println("y");
delay(1000);


//////////////////////////
moisture1=analogRead(moisture);
  Serial.print("moisture sensor value: ");
  Serial.println(moisture1);

  Serial.println("z");
  delay(1000);
/////////////////////////////
int ldrStatus = analogRead(ldrPin);

if (ldrStatus <= 200) 
{

digitalWrite(ledPin, HIGH);

Serial.print("Its DARK, Turn on the LED : ");

Serial.println(ldrStatus);
Serial.println("a");
delay(1000);

} 
else {

digitalWrite(ledPin, LOW);

Serial.print("Its BRIGHT, Turn off the LED : ");

Serial.println(ldrStatus);

Serial.println("b");
delay(1000);
}



}
