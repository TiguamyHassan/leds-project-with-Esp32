#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

int BlueLedPin = 16;
int RedLedPin = 17;
int GreenLedPin = 5;

WebServer server(80);

void setup() {

  Serial.begin(115200);

  pinMode(BlueLedPin, OUTPUT);
  pinMode(RedLedPin, OUTPUT);
  pinMode(GreenLedPin, OUTPUT);

  WiFi.begin("WIFI NAME", "WIFI PASSWORD");

  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
  }

  Serial.println(WiFi.localIP());

  server.on("/onblue", []() {
    digitalWrite(BlueLedPin, HIGH);
    server.send(200, "text/plain", "OK");
  });

  server.on("/offblue", []() {
    digitalWrite(BlueLedPin, LOW);
    server.send(200, "text/plain", "OK");
  });

  server.on("/onred", []() {
    digitalWrite(RedLedPin, HIGH);
    server.send(200, "text/plain", "OK");
  });

  server.on("/offred", []() {
    digitalWrite(RedLedPin, LOW);
    server.send(200, "text/plain", "OK");
  });

  server.on("/ongreen", []() {
    digitalWrite(GreenLedPin, HIGH);
    server.send(200, "text/plain", "OK");
  });

  server.on("/offgreen", []() {
    digitalWrite(GreenLedPin, LOW);
    server.send(200, "text/plain", "OK");
  });

  server.begin();
}

void loop() {
  server.handleClient();
}
