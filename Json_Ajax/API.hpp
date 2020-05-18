#include "ESP8266_Utils_APIREST.hpp"
String input;

void setInput(String inputParametro) {
  input = inputParametro;
}

void getData(AsyncWebServerRequest *request)
{
  AsyncResponseStream *response = request->beginResponseStream("application/json");

  //Aqui recibe el JSON del arduino y lo manda a la web

  DynamicJsonDocument doc(1024);
  StaticJsonDocument<300> jsonDoc;
  deserializeJson(doc, input);
  JsonObject obj = doc.as<JsonObject>();
  serializeJson(obj, *response);

  request->send(response);
}

void setData(AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total)
{
  String bodyContent = GetBodyContent(data, len);

  StaticJsonDocument<200> doc;
  DeserializationError error = deserializeJson(doc, bodyContent);
  if (error)
  {
    request->send(400);
    return;
  }

  int id = doc["id"];
  bool ledStatus = doc["status"];
  Serial.println(id);
  Serial.println(ledStatus);
  // hacer acciones con los datos recibidos

  request->send(200);
}
