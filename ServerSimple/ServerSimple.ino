#include <ESP8266WiFi.h>
#include "ESP8266WebServer.h"
#include "page.h"

/* Set these to your desired credentials. */
const char *ssid = "TV Holder";
const char *password = "12345678";

int sliderValue0 = 0;
int sliderValue1 = 20;

ESP8266WebServer server(80);

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println();
  Serial.print("Configuring access point...");
  /* You can remove the password parameter if you want the AP to be open. */
  WiFi.softAP(ssid, password);

  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.on("/", HTTP_GET, [](){
    server.send(200, "text/html", start+String(sliderValue0)+middle+String(sliderValue1)+end);
  });



  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  server.handleClient();
}
