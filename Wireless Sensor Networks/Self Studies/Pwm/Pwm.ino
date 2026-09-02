int pin = 2;
int freq = 1000; // 5kHz
int res = 8; // 8 bits, 255 max resolution
int duty = 10;

void dim(void* p){
  while(1){
    for(int duty = 1; duty < 255; duty++) {
      ledcWrite(pin, duty);
      vTaskDelay(pdMS_TO_TICKS(10));}
  }
}
void setup() {
  ledcAttach(pin, freq, res);
  // xTaskCreate(dim, "Diming", 2048, NULL, 1, NULL);
}

void loop() {
  ledcWrite(pin, duty);
}

/*
  To include pwm in freeRTOS task, PWM runs on ledc hardware
  after setup, the signal runs independently.
  Tasks can only change the duty cycle.
  Resolution and frequency are connected.
  High res -> low freq
  Low res -> high freq

  Too low freq on LED, can see the flickers (rec 5khz, 8 bits)
  Too low freq on motor, whining (rec 20khz, 10 bits)
  Servo (rec 50khz, 16 bits)
*/