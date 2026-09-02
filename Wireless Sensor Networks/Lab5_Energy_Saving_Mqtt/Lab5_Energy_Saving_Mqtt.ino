//"C:\Program Files\Mosquitto"
// mosquitto_sub -h 10.239.25.213 -t test/topic


#include <DHT.h>
#include <WiFi.h>
#include <esp_sleep.h>
#include <PubSubClient.h>

#define SSID "Jeremy Consolidated"
#define PASSWORD "HUAJOVP30"

// #define SSID "MIKAELS WAIFY"
// #define PASSWORD "JovAMIch14%"

#define DHTPIN 4
#define DHTTYPE DHT11 

#define PORT 1883
// #define MQTT_SERVER "192.168.50.220"
#define MQTT_SERVER "10.239.25.213"

DHT dht(DHTPIN, DHTTYPE);

WiFiClient espJovan;
PubSubClient client(espJovan);

//connect to WIFI network
void connect_wifi(){
  WiFi.begin(SSID, PASSWORD);
  Serial.println("Connecting...");

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(200);
  }
  Serial.println("Connected to WiFi.");
}

//convert mqtt data from bytes to string, only for subscribers
void callback(char* topic, byte* payload, unsigned int length){
  Serial.print("Broker back: ");
  for(int i = 0; i < length; i++){
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
//Makes mqtt connection to broker, has ClientID ESP32Client
void reconnect(){
  while(!client.connected()){
    if(client.connect("ESP32Client")){
      // Serial.println(WiFi.localIP());
      Serial.println("connected");
      client.subscribe("test/topic");
    } 
    else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again");
      delay(500);
    }
  }
}
//Some feelings stuff
String tempHum(){
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();
  return "J-Temp: " + String(temp) + "\nJ-Humidity: " + String(hum);
}
// 
void the_work(){
  if(!client.connected()) reconnect();
  client.loop(); //To keep mqtt connection alive, pings keep_alive and calls callback

  char readings[100];
  String msg = tempHum();
  msg.toCharArray(readings, 100);

  client.publish("test/topic", readings);
  Serial.println("Sent to Jovan.");
}
void setup() {
  Serial.begin(115200);
  dht.begin();
  connect_wifi();
  
  client.setServer(MQTT_SERVER, PORT);
  client.setCallback(callback); //can skip for sender node

  the_work();
  delay(500);

  //Sleep for 5 seconds
  esp_sleep_enable_timer_wakeup(1 * 1000000ULL);
  esp_deep_sleep_start();
}

void loop() {

}
