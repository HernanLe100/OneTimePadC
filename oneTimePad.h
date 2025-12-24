/* oneTimePad.h - Hernan Le */

#ifndef ONE_TIME_PAD
#define ONE_TIME_PAD

#include "byteArray.h"
#include <stddef.h> 
#include <stdio.h>

/* Sets up the system to generate (pseudo) random numbers. 
- This function MUST be called BEFORE calling OTP_generateKey(). */
void OTP_setup();

/* Generates a random key of keyLength bytes and return as a ByteArray.
Return NULL if memory allocation failed. */
ByteArray OTP_generateKey(size_t keyLength);

/* Returns a ByteArray representation of first length bytes of str. 
Return NULL if memory allocation failed.*/
ByteArray OTP_stringToByteArray(const char *str, size_t length);

/* XOR msg and key and returns result as ByteArray. 
Return NULL if memory allocation failed. 
- Ideally, key and msg are the same length, 
but if |key| < |msg|, the first |key| bytes of msg are encrypted. */
ByteArray OTP_applyKey(ByteArray msg, ByteArray key);

/* Prints the contents of byteArr to outputStream. */
void OTP_print(FILE * outputStream, ByteArray byteArr); 


#endif