#include <DHT.h>
#define DHTPIN 4
#define DHTTYPE DHT11 // XHT11 u s e s DHT11 p r o t o c o l
#define LDR_PIN 34

DHT dht(DHTPIN, DHTTYPE) ;

void setup() {
  Serial.begin(115200);
  dht.begin();
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();
  float lightRaw = analogRead(LDR_PIN)/100;

  float tempOffset = 1.5;
  float tempCal = temperature + tempOffset;

  //Moving average filter
  float lightSum = 0;
  int N = 15;
  float latests[15];
  for(int i = 0; i < N; i++){
    lightSum += analogRead(LDR_PIN)/100;
  }
  float lightFiltered = lightSum/N;
  
  // Serial.print(",Raw_Humidity:");
  // Serial.print(humidity);
  // Serial.print("%");
  // Serial.print("Raw_Temp:");
  // Serial.print(temperature);
  // Serial.print("C");
  Serial.print(",Light_raw:");
  Serial.print(lightRaw);
  Serial.print("%");
  // Serial.print(",Cal_Temp:");
  // Serial.print(tempCal);
  // Serial.print("C");
  Serial.print(",Filtered_Light:");
  Serial.println(lightFiltered);
  
  delay(50);
}
