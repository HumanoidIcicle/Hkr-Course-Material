//Photoresistor on IO34
//Temperature on IO32
#define TempSensorPin 32   //ADC1_4;
#define PhotoSensorPin 34  //ADC1_6;
#define LED 23

SemaphoreHandle_t serialMutex;  //Create mutex object

void taskLED(void* p) {
  while (true) {
    digitalWrite(LED, HIGH);
    vTaskDelay(pdMS_TO_TICKS(1000));
    digitalWrite(LED, LOW);
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
void taskBefore(void* p) {
  while (true) {
    int T_val = analogRead(TempSensorPin);
    int P_val = analogRead(PhotoSensorPin);

    if (xSemaphoreTake(serialMutex, portMAX_DELAY) == pdTRUE) {
      Serial.println("Raw ADC:");
      Serial.println("Temp: ");
      Serial.println(T_val);
      vTaskDelay(pdMS_TO_TICKS(1000));
      Serial.println("Light: ");
      Serial.println(P_val);

      xSemaphoreGive(serialMutex);
    }
    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}
void taskAfter(void* p) {
  while (true) {
    int T_val = analogReadMilliVolts(TempSensorPin);
    int P_val = analogReadMilliVolts(PhotoSensorPin);

    if (xSemaphoreTake(serialMutex, portMAX_DELAY) == pdTRUE) {
      Serial.println("Callibrated:");
      Serial.println("Temp: ");
      Serial.println(T_val);
      vTaskDelay(1000);
      Serial.println("Light: ");
      Serial.println(P_val);

      xSemaphoreGive(serialMutex);
    }
    vTaskDelay(pdMS_TO_TICKS(5000));
  }
}

void setup() {
  pinMode(LED, OUTPUT);
  serialMutex = xSemaphoreCreateMutex();  //initialise mutex

  Serial.begin(115200);
  analogReadResolution(12);
  analogSetAttenuation(ADC_11db);
  xTaskCreate(taskLED, "Blink LED", 1024, NULL, 3, NULL);
  xTaskCreate(taskBefore, "Not Callibrated", 1024, NULL, 1, NULL);
  xTaskCreate(taskAfter, "Callibrited", 1024, NULL, 2, NULL);
}

void loop() {
}
