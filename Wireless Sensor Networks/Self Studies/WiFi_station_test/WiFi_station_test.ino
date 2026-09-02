// #include <WiFi.h>

// const char* ssid = "eduroam";
// const char* password = "Gyryve38%Gyryve38%";

// WiFiServer server(80); //Set as wifi server, access point is port 80

// void setup() {
//   Serial.begin(115200);
  // pinMode(27, OUTPUT);

//   Serial.print("\n\nConnecting to ");
//   Serial.println(ssid);

//   WiFi.begin(ssid, password);
#include <WiFi.h>
// #include "esp_wpa2.h" // WPA2 Enterprise
#include "esp_eap_client.h"

const char* ssid = "eduroam";
const char* username = "jovan.ssettuba0001@stud.hkr.se";
const char* password = "GYGY3";

WiFiServer server(80); //Set as wifi server, access point is port 80

void setup() {
  Serial.begin(115200);

  WiFi.disconnect(true);
  WiFi.mode(WIFI_STA);

    pinMode(5, OUTPUT);

  // Initialize WPA2 Enterprise
  // esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)username, strlen(username));
  // esp_wifi_sta_wpa2_ent_set_username((uint8_t *)username, strlen(username));
  // esp_wifi_sta_wpa2_ent_set_password((uint8_t *)password, strlen(password));

  // esp_wpa2_config_t config = WPA2_CONFIG_INIT_DEFAULT();
  // esp_wifi_sta_wpa2_ent_enable(&config);

  // Set identity (usually same as username for eduroam)
  esp_eap_client_set_identity((uint8_t *)username, strlen(username));

  // Set username
  esp_eap_client_set_username((uint8_t *)username, strlen(username));

  // Set password
  esp_eap_client_set_password((uint8_t *)password, strlen(password));

  // Enable WPA2 Enterprise (no config struct needed anymore)
  esp_wifi_sta_enterprise_enable();


  WiFi.begin(ssid);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected. ");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  server.begin();

}


void loop() {
  NetworkClient client = server.accept();  // listen for incoming clients

  if (client) {                     // if you get a client,
    Serial.println("New Client.");  // print a message out the serial port
    String currentLine = "";        // make a String to hold incoming data from the client
    while (client.connected()) {    // loop while the client's connected
      if (client.available()) {     // if there's bytes to read from the client,
        char c = client.read();     // read a byte, then
        Serial.write(c);            // print it out the serial monitor
        if (c == '\n') {            // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
            // and a content-type so the client knows what's coming, then a blank line:
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println();

            // the content of the HTTP response follows the header:
            client.print("Click <a href=\"/H\">here</a> to turn the LED on pin 5 on.<br>");
            client.print("Click <a href=\"/L\">here</a> to turn the LED on pin 5 off.<br>");

            // The HTTP response ends with another blank line:
            client.println();
            // break out of the while loop:
            break;
          } else {  // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /H")) {
          digitalWrite(5, HIGH);  // GET /H turns the LED on
        }
        if (currentLine.endsWith("GET /L")) {
          digitalWrite(5, LOW);  // GET /L turns the LED off
        }
      }
    }
    // close the connection:
    client.stop();
    Serial.println("Client Disconnected.");
  }
}

