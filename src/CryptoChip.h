/*
  CryptoChip.h
*/

#ifndef CRYPTOCHIP_H
#define CRYPTOCHIP_H

class CryptoChip {

public:
	CryptoChip();
	void modularExponentiation(uint8_t *cypher, uint16_t cypherSize, uint8_t *exponent, uint16_t exponentSize, uint8_t *modulus, uint16_t modulusSize, uint8_t *result, uint16_t resultSize);
	int8_t sha256HashInit();
  int8_t sha256HashUpdate(byte *pu8Data, word u16DataLength);
  int8_t sha256HashFinish(byte *pu8Sha256Digest);
  int8_t rsaSign(byte *pu8N, word u16NSize, byte *pu8d, word u16dSize, byte *pu8SignedMsgHash,word u16HashLength, byte *pu8RsaSignature);
	bool rsaVerifySignature(byte *pu8N, word u16NSize, byte *pu8E, word u16ESize, byte *pu8SignedMsgHash,word u16HashLength, byte *pu8RsaSignature);
};

#endif /*CRYPTOCHIP_H */
