#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>


int leds[3]= {D0,D1,D2};
int State[3]={LOW,LOW,LOW};
#define firebaseUrl "test1-b8a0a.firebaseio.com"
#define authCode "aLxaTdQTTI5wTGmUrRr4y5CyrcqetomoBC507Wd7"

#define wifiName "DNH"
#define wifiPass "dnh123456"

String chipID = "time";

void setupFirebase(){
  Firebase.begin(firebaseUrl,authCode);
  }

void setupWifi(){
  WiFi.begin(wifiName,wifiPass);
  Serial.println("Hey I'm Connecting");

  while(WiFi.status()!=WL_CONNECTED){
    Serial.println("not connected");
    delay(500);
    }

  Serial.println();
  Serial.println("I'm connecting and IP address: ");
  Serial.println(WiFi.localIP());
  
  }

void setup() {

  Serial.begin(9600);
  setupWifi();
  setupFirebase();
  SetupPinMode();

}

void getData(){
  String path = chipID +"/state";
  FirebaseObject object = Firebase.get(path);

  bool led1 = object.getBool("001");
  bool led2 = object.getBool("002");
  bool led3 = object.getBool("003");

  

  Serial.println("led1: ");
  Serial.println(led1);

  Serial.println();
  Serial.println("led2: ");
  Serial.println(led2);

  Serial.println();
  Serial.println("led3: ");
  Serial.println(led3);

  digitalWrite(leds[0],led1);
  digitalWrite(leds[1],led2);
  digitalWrite(leds[2],led3);
  
  
  }

void loop() {
  //Serial.println("working");
  getData();
 // Firebase.setBool("time/state/001", true);

}

void SetupPinMode(){
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  
  }
  
void turnOnLed(int pin){
  digitalWrite(pin,HIGH); 
  }
void turnOffLed(int pin){
  digitalWrite(pin,LOW); 
  }
