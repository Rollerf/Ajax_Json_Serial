#include <ESP8266WiFi.h>
#include <ESPAsyncWebServer.h>
#include <FS.h>
#include <ArduinoJson.h>
#include<SoftwareSerial.h>

#include "config.h"  // Sustituir con datos de vuestra red
#include "API.hpp"
#include "Server.hpp"
#include "ESP8266_Utils.hpp"

SoftwareSerial mySerial(D2, D3); // RX, TX 1-D1 3-D0

void setup(void)
{
  Serial.begin(115200);
  SPIFFS.begin();
  mySerial.begin(4800);
  pinMode(D2, INPUT);
  pinMode(D3, OUTPUT);

  ConnectWiFi_STA(true);

  InitServer();
}

void loop(void)
{
  if (mySerial.available()) {
      String input = mySerial.readStringUntil('\n');
      setInput(input);
      Serial.println(input);
    }
}
