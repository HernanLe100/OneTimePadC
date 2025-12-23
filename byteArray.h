/* byteArray.h - Hernan Le */

#ifndef BYTE_ARRAY
#define BYTE_ARRAY

#include <stddef.h>

/* */
typedef struct ByteArrayStruct * ByteArray;

/* Allocate memory for an empty ByteArray of size len and return the 
ByteArray. Returns NULL if insufficient memory. */
ByteArray ByteArray_new(size_t len);

/* Frees memory allocated to byteArr */
void ByteArray_free(ByteArray byteArr);

/* Sets index-th byte of byteArr to value */
void ByteArray_setByte(ByteArray byteArr, size_t index, char value);

#endif
