
#include <SoftwareSerial.h>
SoftwareSerial NodeMcu(3,2);
#include<dht.h>
dht DHT;
#define DHT11_PIN 5
int M1=A5;
int M2=A4;
int ldr_sensor=A3;
int pir_sensor=A2;
int M1_out=8;
int M2_out=9;
int ldr_out=11;
int temp_out=10;
int pir_out=12;
 void setup() {
  // put your setup code here, to run once:
 Serial.begin(9600);
 NodeMcu.begin(4800);
 pinMode(M1,INPUT);
 pinMode(M2,INPUT);
 pinMode(ldr_sensor,INPUT);
 pinMode(pir_sensor,INPUT);
 pinMode(M1_out,OUTPUT);
 pinMode(M2_out,OUTPUT);
 pinMode(ldr_out,OUTPUT);
 pinMode(temp_out,OUTPUT);
 pinMode(pir_out,OUTPUT);
 
}
 void loop() {
   long moisture1=analogRead(M1);
   long moisture2=analogRead(M2);
   long ldr=analogRead(ldr_sensor);
   int temp_val = DHT.read11(DHT11_PIN);
long humidity=DHT.humidity;
long pir=analogRead(pir_sensor);
 long temp=DHT.temperature;
    NodeMcu.print(moisture1);
   NodeMcu.println("\n");
   Serial.println("Moisture in Region 1: ");
   Serial.println(moisture1);
   if(moisture1>300)
   digitalWrite(M1_out,HIGH);
   else
   digitalWrite(M1_out,LOW);
   
   
   delay(15);
    NodeMcu.print(moisture2);
   NodeMcu.println("\n");
   Serial.println("Moisture in Region 2: ");
   
   Serial.println(moisture2);
   if(moisture2>300)
   digitalWrite(M2_out,HIGH);
   else
   digitalWrite(M2_out,LOW);
   
   delay(15);
   NodeMcu.print(ldr);
   NodeMcu.println("\n");
   Serial.println("Light amount: ");
   Serial.println(ldr);
   if(ldr>150)
   digitalWrite(ldr_out,HIGH);
   else
   digitalWrite(ldr_out,LOW);
   
   
   delay(15);
   NodeMcu.print(temp);
   NodeMcu.println("\n");
   Serial.print(" Temparature in Degree Celsius ");
   Serial.println(DHT.temperature, 1);
   if(temp>20)
   digitalWrite(temp_out,HIGH);
   else
   digitalWrite(temp_out,LOW);
 
   
   delay(15);
   NodeMcu.print(humidity);
   NodeMcu.println("\n");
   
   Serial.print("Relative humidity %: ");
   Serial.println(DHT.humidity, 1);
   Serial.println(humidity);
   
 
   delay(15);
   NodeMcu.print(pir);
   NodeMcu.println("\n");
   Serial.println("Motion: ");
   Serial.println(pir);
   if(pir>150)
   digitalWrite(pir_out,HIGH);
   else
   digitalWrite(pir_out,LOW);
   
   
    delay(1500);
 }
