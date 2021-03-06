/*

 This example makes an attempt at using the CryptoChip directly

 */
#include <SPI.h>
#include <CryptoChip.h>
#define M2M_SHA256_DIGEST_LEN			32

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
CryptoChip chip;
/*char	gacRsaSignedMessage[] = 
	"THIS SOFTWARE IS PROVIDED BY ATMEL \"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,"\
	" THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT ARE EXPRESSLY AND"\
	" SPECIFICALLY DISCLAIMED. IN NO EVENT SHALL ATMEL BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY"\
	", OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, "\
	"DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT"\
	"LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF "\
	"ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."\
	"Implements the MLME_SCAN primitives."\
	"This file implements functions to handle all MLME-SCAN primitives and the corresponding scan algorithm. This includes ED"\
	", Active, Passive and Orphan scan. All required timers and frames (beacon request and orphan notification frames) are "\
	"assembled and their transmission is initiated."\
	"Copyright (c) 2013-2015 Atmel Corporation. All rights reserved."\
	"Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following"\
	" conditions are met:"\
	"Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer."\
	"Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following "\
	"disclaimer in the documentation and/or other materials provided with the distribution."\
	"The name of Atmel may not be used to endorse or promote products derived from this software without specific prior "\
	"written permission."\
	"This software may only be redistributed and used in connection with an Atmel microcontroller product.";*/
  char gacRsaSignedMessage[] = "She Sells Seashells by the Seashore";


  byte	d[256] = {
	0x1d, 0xde, 0x65, 0x03, 0x7d, 0x47, 0x94, 0x58, 0xad, 0x91, 0x58, 0x05, 0x7b, 0xce, 0x1d, 0x69,
	0x16, 0x94, 0xd6, 0x05, 0xf9, 0xdb, 0xb7, 0x82, 0x14, 0x3e, 0x73, 0x4f, 0x16, 0x00, 0x54, 0xd6,
	0x34, 0xda, 0xf8, 0x68, 0xdc, 0x83, 0x98, 0x56, 0x3c, 0x8d, 0x60, 0xd9, 0xe4, 0x96, 0x73, 0x8e,
	0x07, 0xa3, 0x56, 0x47, 0x31, 0x99, 0x57, 0xdd, 0xd8, 0x99, 0x7f, 0x2b, 0xfb, 0xc1, 0x1b, 0x69,
	0x3c, 0x18, 0xb0, 0x99, 0xa3, 0x2f, 0x88, 0x74, 0xcb, 0xc1, 0x95, 0x65, 0xcb, 0x4f, 0x26, 0x52,
	0xec, 0x1d, 0x20, 0x29, 0xfc, 0x1f, 0x10, 0x89, 0x4f, 0x7f, 0xbf, 0x68, 0x4c, 0x4a, 0x7c, 0x0a,
	0xb2, 0x0f, 0x70, 0x55, 0x24, 0x56, 0x3b, 0x61, 0x53, 0xd8, 0xc8, 0xdc, 0x89, 0xd8, 0x1a, 0xcc,
	0xb2, 0x8f, 0x5d, 0x87, 0x3b, 0xf0, 0x2a, 0x37, 0x1f, 0x84, 0xe7, 0x65, 0x4f, 0xeb, 0xf2, 0x74,
	0x27, 0x2b, 0x58, 0x2f, 0x75, 0x18, 0xb6, 0xf8, 0x45, 0x6b, 0xc5, 0x82, 0x31, 0x5a, 0x44, 0xd3,
	0x09, 0x13, 0xf9, 0x5b, 0xd7, 0x41, 0x7f, 0x20, 0x88, 0x96, 0xc6, 0x14, 0x72, 0x81, 0x83, 0x70,
	0x42, 0xd1, 0xb4, 0x2c, 0x47, 0xd2, 0x4e, 0xbf, 0x31, 0xac, 0x98, 0x2b, 0xe2, 0xcc, 0x8d, 0x1f,
	0x54, 0xfe, 0x2d, 0x8e, 0x31, 0xbb, 0x5a, 0x0c, 0x6f, 0x6f, 0x94, 0x8c, 0x8d, 0x36, 0x7e, 0x85,
	0xf3, 0x16, 0xf0, 0x87, 0x69, 0x4e, 0x66, 0x19, 0x8b, 0xcf, 0x60, 0x5d, 0x5d, 0xa9, 0x33, 0xb6,
	0x52, 0x89, 0xdf, 0x54, 0xf6, 0x23, 0x93, 0x0f, 0x9d, 0x12, 0x51, 0x79, 0x78, 0x72, 0x5f, 0xe8,
	0x25, 0x8e, 0xae, 0xa2, 0x1e, 0x7e, 0xd4, 0x67, 0xcf, 0xe6, 0x10, 0x74, 0xa3, 0x05, 0x31, 0x7e,
	0xb5, 0xa8, 0x9d, 0xbf, 0xab, 0x6d, 0xe6, 0x76, 0x2e, 0xce, 0xcf, 0x3a, 0xe8, 0xc7, 0xbd, 0x21
  };

  byte	N[256] = {
	0xad ,0x6a ,0x33 ,0xee ,0xa2 ,0x73 ,0x6d ,0x68 ,0xba ,0xbd ,0x2d ,0xb1 ,0xb5 ,0x54 ,0xf0 ,0x04,
	0x14 ,0xff ,0xbd ,0xd7 ,0x5b ,0x4c ,0x69 ,0xe7 ,0xf4 ,0x66 ,0x7f ,0xac ,0x06 ,0xe1 ,0x95 ,0x77,
	0x6b ,0x9d ,0x9a ,0x1f ,0x51 ,0x61 ,0xe6 ,0xd2 ,0x92 ,0x50 ,0xdc ,0x0f ,0x5d ,0x15 ,0x0c ,0x9e,
	0xd3 ,0x37 ,0xa6 ,0xf9 ,0x77 ,0x36 ,0x76 ,0x74 ,0xda ,0x3f ,0x50 ,0x7f ,0x9c ,0xdf ,0x52 ,0xc9,
	0x32 ,0x4c ,0xda ,0x22 ,0x31 ,0xeb ,0x94 ,0xb0 ,0xcf ,0x56 ,0xee ,0x91 ,0x86 ,0x30 ,0xa9 ,0x24,
	0x29 ,0x01 ,0x2f ,0x83 ,0xd1 ,0x08 ,0x73 ,0x94 ,0x97 ,0xe1 ,0xdb ,0x88 ,0x85 ,0x3b ,0xe1 ,0x46,
	0x2b ,0xc5 ,0xff ,0x03 ,0xea ,0x7c ,0x74 ,0xa6 ,0x89 ,0x64 ,0x41 ,0xcc ,0x88 ,0xe7 ,0x9c ,0xaf,
	0x33 ,0xfb ,0x48 ,0xe7 ,0x5b ,0xca ,0x6f ,0x90 ,0x75 ,0x7a ,0x42 ,0xa2 ,0xba ,0x8a ,0x4e ,0x06,
	0x38 ,0x87 ,0x51 ,0x66 ,0x96 ,0xc1 ,0xef ,0x8a ,0xe2 ,0xb2 ,0xe7 ,0x63 ,0x57 ,0xf4 ,0xfa ,0xf8,
	0xa6 ,0x4d ,0x4d ,0x43 ,0x28 ,0xac ,0x3a ,0x4c ,0xee ,0x33 ,0x5d ,0xf1 ,0x21 ,0x0d ,0xd4 ,0xfc,
	0x9e ,0x23 ,0xf0 ,0x29 ,0xd8 ,0xf6 ,0x55 ,0x66 ,0x36 ,0x1a ,0x29 ,0x7a ,0x6d ,0x33 ,0x2f ,0x0d,
	0x30 ,0x72 ,0xf8 ,0xb4 ,0x2b ,0x7f ,0xe9 ,0x61 ,0x75 ,0x49 ,0xdd ,0xfd ,0x3b ,0x2c ,0x29 ,0xdf,
	0x7b ,0xb1 ,0x96 ,0x32 ,0x0c ,0x98 ,0xc4 ,0x36 ,0x3c ,0xd8 ,0x0c ,0x82 ,0xd3 ,0xc7 ,0xf4 ,0xf0,
	0xf4 ,0xc4 ,0xe2 ,0x7c ,0xd4 ,0x56 ,0xae ,0x74 ,0x60 ,0xfc ,0xc2 ,0xe9 ,0x44 ,0xda ,0xf4 ,0x74,
	0x12 ,0x05 ,0x6a ,0x4f ,0xbc ,0xba ,0xbb ,0x4c ,0x04 ,0xaa ,0x43 ,0x9d ,0x50 ,0x88 ,0xa7 ,0xa2,
	0x38 ,0x73 ,0x5a ,0x01 ,0x01 ,0x40 ,0xcd ,0xd2 ,0x7c ,0x79 ,0xc8 ,0x78 ,0xdc ,0x26 ,0x44 ,0xe5
  };

  byte	e[3] = {1, 0, 1};
  
	word u16SignedMsgLen = strlen(gacRsaSignedMessage);
	byte au8SHA256Digest[M2M_SHA256_DIGEST_LEN];
	byte au8RSASignature[256];
	
  chip.sha256HashInit();
  chip.sha256HashUpdate((byte*)gacRsaSignedMessage, u16SignedMsgLen);
  chip.sha256HashFinish(au8SHA256Digest);
  Serial.println("The hash of the message is");
  printHex(au8SHA256Digest, M2M_SHA256_DIGEST_LEN);

  //Generate the signature
  chip.rsaSign(N, 256, d, 256, au8SHA256Digest, M2M_SHA256_DIGEST_LEN, au8RSASignature);
  Serial.println("The generated signature was:");
  printHex(au8RSASignature, 256);

  //Verify the signature
  bool result = chip.rsaVerifySignature(N, 256, e, 3, au8SHA256Digest, M2M_SHA256_DIGEST_LEN, au8RSASignature);
  Serial.print("Signature verified: ");
  Serial.println(result); //always prints 0 (false)
  Serial.println("");
  Serial.println("Performing verification again in 10 seconds...");
  delay(10000);
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