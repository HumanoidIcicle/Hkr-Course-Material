#include <WiFi.h>
#include <WiFiUdp.d>

const char* SSID = "Network name";
const char* password = "";

// const char* ssid = "eduroam";
// const char* username = "jovan.ssettuba0001@stud.hkr.se";
// const char* password = "Gyryve38%Gyryve38%";

WiFiUDP udp;
const int receiverPort = 12345;

void setup() {
  Serial.begin(115200);

  WiFi.begin(SSID, password);
  
  while(WiFi.status() != WLCONNECTED){
    delay(500);
    Serial.println("Connecting...");
  }
  Serial.println("Connected to WiFi.");
{
  // // Set identity (usually same as username for eduroam)
  //   esp_wifi_sta_wpa2_ent_set_identity((uint8_t *)username, strlen(username));


  // // Set username
  //   esp_wifi_sta_wpa2_ent_set_username((uint8_t *)username, strlen(username));


  // // Set password
  // esp_wifi_sta_wpa2_ent_set_password((uint8_t *)password, strlen(password));

  // // Enable WPA2 Enterprise (no config struct needed anymore)
  // esp_wifi_sta_enterprise_enable();
  // // or
  // esp_wifi_sta_wpa2_ent_enable();

  // WiFi.begin(ssid);
}
  udp.begin(receiverPort);
  Serial.println("Receiver ready.");
}

void loop() {
  int packetSize = udp.parsePacket();

  if(packetSize){
    char incoming[255];
    int len = udp.read(incoming, 255);

    if (len >0){
      incoming[len] = 0;
    }
    
    Serial.print("Receive: ");
    Serial.println(incoming);
  }
}
















