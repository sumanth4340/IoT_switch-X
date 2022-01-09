#define BLYNK_TEMPLATE_ID "TMPLg0EUxVS-"
#define BLYNK_DEVICE_NAME "Switch iot X"
#define BLYNK_FIRMWARE_VERSION        "0.1.0"
#define BLYNK_PRINT Serial
#define BLYNK_DEBUG
#define APP_DEBUG

bool toggleState_1 = LOW;
bool toggleState_2 = LOW; 
bool toggleState_3 = LOW; 
bool toggleState_4 = LOW; 

bool SwitchState_1 = LOW;
bool SwitchState_2 = LOW;
bool SwitchState_3 = LOW;
bool SwitchState_4 = LOW;

#include "BlynkEdgent.h"

BLYNK_CONNECTED() {
  Blynk.syncVirtual(V0);
  Blynk.syncVirtual(V1);
  Blynk.syncVirtual(V2);
  Blynk.syncVirtual(V3);
}

BLYNK_WRITE(V0) {
  toggleState_1 = param.asInt();
  if(toggleState_1 == 1){
    digitalWrite(D5, LOW);
  }
  else { 
    digitalWrite(D5, HIGH);
  }
}

BLYNK_WRITE(V1) {
  toggleState_2 = param.asInt();
  if(toggleState_2 == 1){
    digitalWrite(D1, LOW);
  }
  else { 
    digitalWrite(D1, HIGH);
  }
}

BLYNK_WRITE(V2) {
  toggleState_3 = param.asInt();
  if(toggleState_3 == 1){
    digitalWrite(D2, LOW);
  }
  else { 
    digitalWrite(D2, HIGH);
  }
}

BLYNK_WRITE(V3) {
  toggleState_4 = param.asInt();
  if(toggleState_4 == 1){
    digitalWrite(D8, LOW);
  }
  else { 
    digitalWrite(D8, HIGH);
  }
}

BLYNK_WRITE(V9) {
  all_SwitchOff();
}


void all_SwitchOff(){
  toggleState_1 = 0; digitalWrite(D5, HIGH); Blynk.virtualWrite(V0, toggleState_1); delay(100);
  toggleState_2 = 0; digitalWrite(D1, HIGH); Blynk.virtualWrite(V1, toggleState_2); delay(100);
  toggleState_3 = 0; digitalWrite(D2, HIGH); Blynk.virtualWrite(V2, toggleState_3); delay(100);
  toggleState_4 = 0; digitalWrite(D8, HIGH); Blynk.virtualWrite(V3, toggleState_4); delay(100);
}

void setup()
{
  Serial.begin(115200);

  pinMode(D5, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D8, OUTPUT);


  pinMode(wifiLed, OUTPUT);

  pinMode(D4, INPUT_PULLUP);
  pinMode(D3, INPUT_PULLUP);
  pinMode(D7, INPUT_PULLUP);
  pinMode(D6, INPUT_PULLUP);

  

  digitalWrite(D5, HIGH);
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D8, HIGH);


  BlynkEdgent.begin();
}

void loop() {

    BlynkEdgent.run();
    
    manual_control(); 
}
