/*
 * Wiring Guide: Connect the RPLidar A1's TX, RX, and PWM pins to the U1TX/14, U1RX/15, and IO10 pins on the board respectively.
 * Use the board's 5V to power the LiDAR.
 */

#include <lds_all_models.h>  // Make sure to install the LDS Arduino Library

HardwareSerial LidarSerial(1);
LDS * lidar;

const uint16_t PRINT_EVERY_NTH_POINT = 20;

void setupLidar()
{
  lidar = new LDS_RPLIDAR_A1();

  lidar->setScanPointCallback(lidar_scan_point_callback);
  lidar->setPacketCallback(lidar_packet_callback);
  lidar->setSerialWriteCallback(lidar_serial_write_callback);
  lidar->setSerialReadCallback(lidar_serial_read_callback);
  lidar->setMotorPinCallback(lidar_motor_pin_callback);
  lidar->setInfoCallback(lidar_info_callback);
  lidar->setErrorCallback(lidar_error_callback);

  delay(200);

  LidarSerial.begin(lidar->getSerialBaudRate(), SERIAL_8N1, 14, 15);

  delay(200);

  lidar->init();
}

void setup()
{
  Serial.begin(115200);

  setupLidar();

  delay(200);

  LDS::result_t result = lidar->start();
  Serial.print("startLidar() result: ");
  Serial.println(lidar->resultCodeToString(result));
}

void printByteAsHex(uint8_t b)
{
  if (b < 16) Serial.print('0');
  Serial.print(b, HEX);
  Serial.print(' ');
}

void printBytesAsHex(const uint8_t * buffer, uint16_t length)
{
  if (length == 0) return;

  for (uint16_t i = 0; i < length; i++) {
    printByteAsHex(buffer[i]);
  }
}

int lidar_serial_read_callback() { return LidarSerial.read(); }

size_t lidar_serial_write_callback(const uint8_t * buffer, size_t length)
{
  return LidarSerial.write(buffer, length);
}

void lidar_scan_point_callback(
  float angle_deg, float distance_mm, float quality, bool scan_completed)
{
  static int i = 0;

  if (scan_completed) {
    i = 0;
    Serial.print("Scan completed; scans-per-second ");
    Serial.println(lidar->getCurrentScanFreqHz());
  }

  if (i % PRINT_EVERY_NTH_POINT == 0) {
    Serial.print(i);
    Serial.print(' ');
    Serial.print(distance_mm);
    Serial.print(' ');
    Serial.println(angle_deg);
  }
  i++;
}

void lidar_motor_pin_callback(float value, LDS::lds_pin_t lidar_pin)
{
  int pin = (lidar_pin == LDS::LDS_MOTOR_EN_PIN) ? 7 : 10;

  if (value <= (float)LDS::DIR_INPUT) {
    if (value == (float)LDS::DIR_OUTPUT_PWM) {
      if (!ledcAttachChannel(pin, 10000, 11, 2))
        Serial.println("lidar_motor_pin_callback() ledcAttachChannel() error");
    } else
      pinMode(pin, (value == (float)LDS::DIR_INPUT) ? INPUT : OUTPUT);
    return;
  }

  if (value < (float)LDS::VALUE_PWM) {
    // Set constant output
    digitalWrite(pin, (value == (float)LDS::VALUE_HIGH) ? HIGH : LOW);
  } else {
    int pwm_value = ((1 << LIDAR_PWM_BITS) - 1) * value;
    ledcWriteChannel(LIDAR_PWM_CHANNEL, pwm_value);
  }
}

void lidar_info_callback(LDS::info_t code, String info)
{
  Serial.print("LiDAR info ");
  Serial.print(lidar->infoCodeToString(code));
  Serial.print(": ");
  Serial.println(info);
}

void lidar_error_callback(LDS::result_t code, String aux_info)
{
  Serial.print("LiDAR error ");
  Serial.print(lidar->resultCodeToString(code));
  Serial.print(": ");
  Serial.println(aux_info);
}

void lidar_packet_callback(uint8_t * packet, uint16_t length, bool scan_completed) { return; }

void loop() { lidar->loop(); }
