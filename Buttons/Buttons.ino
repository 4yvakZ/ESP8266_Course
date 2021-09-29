#define ACTION_BTN_1 4

unsigned long prevMillis;
bool but1[2] = {1, 1};

//void checkBtn() {
//  if (millis() - prevMillis > 100) {
//    but1[0] = but1[1];
//    but1[1] = digitalRead(ACTION_BTN_1);
//    prevMillis = millis();
//  }
//}

void setup() {
  Serial.begin(9600);
  pinMode(ACTION_BTN_1, INPUT_PULLUP);
}

void loop() {
//  checkBtn();
//  if (but1[0] == 0 && but1[1] == 0) Serial.print("Press");
  if(digitalRead(ACTION_BTN_1)) Serial.print("Press");
}
