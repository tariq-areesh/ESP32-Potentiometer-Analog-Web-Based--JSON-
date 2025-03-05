#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Tareq2";      
const char* password = "m1h2r2t1";  

WebServer server(80);  

const int pin = 34;

void handleSensorData() {
  int value = analogRead(pin); 
  String json = "{\"value\": " + String(value) + "}";  
  server.sendHeader("Access-Control-Allow-Origin", "*");
  server.send(200, "application/json", json);
}

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  
  Serial.println("\nWiFi connected. IP: " + WiFi.localIP().toString());
  
  server.on("/data", handleSensorData);  
  server.begin();
}

void loop() {
  server.handleClient();  
}
