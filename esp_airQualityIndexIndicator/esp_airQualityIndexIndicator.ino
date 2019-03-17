#include <ESP8266WiFi.h>

#include "led.h"

led_t rgbLed;
char r_value,g_value,b_value;


const char* ssid = "xxx";
const char* password = "xxx";


void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Air Quality Index Indicator");
  
  led_Setup(&rgbLed, 12, 13, 15);

  pinMode(16, INPUT);           // set pin to input
  pinMode(4, INPUT);           // set pin to input
  pinMode(5, INPUT);           // set pin to input
  
  /*
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  */
}

void loop() {
  
  //Serial.println(analogRead(A0));

  if (digitalRead(16)) {
    if (r_value < 255) {
      r_value++;
    }
  } else {
    if (r_value > 0) {
      r_value--;
    }
  }
  
  if (digitalRead(4)) {
    if (g_value < 255) {
      g_value++;
    }
  } else {
    if (g_value > 0) {
      g_value--;
    }
  }
  
  if (digitalRead(5)) {
    if (b_value < 255) {
      b_value++;
    }
  } else {
    if (b_value > 0) {
      b_value--;
    }
  }
  
  delay(5);
  led_SetColor(&rgbLed, r_value, g_value, b_value);
  led_Poll(&rgbLed);
}
