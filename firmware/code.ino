#include <Wire.h>

#define AS5600_ADDR      0x36
#define AS5600_RAW_ANGLE 0x0C
#define BUZZER_PIN       0

uint16_t readAngle() {
  Wire.beginTransmission(AS5600_ADDR);
  Wire.write(AS5600_RAW_ANGLE);
  if (Wire.endTransmission(false) != 0) return 0xFFFF; // I2C error
  Wire.requestFrom(AS5600_ADDR, 2);
  uint16_t hi = Wire.read();
  uint16_t lo = Wire.read();
  return ((hi << 8) | lo) & 0x0FFF; // 12-bit value, 0-4095
}

void setup() {
  Serial.begin(115200);
  Wire.setSDA(6);
  Wire.setSCL(7);
  Wire.begin();
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  uint16_t raw = readAngle();
  if (raw != 0xFFFF) {
    float deg = raw * 360.0f / 4096.0f;
    int frequency = map(raw, 0, 4095, 200, 1000);
    tone(BUZZER_PIN, frequency);
    Serial.print("Angle: ");
    Serial.print(deg);
    Serial.print(" degrees  Frequency: ");
    Serial.print(frequency);
    Serial.println(" Hz");
  }
  delay(20);
}