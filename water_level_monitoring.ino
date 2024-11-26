#include "UbidotsMicroESP8266.h"

#define TOKEN "BBFF-lElK8mQKsJGmqYqVmLjDBCIFBLFFWP" // Put here your Ubidots TOKEN
#define ID_1 "5b497e8a642ab637bdbe0059" 
//#define ID_2 "Your_variable_ID_here" // Put your variable ID here
#define WIFISSID "abcd" //Put here your Wi-Fi SSID
#define PASSWORD "123456789" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
     pinMode(13,INPUT);
  pinMode(12,INPUT);
  pinMode(16,OUTPUT);
 pinMode(14,INPUT); //client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop(){
if(digitalRead(13)==1)
  {Serial.println("water level low");
    digitalWrite(16,HIGH);
    delay(5000);
 if(digitalRead(12)==0)
    {
    client.add(ID_1, 1);
    //client.add(ID_2, value2);
    client.sendAll(false);
    digitalWrite(16,HIGH);
    delay(5000);
    }
  }
  while(digitalRead(14)==1)
    {
      digitalWrite(16,LOW);
      delay(5000); 
    }
}

