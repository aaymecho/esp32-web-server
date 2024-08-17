#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include "config.h"

AsyncWebServer server(80);

const int ledPin4 = 4;
const int ledPin5 = 5;
bool led4State = false;
bool led5State = false;

void setup() {
  Serial.begin(115200);
  pinMode(ledPin4, OUTPUT);
  pinMode(ledPin5, OUTPUT);

  WiFi.begin(SSID, PASSWORD);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");
  Serial.println(WiFi.localIP());

  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");

  server.on("/led/4/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin4, HIGH);
    led4State = true;
    request->send(200, "text/plain", "LED 4 is ON");
    Serial.println("LED 4 turned ON");
  });

  server.on("/led/4/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin4, LOW);
    led4State = false;
    request->send(200, "text/plain", "LED 4 is OFF");
    Serial.println("LED 4 turned OFF");
  });

  server.on("/led/5/on", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin5, HIGH);
    led5State = true;
    request->send(200, "text/plain", "LED 5 is ON");
    Serial.println("LED 5 turned ON");
  });

  server.on("/led/5/off", HTTP_GET, [](AsyncWebServerRequest *request){
    digitalWrite(ledPin5, LOW);
    led5State = false;
    request->send(200, "text/plain", "LED 5 is OFF");
    Serial.println("LED 5 turned OFF");
  });

  server.on("/led/4/status", HTTP_GET, [](AsyncWebServerRequest *request){
    String state = led4State ? "ON" : "OFF";
    request->send(200, "text/plain", state);
  });

  server.on("/led/5/status", HTTP_GET, [](AsyncWebServerRequest *request){
    String state = led5State ? "ON" : "OFF";
    request->send(200, "text/plain", state);
  });

  server.begin();
}

void loop() {
  // Your main loop code here
}
