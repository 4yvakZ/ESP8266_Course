#include <ESP8266WiFi.h>
 
const char* ssid = "YOUR_SSID";  // для SSID точки доступа
const char* password = "YOUR_PASSWORD";  // для пароля к точке доступа
 
int ledPin = 2; // контакт GPIO2 на ESP8266
WiFiServer server(80);  //  порт веб-сервера
 
void setup() {
  Serial.begin(115200);
  delay(10);
 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
   
  // подключаемся к WiFi-сети:
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");  //  "Подключение к "
  Serial.println(ssid);
   
  WiFi.begin(ssid, password); 
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");");  //  "Подключение к WiFi
                                        //  выполнено"
   
  // запускаем сервер:
  server.begin();
  Serial.println("Server started");  //  "Сервер запущен"
 
  // печатаем IP-адрес:
  Serial.print("Use this URL to connect: ");  //  "Используем этот URL 
                                              //  для подключения: "
  Serial.print("http://");
  Serial.print(WiFi.localIP());
  Serial.println("/");
}
