#include <ESP8266WiFi.h>
#include <Firebase.h>
#include <FirebaseArduino.h>
#include <FirebaseCloudMessaging.h>
#include <FirebaseError.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <stdlib.h>

#define FIREBASE_HOST "iot-hara-default-rtdb.europe-west1.firebasedatabase.app"
#define FIREBASE_AUTH "kxYYO3otxe8awqHTfqJ9GtnRr3BQSuCs04mq4ar2"
#define WIFI_SSID "COLAKHODZIC"
#define WIFI_PASSWORD "123senad" 



#define led1 D2
#define led2 D3
String led1Status = "";  
String led2Status = ""; 
//int led = D2; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
  Serial.print("Connecting...");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected: ");
  Serial.println(WIFI_SSID);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  if (Firebase.failed()) {
    Serial.print(Firebase.error());
  } else {
    Serial.println("Firebase connected");
  }

}


void loop() {
  
   led1Status = Firebase.getString("LED1STATUS");     
   led2Status = Firebase.getString("LED2STATUS"); 

  led1Status == "ON" ? digitalWrite(led1, HIGH) : digitalWrite(led1, LOW);   
  led2Status == "ON" ? digitalWrite(led2, HIGH) : digitalWrite(led2, LOW);  

}
