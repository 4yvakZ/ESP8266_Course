#include <ESP8266WiFi.h>
#include <WiFiManager.h>
#include "ESP8266WebServer.h"
#include "page.h"

WiFiManager wifiManager;

ESP8266WebServer server(80);

void setup() {

  Serial.begin(115200);
  while (!Serial);

  delay(1000);
  Serial.print("\n");

  wifiManager.autoConnect("TV Holder Config");

  server.on("/", HTTP_GET, []() {
    server.send(200, "text/html", index_html);
  });

  Serial.print("Ready!!!\n");
  server.begin();
}

void loop() {
  server.handleClient();
}
