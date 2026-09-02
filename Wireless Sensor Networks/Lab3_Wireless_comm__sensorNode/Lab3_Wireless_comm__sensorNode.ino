#include <DHT.h>
#include <WiFi.h>
#include <WiFiUdp.h>

#define DHTTYPE DHT11 // XHT11 uses DHT11 protocol
#define DHTPIN 27

const char* ssid = "Jeremy Consolidated";
const char* password = "HUAJOVP30";
// const char* ssid = "Su";
// const char* password = "rutw165wemqpd";

const char* receiverIP = "10.239.25.64";
const int receiverPort = 12345;

DHT dht(DHTPIN, DHTTYPE);

WiFiUDP udp;

void setup() {
  dht.begin();
  Serial.begin(115200);

  Serial.println("Connecting");
  // Set identity (usually same as username for eduroam)
    esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)username, strlen(username));

  // Set username
    esp_wifi_sta_wpa2_ent_set_username((uint8_t *)username, strlen(username));

  // Set password
  esp_wifi_sta_wpa2_ent_set_password((uint8_t *)password, strlen(password));

  // Enable WPA2 Enterprise (no config struct needed anymore)
  // esp_wifi_sta_enterprise_enable();
  // or
  esp_wifi_sta_wpa2_ent_enable();

  WiFi.begin(ssid);
  // WiFi.begin(ssid, password);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected to WiFi.");
}

int count = 0;

void loop() {
  float temp = dht.readTemperature();
  float tempOffset = 1.5;
  float tempCal = temp + tempOffset;

  String msg = String(tempCal);
  String c = " No: " + String(count);

  udp.beginPacket(receiverIP, receiverPort);
  udp.print(msg);
  udp.print(c);
  count++;
  udp.endPacket();

  // delay(1000);
  // delay(200);
  delay(50);

}
