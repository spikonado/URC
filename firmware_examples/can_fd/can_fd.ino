/*
 * Wiring Guide: Connect the CAN FD peripheral to the board by wiring the CANH and CANL lines to the CANH and CANL pins on the board.
 */

#include <ACAN2517FD.h>  // Make sure to install the ACAN2517FD Arduino Library
#include <SPI.h>

SPIClass hspi(HSPI);
ACAN2517FD can(38, hspi, 41);

#define LED_PIN 2  // Make sure to attach an LED to this pin

void setup()
{
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, HIGH);

  Serial.begin(115200);

  hspi.begin(18, 21, 17);

  Serial.print("sizeof (ACAN2517FDSettings): ");
  Serial.print(sizeof(ACAN2517FDSettings));
  Serial.println(" bytes");
  Serial.println("Configure ACAN2517FD");

  ACAN2517FDSettings settings(
    ACAN2517FDSettings::OSC_4MHz10xPLL, 125 * 1000, DataBitRateFactor::x1);
  settings.mRequestedMode = ACAN2517FDSettings::InternalLoopBack;

  Serial.print("MCP2517FD RAM Usage: ");
  Serial.print(settings.ramUsage());
  Serial.println(" bytes");

  const uint32_t errorCode = can.begin(settings, [] { can.isr(); });
  if (errorCode == 0) {
    Serial.print("Bit Rate prescaler: ");
    Serial.println(settings.mBitRatePrescaler);
    Serial.print("Arbitration Phase segment 1: ");
    Serial.println(settings.mArbitrationPhaseSegment1);
    Serial.print("Arbitration Phase segment 2: ");
    Serial.println(settings.mArbitrationPhaseSegment2);
    Serial.print("Arbitration SJW:");
    Serial.println(settings.mArbitrationSJW);
    Serial.print("Actual Arbitration Bit Rate: ");
    Serial.print(settings.actualArbitrationBitRate());
    Serial.println(" bit/s");
    Serial.print("Exact Arbitration Bit Rate ? ");
    Serial.println(settings.exactArbitrationBitRate() ? "yes" : "no");
    Serial.print("Arbitration Sample point: ");
    Serial.print(settings.arbitrationSamplePointFromBitStart());
    Serial.println("%");
  } else {
    Serial.print("Configuration error 0x");
    Serial.println(errorCode, HEX);
  }
}

static uint32_t gBlinkLedDate = 0;
static uint32_t gReceivedFrameCount = 0;
static uint32_t gSentFrameCount = 0;

void loop()
{
  CANFDMessage frame;
  if (gBlinkLedDate < millis()) {
    gBlinkLedDate += 2000;
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
    const bool ok = can.tryToSend(frame);
    if (ok) {
      gSentFrameCount += 1;
      Serial.print("Sent: ");
      Serial.println(gSentFrameCount);
    } else {
      Serial.println("Send failure");
    }
  }
  if (can.available()) {
    can.receive(frame);
    gReceivedFrameCount++;
    Serial.print("Received: ");
    Serial.println(gReceivedFrameCount);
  }
}
