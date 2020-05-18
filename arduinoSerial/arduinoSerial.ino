#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial mySerial(2, 3); // RX, TX

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(115200);
  mySerial.begin(4800);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Native USB only
  }
}

void loop() // run over and over
{
  StaticJsonDocument<200> jsonDoc;
  jsonDoc["id"] = 2;
  jsonDoc["status"] = 1;

  serializeJson(jsonDoc, mySerial);
  serializeJson(jsonDoc, Serial);
  mySerial.println();
  //mySerial.write("Write");
  Serial.println();

  delay(100);
}
