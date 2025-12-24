/* oneTimePad.h - Hernan Le */

#ifndef ONE_TIME_PAD
#define ONE_TIME_PAD

#include "byteArray.h"
#include <stddef.h> 

/* Sets up the  */
void OTP_setup();

/* Generates a random key of keyLen bytes and return as a ByteArray.
Return NULL if memory allocation failed. */
ByteArray OTP_generateKey(size_t keyLen);

/* Returns a ByteArray representation of str. 
Return NULL if memory allocation failed.*/
ByteArray OTP_stringToByteArray(const char *str);

/* XOR msg and key and returns result as ByteArray. 
Return NULL if memory allocation failed. 
- Ideally, key and msg are the same length, 
but if key < msg, the first |key| bytes of msg are encrypted. */
ByteArray OTP_applyKey(ByteArray msg, ByteArray key);

/* prints the contents of byteArr to standard output. */
void OTP_print(ByteArray byteArr); 


#endif