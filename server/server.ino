#include <WiFi.h>
#include <WebSocketsServer.h>

const char* ssid = "ESP32-AP";
const char* password = "";

// Define the LED pin
const int ledPin = 2;

WebSocketsServer webSocket = WebSocketsServer(80);

void setup() {
  Serial.begin(115200);
  Serial.println();

  // Set up WiFi as an access point
  WiFi.softAP(ssid, password);

  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Set up the LED pin
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);  // Ensure the LED is off initially

  // WebSocket event handler
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void loop() {
  webSocket.loop();
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t *payload, size_t length) {
  String receivedText;  // Declare the variable outside the switch statement

  switch(type) {
    case WStype_DISCONNECTED:
      Serial.printf("Client %u disconnected\n", num);
      break;
    case WStype_CONNECTED:
      Serial.printf("Client %u connected\n", num);
      break;
    case WStype_TEXT:
      receivedText = String((char*)payload);

      // Check for specific commands and process them
      if (receivedText == "up") {
        Serial.println("Received 'up' command");
        digitalWrite(ledPin, HIGH);  // Turn on the LED
      } else if (receivedText == "down") {
        Serial.println("Received 'down' command");
        digitalWrite(ledPin, LOW);  // Turn off the LED
      }
      // Do not send any responses back to the JavaScript client
      break;
    case WStype_BIN:
      Serial.printf("Received Binary Message of %u bytes\n", length);
      // Optionally handle binary messages here
      break;
    case WStype_PONG:
      Serial.printf("Pong received\n");
      break;
    case WStype_ERROR:
      Serial.printf("Error occurred\n");
      break;
  }
}
