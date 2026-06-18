#include <SCServo.h>  // Make sure to install the SCServo Arduino Library

SMS_STS st;

void setup()
{
  Serial2.begin(1000000, SERIAL_8N1, 48, 47);
  st.pSerial = &Serial2;
}

void loop()
{
  st.WritePosEx(1, 4095, 3400, 50);  // servo(ID1) speed=3400，acc=50，move to position=4095.
  delay(2000);

  st.WritePosEx(1, 2000, 1500, 50);  // servo(ID1) speed=3400，acc=50，move to position=2000.
  delay(2000);
}
