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


void loop() {
  CryptoChip chip;
  //byte cypher[256] = { 0x15, 0xEA, 0x94, 0x70, 0x06, 0x83, 0xD0, 0xF2, 0xCB, 0x4F, 0xAF, 0x2A, 0xC3, 0x11, 0xDE, 0xF4, 0xB7, 0x74, 0x20, 0xF3, 0x2D, 0x6C, 0x13, 0x20, 0x56, 0x42, 0xB5, 0x67, 0x09, 0x41, 0xE3, 0xB5, 0x70, 0x66, 0xD5, 0xC2, 0x6F, 0xDC, 0xA7, 0x03, 0x99, 0x78, 0xDC, 0x55, 0xBD, 0x92, 0x2D, 0x8B, 0x5A, 0xD9, 0xF3, 0x2A, 0x7E, 0x91, 0xFC, 0x2C, 0x55, 0xBB, 0x62, 0x03, 0xA0, 0x01, 0x62, 0xC2, 0x4D, 0xCC, 0x04, 0x5E, 0xB5, 0x35, 0x33, 0x5B, 0x5C, 0x47, 0x1A, 0x3E, 0x25, 0x02, 0x6E, 0x09, 0x8A, 0xE0, 0x15, 0xC1, 0x31, 0xB8, 0x53, 0xD9, 0x22, 0x16, 0x72, 0xF2, 0xC3, 0xE2, 0x05, 0x5C, 0x35, 0x53, 0x2F, 0x90, 0x6D, 0xC4, 0x01, 0x92, 0x38, 0x78, 0xD3, 0x74, 0xF3, 0x08, 0x55, 0x52, 0x3F, 0xBC, 0xC1, 0x26, 0xAD, 0x4D, 0xBC, 0x90, 0x20, 0x6B, 0xA6, 0x4F, 0x7E, 0xB1, 0x15, 0xDE, 0xE3, 0x7E, 0x01, 0xFE, 0xF6, 0xE4, 0x74, 0x94, 0x2E, 0x6F, 0x71, 0x05, 0x57, 0x50, 0x7F, 0x3C, 0xC9, 0x72, 0x76, 0x82, 0xCA, 0xFC, 0xC1, 0x55, 0x01, 0xA6, 0x55, 0xDC, 0xA8, 0x41, 0xFC, 0xB2, 0x8E, 0xE1, 0x9A, 0xF8, 0x95, 0x72, 0x34, 0x1C, 0xF0, 0x79, 0xDE, 0xCD, 0xA4, 0xEE, 0xC6, 0xCB, 0x4C, 0x39, 0x4E, 0x66, 0x6A, 0x9A, 0x1C, 0x41, 0x92, 0x0C, 0xE6, 0x2B, 0x84, 0x69, 0x42, 0xD7, 0xB6, 0xE0, 0x15, 0x46, 0xB7, 0x6D, 0x5E, 0xC5, 0x92, 0x1E, 0x3E, 0x4C, 0xB6, 0xBC, 0x5F, 0x81, 0x59, 0xD3, 0xC7, 0x70, 0x93, 0x08, 0x94, 0x50, 0x1C, 0xEB, 0x73, 0x82, 0x30, 0x12, 0x40, 0x14, 0xB0, 0x7C, 0xDB, 0x48, 0xBF, 0x51, 0x20, 0xC5, 0xC1, 0xA2, 0xF5, 0x24, 0xA5, 0xED, 0xCB, 0x7F, 0xE4, 0xBB, 0x76, 0x97, 0xD3, 0x17, 0x8D, 0x07, 0xA5, 0x4A, 0x6A, 0x01, 0xE3, 0xA4, 0x78, 0x56 };
  byte cypher[256] = { 0x21, 0xB2, 0x8E, 0xCC, 0x0F, 0xF5, 0xC0, 0x3C, 0x80, 0x91, 0x51, 0x24, 0xCF, 0xF1, 0x78, 0x63, 0x0D, 0xEC, 0xF1, 0xD7, 0xD1, 0x1D, 0x26, 0x42, 0x9C, 0xF9, 0x84, 0xE2, 0x79, 0x33, 0x74, 0xDC, 0xEF, 0x77, 0x60, 0xE7, 0xD3, 0x34, 0xEA, 0x77, 0x7F, 0x6A, 0x15, 0x16, 0xE2, 0x9E, 0xFD, 0x12, 0x50, 0xA3, 0x5A, 0xE2, 0xEF, 0xDB, 0x6B, 0xD2, 0xA2, 0x3A, 0x20, 0xA8, 0x7D, 0x03, 0x51, 0x38, 0x30, 0xD8, 0x47, 0x1B, 0x2A, 0xFF, 0xD0, 0x3C, 0xC3, 0x40, 0xD2, 0xCE, 0xAE, 0x52, 0x0C, 0x29, 0x4C, 0x63, 0xFC, 0xBB, 0xD0, 0x65, 0x4A, 0x63, 0xC2, 0xED, 0x0C, 0xA1, 0x00, 0x1F, 0x08, 0x2C, 0x5C, 0xA2, 0x83, 0x3E, 0xC6, 0xAA, 0x08, 0x38, 0x59, 0x2D, 0x92, 0xEF, 0xFC, 0x7E, 0x96, 0x85, 0x80, 0xB7, 0xA0, 0xDD, 0xAE, 0xFD, 0x10, 0x52, 0xA3, 0xFF, 0x42, 0xD0, 0x92, 0xDB, 0x6F, 0x78, 0x36, 0xA3, 0x3A, 0xD4, 0xE3, 0x6A, 0x0C, 0x83, 0x92, 0xE2, 0xAF, 0x11, 0x67, 0x82, 0x29, 0x5A, 0x49, 0x42, 0x25, 0x11, 0xC2, 0x1A, 0xB2, 0xCE, 0x1F, 0xE5, 0xD2, 0xD7, 0xB9, 0xF1, 0xE8, 0xBF, 0xC5, 0xD5, 0xBA, 0x3A, 0x18, 0x8D, 0x80, 0x55, 0xFC, 0x56, 0xEC, 0x50, 0x03, 0x10, 0x8C, 0xD9, 0x23, 0x42, 0x3D, 0x7B, 0xF5, 0x9B, 0xC4, 0x3E, 0xFC, 0x60, 0x5F, 0xA3, 0x21, 0x48, 0xE9, 0xDD, 0x22, 0x2E, 0x78, 0x83, 0x80, 0x74, 0xD7, 0x4C, 0xDE, 0x2C, 0x2E, 0x1F, 0xAB, 0xEA, 0xA9, 0xD9, 0xFC, 0xA0, 0x36, 0x60, 0x4C, 0xDF, 0x09, 0xDF, 0xD3, 0x8A, 0xF6, 0x83, 0x36, 0x12, 0x84, 0x76, 0x82, 0x23, 0xAA, 0xDF, 0xD6, 0x6C, 0x3D, 0xFF, 0x57, 0x32, 0xD7, 0x4E, 0x4F, 0x18, 0x34, 0xC4, 0x55, 0xAF, 0x0C, 0x7B, 0x78, 0xF5, 0x99, 0x55, 0x14, 0xB0, 0x42, 0x87, 0x88, 0x2A, 0xED, 0x23 };
  byte exponent[3] = { 0x01, 0x00, 0x01 };
  byte modulus[256] = { 0xB4, 0x7B, 0x13, 0x96, 0x98, 0x81, 0x38, 0x97, 0x4E, 0xA6, 0xF4, 0x12, 0x67, 0x7B, 0xEE, 0x9E, 0xDB, 0x81, 0x9B, 0x48, 0x3F, 0x7A, 0xFB, 0x84, 0x70, 0x85, 0xE4, 0x9A, 0xBC, 0x9C, 0x34, 0x0A, 0x3F, 0x13, 0x2D, 0x91, 0xEB, 0x2D, 0xA5, 0x0A, 0xAD, 0x1A, 0x54, 0xC4, 0xFD, 0x11, 0x32, 0xE0, 0x36, 0xF0, 0x25, 0x3B, 0x61, 0x60, 0xFE, 0xCF, 0x5A, 0x86, 0xFA, 0xB7, 0xC1, 0xCC, 0x6B, 0x11, 0x7A, 0xA8, 0x00, 0xE8, 0x8D, 0xBF, 0xEA, 0xDB, 0xDF, 0x72, 0xE2, 0xC8, 0x4E, 0x9A, 0x46, 0x2A, 0x93, 0xC7, 0x9F, 0xC5, 0x58, 0x09, 0xD7, 0xFC, 0x92, 0x64, 0xEB, 0x0A, 0x7D, 0x3E, 0x16, 0xB1, 0x87, 0xC2, 0x4B, 0xAB, 0x75, 0x13, 0x63, 0xBD, 0xD2, 0xD0, 0xD3, 0x70, 0x15, 0xBC, 0x86, 0xAB, 0x28, 0xDF, 0x06, 0x81, 0xDB, 0xB4, 0x21, 0x13, 0xED, 0x66, 0xD5, 0xFE, 0x93, 0x59, 0xD6, 0xB4, 0x5A, 0x91, 0x9B, 0x86, 0x75, 0x8F, 0x51, 0x80, 0xC7, 0x05, 0x40, 0x83, 0xB8, 0xC5, 0xDD, 0x68, 0x12, 0x46, 0x75, 0xB8, 0x78, 0x1F, 0x25, 0x03, 0x67, 0x67, 0x80, 0x4D, 0x8E, 0x7C, 0x3B, 0xAC, 0x18, 0x93, 0xB9, 0x9A, 0xC1, 0x95, 0xB8, 0x73, 0x2E, 0xEE, 0x9F, 0xAF, 0x82, 0x7D, 0x9B, 0x60, 0x9A, 0xB0, 0x75, 0xB8, 0x5F, 0xFB, 0x7E, 0x86, 0x29, 0xED, 0xF8, 0x2F, 0xAC, 0x18, 0xD5, 0xA4, 0x7D, 0xA0, 0xA6, 0x1A, 0xBE, 0x69, 0xC2, 0x4B, 0x34, 0x19, 0x84, 0x04, 0x0F, 0xB3, 0xC4, 0xBB, 0x2E, 0xE8, 0x27, 0x9F, 0x61, 0x83, 0x37, 0x45, 0x56, 0x52, 0xA8, 0x09, 0x28, 0x65, 0x30, 0x99, 0xB4, 0xB6, 0x63, 0x9A, 0xF7, 0xA1, 0x2A, 0xA0, 0xC8, 0x76, 0xB4, 0x54, 0xA5, 0x26, 0x7C, 0x90, 0xDE, 0x95, 0x3D, 0x5F, 0x13, 0xFB, 0x52, 0x27, 0x3D, 0x90, 0x42, 0xFE, 0xBC, 0x90, 0xEA, 0xE3 };
  byte result[256];

  long startTime = millis();
  chip.modularExponentiation(cypher, sizeof(cypher), exponent, sizeof(exponent), modulus, sizeof(modulus), result, sizeof(result));
  long endTime = millis();
  Serial.print("Result is: ");
  printHex(result, sizeof(result));
  Serial.print("It took: ");
  Serial.println(endTime-startTime);

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