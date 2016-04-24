#include <ESP8266WiFi.h>

const char* ssid     = "Your-SSID"; // Your ssid
const char* password = "Your-Pasword"; // Your Password

const int buttonPin = 2; // Button pin
const char* host = "maker.ifttt.com"; // IFTTT maker channel URL
const int httpsPort = 443; // https port number
const char* Key = "Maker-Key"; // Your Maker Channel Key
const char* Event = "Maker-Event-name"; // Your Maker Channel Event Name

void setup() {
Serial.begin(115200);
delay(10);
Serial.println();
WiFi.mode(WIFI_STA);
Serial.println();
Serial.print("Connecting to ");
Serial.println(ssid);
WiFi.begin(ssid, password);
while (WiFi.status() != WL_CONNECTED) {
delay(500);
Serial.print(".");
}
Serial.println("");
Serial.println("WiFi connected");
Serial.println(WiFi.localIP());

pinMode( buttonPin, INPUT_PULLUP ); // internal pull-up 
}

void loop() {
  int buttonVal = digitalRead(buttonPin);
  if (buttonVal == LOW) {
  WiFiClientSecure client;
  Serial.print("connecting to ");
  Serial.println(host);
  if (!client.connect(host, httpsPort)) {
    Serial.println("connection failed");
    return;
  }
  String url = "/trigger/";
  url += Event;
  url += "/with/key/";
  url += Key;

  Serial.print("requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "User-Agent: ESP8266\r\n" +
               "Connection: close\r\n\r\n");

  Serial.println("request sent");
  while (client.connected()) {
    String line = client.readStringUntil('\n');
    if (line == "\r") {
      Serial.println("headers received");
      break;
    }
  }
  String line = client.readStringUntil('\n');
  Serial.println("Feedback IFTTT:");
  Serial.println("==========");
  Serial.println(line);
  Serial.println("==========");
  Serial.println("closing connection");
}
}
