#include <DHT.h>
#define DHTTYPE DHT11 // XHT11 u s e s DHT11 p r o t o c o l
#define DHTPIN 33

int red = 17;
int green = 5;
int blue = 18;
int LED = 4;
int on = 0;
int button = 27;

DHT dht(DHTPIN, DHTTYPE) ;

void setup() {
  Serial.begin(115200);
  dht.begin();

  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(LED, OUTPUT);
  pinMode(button, INPUT);
}

void toggleLED(){
  if (on == 0) on = 1;
  else on = 0;
}
void RGB(){
  int val;
  for (val = 255; val > 0; val--){
    analogWrite(red, val/2);
    analogWrite(green, 255-val);
    analogWrite(blue, 128-val);
  }
  for (val = 0; val < 255; val++){
    analogWrite(red, val);
    analogWrite(green, 128-val);
    analogWrite(blue, 255-val);
    
  }
}

void loop() {
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  float tempOffset = 1.5;
  float tempCal = temperature + tempOffset;
  
  Serial.print("Humidity: "); Serial.print(humidity); Serial.println(" %");
  Serial.print("Temperature: "); Serial.print(temperature); Serial.println(" C");

  if (digitalRead(button) == HIGH) {
    toggleLED();
    // delay(20);
  }

    Serial.println(on);
  if (on == 1) {
    digitalWrite(LED, HIGH);
  }
  else {
    digitalWrite(LED, LOW);
  }

  RGB();
  //delay(2000);
}
