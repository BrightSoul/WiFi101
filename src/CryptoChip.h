/*
  CryptoChip.h
*/

#ifndef CRYPTOCHIP_H
#define CRYPTOCHIP_H

class CryptoChip {

public:
	CryptoChip();
	void modularExponentiation(uint8_t *cypher, uint16_t cypherSize, uint8_t *exponent, uint16_t exponentSize, uint8_t *modulus, uint16_t modulusSize, uint8_t *result, uint16_t resultSize);
};

#endif /*CRYPTOCHIP_H */
