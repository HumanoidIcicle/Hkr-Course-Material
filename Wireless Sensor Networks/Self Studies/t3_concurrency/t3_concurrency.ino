#define LED1 4
#define LED2 23

void taskFast(void *parameter) {
  while (true) {
    digitalWrite(LED1, HIGH);
    vTaskDelay(100 / portTICK_PERIOD_MS);
    digitalWrite(LED1, LOW);
    Serial.println("led1");
    vTaskDelay(100 / portTICK_PERIOD_MS);
  }
}

void taskSlow(void *parameter) {
  while (true) {
    digitalWrite(LED2, HIGH);
    vTaskDelay(1000 / portTICK_PERIOD_MS);
    digitalWrite(LED2, LOW);
    Serial.println("led2");
    vTaskDelay(1000 / portTICK_PERIOD_MS);
  }
}

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  Serial.begin(115200);
  
  xTaskCreate( //Creates a new task (thread) that runs independently of other tasks
    taskFast,      // 1. Task function pointer
    "Fast Blink",  // 2. Task name (for debugging)
    1024,          // 3. Stack size in bytes
    NULL,          // 4. Task parameters pointer
    1,             // 5. Task priority (0 = lowest, 1 = highest)
    NULL           // 6. Task handle (output)
  );
  
  xTaskCreate(
    taskSlow,
    "Slow Blink",
    1024,
    NULL,
    1,
    NULL
  );
}

void loop() {
  // Empty: tasks run independently
}