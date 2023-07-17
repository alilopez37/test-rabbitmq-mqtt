#include "Arduino.h"
#include <WiFi.h>
#include <PubSubClient.h>

const char *ssid = "Politecnica";
const char *pass = "";
char *server = "184.73.232.22";
const int mqttPort = 1883;

char *subscribeTopic = "";
char *publishTopic = "esp32.mqtt";
const char* mqttUser = "guest";
const char* mqttPassword = "guest";

 
WiFiClient espClient;
PubSubClient client(espClient);
 
void setup() {
 
  Serial.begin(115200);
  WiFi.begin(ssid, pass);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
  client.setServer(server, mqttPort);
 
  while (!client.connected()) {
    Serial.println("Connecting to MQTT...");
 
    if (client.connect("ESP32Client", mqttUser, mqttPassword )) {
 
      Serial.println("connected");
 
    } else {
 
      Serial.print("failed with state ");
      Serial.print(client.state());
      delay(2000);
 
    }
  }
 
  if (client.publish(publishTopic, "Hello from ESP32")){
      Serial.print("Msn enviado exitosamente");  
  } else {
      Serial.print("Error en el envio");  
  }
}
 
void loop() {
  client.loop();
}