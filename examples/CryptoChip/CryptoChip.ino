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
  byte cypher[1] = { 0x03 };
  byte exponent[1] = { 0x02 };
  byte modulus[1] = { 0x05 };
  byte result[1];

  chip.modularExponentiation(cypher, 1, exponent, 1, modulus, 1, result, 1);

  Serial.print("Result is: ");
  printHex(result, 1);
  delay(2000);
}

void printHex(byte *buffer, const word length) {
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