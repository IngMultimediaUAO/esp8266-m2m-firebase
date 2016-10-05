#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

// Configure this parameters to run the sketch
#define FIREBASE_HOST "id-del-proyecto.firebaseio.com"
#define FIREBASE_AUTH "token-o-secret-del-proyecto"
#define WIFI_SSID "nombre-red-wifi"
#define WIFI_PASSWORD "password-red-wifi"
#define pinLed 2

void setup() {

  // Initialize the Serial
  Serial.begin(9600);

  // Adjust pinLed as output pin
  pinMode(pinLed, OUTPUT);

  // Connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  
  // Connect to firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

int n = 0;
boolean ledArduino1 = false;
boolean ledArduino2 = false;

void loop() {

  // get valor led arduino2
  ledArduino2 = Firebase.getBool("ledArduino2");
  if(ledArduino2){
    digitalWrite(pinLed, HIGH); // turn on the led
  }else{
    digitalWrite(pinLed, LOW); // turn off the led
  }

  ledArduino1 = Firebase.getBool("ledArduino1");
  // set valor led arduino1
  Firebase.setBool("ledArduino1", !ledArduino1);
  // manejar el error
  if (Firebase.failed()) {
      Serial.print("setting /ledArduino1 failed:");
      Serial.println(Firebase.error());  
      return;
  }
  
  delay(3000);
}
