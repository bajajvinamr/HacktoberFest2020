#include <Mouse.h>  
  
const int trigpin= 8;  
const int echopin= 7;  
long duration;  
int distance;  
void setup(){  
  pinMode(trigpin,OUTPUT);  
  pinMode(echopin,INPUT);  
  Serial.begin(9600);  
}  
  
void loop(){  
  digitalWrite(trigpin,HIGH);  
  delayMicroseconds(10);  
  digitalWrite(trigpin,LOW);  
  duration=pulseIn(echopin,HIGH);  
  distance = duration*0.034/2;  
  Serial.println(distance);  
}  
