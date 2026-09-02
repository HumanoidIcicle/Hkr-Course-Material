#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>
#include <ArduinoJson.h>
/*
  // cd "C:\Program Files\Mosquitto"
  // mosquitto_sub -h 10.93.169.213 -t sensor/nodes
*/
#define PORT 1883
#define SSID  "Jeremy Consolidated"
#define PASSWORD  "HUAJOVP30"
#define MQTT_SERVER "10.93.169.73"

#define DHTPIN 4
#define DHTTYPE DHT11

WiFiClient sensorNode;
DHT dht(DHTPIN, DHTTYPE);
PubSubClient client(sensorNode);

StaticJsonDocument<200> data; //create json object of size 200 bytes

int counter = 0;
const char* topic = "sensor/nodes";
const char* name = "N2";

void connect_wifi(){
  Serial.println("Connecting WiFi...");
  WiFi.begin(SSID, PASSWORD);

  while(WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(100);
  }
  Serial.println("Connected to WiFi.");
}

 // For the sensor nodes
void reconnect_mqtt(){
  client.setServer(MQTT_SERVER, PORT);
  // client.setCallback(callback);
  Serial.println("Connecting MQTT...");
  
  while(!client.connected()){ //keep trying until connected to mqtt

    if(client.connect("room1")){ //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! CHANGE FOR EACH NODE
      Serial.println("MQTT connected.");
    } 
    else { //Print status code for reason for failed connection
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again");
      delay(500);
    }
  }
}

void DHT11_values(){ //Declare and initialize key:value pairs of sensor data into the json object
  data["nodeName"] = name; 
  data["dht_hum"] = dht.readHumidity() - 7.5;
  data["dht_temp"] = dht.readTemperature() + 5.0;
  data["id"] = counter;
  counter++;
}

void data_to_send(char* output, size_t size){
  dht.begin(); 
  DHT11_values();
  serializeJson(data, output, size); // Flattens the json data object into text able to send over mqtt
}

void publish_sensor_values(){
  // Format data into string and publish it
  char buffer[200];
  data_to_send(buffer, sizeof(buffer));
  client.publish(topic, buffer, false);

  Serial.print("Data published: ");
  Serial.println(buffer);
  delay(500);
}

void setup() {
  Serial.begin(115200); 
  WiFi.begin();
  connect_wifi();
  client.setServer(MQTT_SERVER, PORT);
}

void loop() {
  if(!client.connected()) reconnect_mqtt();
  client.loop(); 
  publish_sensor_values(); // For sensor node
}