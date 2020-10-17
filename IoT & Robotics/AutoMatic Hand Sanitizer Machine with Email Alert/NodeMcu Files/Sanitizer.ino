
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


String serverName = "Enter the Ip address";
const char* ssid = "Enter the wifi-username";
const char* password = "Enter the password for wifi-username";

const int pingPin =14;    // trigo pin
const int echoPin =12;
const int pingPin2=4;
const int echoPin2=0;
const int led=13;
const int indicator =  5;
;  // relay output
int hand_counter = 1 ;
int email_trigger = 0;  //not set initialy
void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  pinMode(indicator,OUTPUT);
 
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());
 
  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");
}




void loop() {
   digitalWrite(LED_BUILTIN,HIGH);
   int depth=sensor2(pingPin2,echoPin2);
   int hand_distance=sensor1(pingPin,echoPin);
   Serial.print("depth :");
   Serial.print(depth);
   Serial.print(" \nhand_distance :");
   Serial.print(hand_distance);
   
   Serial.println();
   delay(100);
   
   if(hand_distance<25 && depth<=27)        //and because we only want to spray when tank is full
   
   {
      if (depth<=27){  
         email_trigger = 0 ;             //reset email trigger flag to initial state
      }
    if (hand_counter <1){                //spray sequence nozel on
   
    digitalWrite(indicator,HIGH);
    digitalWrite(LED_BUILTIN,LOW);
    Serial.println("Relay on");
    delay(500);
    hand_counter++;  
    digitalWrite(pingPin,LOW);
    digitalWrite(pingPin2,LOW);
    digitalWrite(indicator,LOW);
    digitalWrite(led,LOW);
   }
   
   else{                                 // let the nozel turned off
     digitalWrite(indicator,LOW);
     digitalWrite(led,LOW);
     
    }
   }
   else {                                // if tank is empty or hand is not placed
    delay(10);
    digitalWrite(indicator,LOW);         //turn spray off
     digitalWrite(led,LOW);
     hand_counter = 0;                   //reset hand_counter flag so that in next loop it can trigger the nozel
    //condition for hand distance
   if (depth>27 && email_trigger == 0){           //send email only when hand is not placed, tank is empty and its first time that conditions are met
      //change threshold for minimum depth
      Serial.println( wifi_http( ));
     
     email_trigger = 1;  //setting email trigger flag indicator of email already sent
   }
   }
}
int sensor1(int pingPin,int echoPin){
  long duration, inches, hand_distance;
   pinMode(pingPin, OUTPUT);
   digitalWrite(pingPin, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin, LOW);
   pinMode(echoPin, INPUT);
   duration = pulseIn(echoPin, HIGH);
   inches = microsecondsToInches(duration);
   hand_distance = microsecondsToCentimeters(duration);
   return hand_distance;
}
 int sensor2(int pingPin2,int echoPin2)
{
    long duration, inches, hand_distance;
   pinMode(pingPin2, OUTPUT);
   digitalWrite(pingPin2, LOW);
   delayMicroseconds(2);
   digitalWrite(pingPin2, HIGH);
   delayMicroseconds(10);
   digitalWrite(pingPin2, LOW);
   pinMode(echoPin2, INPUT);
   duration = pulseIn(echoPin2, HIGH);
   inches = microsecondsToInches(duration);
   hand_distance = microsecondsToCentimeters(duration);
   return hand_distance;
}

long microsecondsToInches(long microseconds) {
   return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds) {
   return microseconds / 29 / 2;
}

int wifi_http( ){

      if(WiFi.status()== WL_CONNECTED){
      HTTPClient http;

      String serverPath = serverName ;
     
      // Your Domain name with URL path or IP address with path
      http.begin(serverPath.c_str());
     
      // Send HTTP GET request
      int httpResponseCode = http.GET();
      Serial.println(http.getString());
      return(httpResponseCode);
}
}
