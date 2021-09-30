#define LED_PIN 2
#define BTN_PIN 14
#define POT_PIN A0
//bool led = false;
int brightness = 0;

void setup() {
  Serial.begin(115200);
  Serial.print("Setup");
  pinMode(LED_PIN, OUTPUT);
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(POT_PIN, INPUT);
}

void loop() {
  //Serial.println("Hello world");
//  digitalWrite(LED_PIN, led);
//  if(!digitalRead(BTN_PIN)){
//    led = !led;
//    Serial.println("Press");
//  }
  analogWrite(LED_PIN, brightness);
  if(brightness<255){
    brightness+=100;
  }else{
    brightness = 0;
  }
  Serial.println(analogRead(POT_PIN));
  delay(100);
}
