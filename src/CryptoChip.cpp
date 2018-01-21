/*
  CryptoChip.cpp
*/
#include <Arduino.h>
#include "CryptoChip.h"
extern "C" {
	#include "driver/include/m2m_crypto.h"
}

tstrM2mSha256Ctxt	strSha256;
CryptoChip::CryptoChip()
{
	nm_bsp_init();
}

void CryptoChip::modularExponentiation(uint8_t *cypher, uint16_t cypherSize, uint8_t *exponent, uint16_t exponentSize, uint8_t *modulus, uint16_t modulusSize, uint8_t *result, uint16_t resultSize)
{
	BigInt_ModExp(cypher, cypherSize, exponent, exponentSize, modulus, modulusSize, result, resultSize);
}


int8_t CryptoChip::sha256HashInit()
{
	return m2m_crypto_sha256_hash_init(&strSha256);
}
int8_t CryptoChip::sha256HashUpdate(byte *pu8Data, word u16DataLength)
{
	return m2m_crypto_sha256_hash_update(&strSha256, pu8Data, u16DataLength);
}
int8_t CryptoChip::sha256HashFinish(byte *pu8Sha256Digest)
{
	return m2m_crypto_sha256_hash_finish(&strSha256, pu8Sha256Digest);
}

bool CryptoChip::rsaVerifySignature(byte *pu8N, word u16NSize, byte *pu8E, word u16ESize, byte *pu8SignedMsgHash,word u16HashLength, byte *pu8RsaSignature)
{
	bool success;
	if (m2m_crypto_rsa_sign_verify(pu8N, u16NSize, pu8E, u16ESize, pu8SignedMsgHash,u16HashLength, pu8RsaSignature) == M2M_RSA_SIGN_OK) {
		success = true;
	} else {
		success = false;
	}
	return success;
}
int8_t CryptoChip::rsaSign(byte *pu8N, word u16NSize, byte *pu8d, word u16dSize, byte *pu8SignedMsgHash,word u16HashLength, byte *pu8RsaSignature)
{
	return m2m_crypto_rsa_sign_gen(pu8N, u16NSize, pu8d, u16dSize, pu8SignedMsgHash,u16HashLength, pu8RsaSignature);
}