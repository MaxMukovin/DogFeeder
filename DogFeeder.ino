#include "ESP8266WiFi.h"
#include "EspMQTTClient.h" 
#define PUB_DELAY (5 * 1000)

EspMQTTClient client(
  "RingoStarr_RPT",
  "4815162342",
  "dev.rightech.io",
  "mqtt-maxmukovin-1jw42"
);

const int Feed1 = 16;
const int Feed2 = 5;
const int Feed3 = 4;
const int Feed4 = 0;
const int Feed5 = 14;
const int Feed6 = 12;
const int Feed7 = 13;
const int Feed8 = 15;

const int StateON = 0;
const int DelayON = 10*1000;


void setup() {
  pinMode(Feed1, OUTPUT);
  pinMode(Feed2, OUTPUT);
  pinMode(Feed3, OUTPUT);
  pinMode(Feed4, OUTPUT);
  pinMode(Feed5, OUTPUT);
  pinMode(Feed6, OUTPUT);
  pinMode(Feed7, OUTPUT);
  pinMode(Feed8, OUTPUT);

  digitalWrite(Feed1, StateON);
  digitalWrite(Feed2, StateON);
  digitalWrite(Feed3, StateON);
  digitalWrite(Feed4, StateON);
  digitalWrite(Feed5, StateON);
  digitalWrite(Feed6, StateON);
  digitalWrite(Feed7, StateON);
  digitalWrite(Feed8, StateON);
  
  Serial.begin(9600);
}

void onConnectionEstablished() {

  Serial.println("connected");
//Feeder #1
    client.subscribe("base/relay/feed1", [] (const String & payload) {
    Serial.println(payload);
    if (!payload.toInt() == 0){
    digitalWrite(Feed1, payload.toInt());
    delay(DelayON);
    digitalWrite(Feed1, !payload.toInt());
    }
  });
//Feeder #2
    client.subscribe("base/relay/feed2", [] (const String & payload) {
    Serial.println(payload);
    if (!payload.toInt() == 0){
    digitalWrite(Feed2, payload.toInt());
    delay(DelayON);
    digitalWrite(Feed2, !payload.toInt());
    }
  });
//Feeder #3
    client.subscribe("base/relay/feed3", [] (const String & payload) {
    Serial.println(payload);
    if (!payload.toInt() == 0){
    digitalWrite(Feed3, payload.toInt());
    delay(DelayON);
    digitalWrite(Feed3, !payload.toInt());
    }
  });
//Feeder #4
    client.subscribe("base/relay/feed4", [] (const String & payload) {
    Serial.println(payload);
    if (!payload.toInt() == 0){
    digitalWrite(Feed4, payload.toInt());
    delay(DelayON);
    digitalWrite(Feed4, !payload.toInt());
    }
  });
//Feeder #5
    client.subscribe("base/relay/feed5", [] (const String & payload) {
    Serial.println(payload);
    if (!payload.toInt() == 0){
    digitalWrite(Feed5, payload.toInt());
    delay(DelayON);
    digitalWrite(Feed5, !payload.toInt());
    }
  });
//Feeder #6
    client.subscribe("base/relay/feed6", [] (const String & payload) {
    Serial.println(payload);
    if (!payload.toInt() == 0){
    digitalWrite(Feed6, payload.toInt());
    delay(DelayON);
    digitalWrite(Feed6, !payload.toInt());
    }
  });
//Feeder #7
    client.subscribe("base/relay/feed7", [] (const String & payload) {
    Serial.println(payload);
    if (!payload.toInt() == 0){
    digitalWrite(Feed7, payload.toInt());
    delay(DelayON);
    digitalWrite(Feed7, !payload.toInt());
    }
  });
//Feeder #8
    client.subscribe("base/relay/feed8", [] (const String & payload) {
    Serial.println(payload);
    if (!payload.toInt() == 0){
    digitalWrite(Feed8, payload.toInt());
    delay(DelayON);
    digitalWrite(Feed8, !payload.toInt());
    }
  });
}
   
void loop() {
  client.loop();
}
