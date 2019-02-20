#include <ESP8266WiFi.h>

const char* ssid = "trillian";
const char* password = "rytykiwi";
//const char* host = "IP OF THE ESP8266";
WiFiServer server(301);

int inputPin = D7;
int outputPin = D6;
int val = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.setTimeout(10);
  delay(100);
  Serial.println(WiFi.localIP());
  pinMode(inputPin, INPUT);
  pinMode(outputPin, OUTPUT);
  // Connect to WiFi network
  Serial.println();
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

  // Start the server
  server.begin();
  Serial.println("Server started");

  // Print the IP address
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  val = digitalRead(inputPin);
  Serial.print(val);
  if (val == 1) {
    digitalWrite(outputPin, HIGH);
    Serial.println("                   Motion detected");
    delay(200);

  } else {
    digitalWrite(outputPin, LOW);
    Serial.println("        No motion");
    delay(200);
  }



}
