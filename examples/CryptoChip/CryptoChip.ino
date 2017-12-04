/*

 This example makes an attempt at using the CryptoChip directly

 */


#include <SPI.h>
#include <CryptoChip.h>

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

CryptoChip chip;
void loop() {
  uint8_t cypher[1] = { 0x03 };
  uint8_t exponent[1] = { 0x02 };
  uint8_t modulus[1] = { 0x07 };
  uint8_t result[1];

  chip.modularExponentiation(cypher, 1, exponent, 1, modulus, 1, result, 1);

  Serial.print("Result is: ");
  printHex(result, 1);
  delay(2000);
}

void printHex(uint8_t *buffer, const uint16_t length) {
  for (word szPos=0; szPos < length; szPos++)
  {
    Serial.print(F("0x"));
    // Append leading 0 for small values
    if (buffer[szPos] <= 0xF) {
      Serial.print(F("0"));
    }
    Serial.print(buffer[szPos]&0xff, HEX);
    if ((length > 1) && (szPos != length - 1))
    {
      Serial.print(F(" "));
    }
  }
  Serial.println();
}