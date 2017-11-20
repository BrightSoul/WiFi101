/*
  CryptoChip.cpp
*/
#include <Arduino.h>
#include "CryptoChip.h"
extern "C" {
	#include "driver/include/m2m_crypto.h"
}

CryptoChip::CryptoChip()
{
}

void CryptoChip::modularExponentiation(uint8_t *cypher, uint16_t cypherSize, uint8_t *exponent, uint16_t exponentSize, uint8_t *modulus, uint16_t modulusSize, uint8_t *result, uint16_t resultSize)
{
	BigInt_ModExp(cypher, cypherSize, exponent, exponentSize, modulus, modulusSize, result, resultSize);
}
