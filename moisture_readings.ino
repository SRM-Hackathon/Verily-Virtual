int moisture=A0;
int moisture1 =0;
int moisture_out=13;
void setup() {
  Serial.begin(9600);
  pinMode(moisture_out,OUTPUT);
  pinMode(moisture,INPUT);
}

void loop() {
  moisture1=analogRead(moisture);
  Serial.print("moisture sensor value: ");
  Serial.println(moisture1);
  if(moisture1>500)
  {
    digitalWrite(moisture_out,HIGH);
    
  }
  else
    digitalWrite(moisture_out,LOW);
    delay(1000);
}
