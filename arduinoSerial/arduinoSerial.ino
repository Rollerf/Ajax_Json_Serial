#include <SoftwareSerial.h>
#include <ArduinoJson.h>

SoftwareSerial mySerial(2, 3); // RX, TX

int progress;
int estado = 0;
int indice = 0;

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
  StaticJsonDocument<100> jb;
  JsonObject jsonDoc = jb.to<JsonObject>();
  if (estado) {
    estado = 0;
  } else {
    estado = 1;
  }

  switch (indice) {

    case 1:
      Serial.println("case 1");
      jsonDoc["id"] = indice;
      jsonDoc["status"] = estado;
      indice++;
      break;

    case 2:
      Serial.println("case 2");
      jsonDoc["id"] = indice;
      jsonDoc["status"] = estado;
      indice++;
      break;

    case 3:
      Serial.println("case 3");
      jsonDoc["id"] = indice;
      jsonDoc["status"] = estado;
      indice++;
      break;

    case 4:
      Serial.println("case 4");
      jsonDoc["id"] = indice;
      jsonDoc["status"] = estado;
      jsonDoc["progress"] = progress;
      if (progress == 100) {
        progress = 0;
      } else {
        progress = progress + 25;
      }
      indice++;
      break;

    default:
      indice = 1;
      break;
  }

  delay(600);

  serializeJson(jsonDoc, mySerial);
  serializeJson(jsonDoc, Serial);
  mySerial.println();
  Serial.println();
}
