/* oneTimePad.c - Hernan Le */

#include "oneTimePad.h"
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <time.h>

/* need to set up the "seed" for pseudo random generation */
typedef enum {FALSE = 0, TRUE = 1} boolean;
static boolean systemReady = FALSE;

void OTP_setup(){
    srand(time(NULL));
    systemReady = TRUE;
}

ByteArray OTP_generateKey(size_t keyLength){
    size_t index;
    ByteArray key;

    assert(systemReady);

    key = ByteArray_new(keyLength);
    if(key == NULL) 
        return NULL;

    for(index = 0; index < keyLength; index++){
        ByteArray_setByte(key, index, rand()%128 );
    }
    return key;
}

ByteArray OTP_stringToByteArray(const char *str, size_t length){
    size_t index;
    ByteArray byteArr;

    assert(str != NULL);

    byteArr = ByteArray_new(length);
    if (byteArr == NULL)
        return NULL;

    for(index = 0; index < length; index++){
        ByteArray_setByte(byteArr, index, str[index]);
    }

    return byteArr;
}

ByteArray OTP_applyKey(ByteArray msg, ByteArray key){
    size_t index;
    size_t msgLength;
    size_t keyLength;

    ByteArray result;

    assert(msg != NULL); assert(key != NULL);
    msgLength = ByteArray_len(msg);
    keyLength = ByteArray_len(key);

    result = ByteArray_new(msgLength);
    if(result == NULL)
        return NULL;

    for(index = 0; index < msgLength; index++){
        if(index < keyLength)
            ByteArray_setByte(result, index, 
            ByteArray_getByte(msg, index) ^ ByteArray_getByte(key, index));
        else
            ByteArray_setByte(result, index, ByteArray_getByte(msg, index));
    }

    return result;
}

void OTP_print(FILE *outputStream, ByteArray byteArr){
    size_t index;
    size_t length;

    assert(byteArr!=NULL);

    length = ByteArray_len(byteArr);

    for(index = 0; index < length; index++){
        fprintf(outputStream, "%c", ByteArray_getByte(byteArr, index));
    }

}