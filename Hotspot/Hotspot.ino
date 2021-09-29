#include <ESP8266WiFi.h>

void setup() {
  Serial.begin(115200);
  Serial.println();

  Serial.print("Setting soft-AP ... ");
  //  "Настройка программной точки доступа ... "
  boolean result = WiFi.softAP("ESPsoftAP_01", "pass-to-soft-AP");
  if (result == true) {
    Serial.println("Ready");
    //  "Готово"
  }
  else {
    Serial.println("Failed!");
    //  "Настроить точку доступа не удалось"
  }
}

void loop() {
  Serial.printf("Stations connected = %d\n", WiFi.softAPgetStationNum());
  //  "Количество подключенных станций = "
  delay(3000);
}
