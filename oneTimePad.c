/* oneTimePad.c - Hernan Le */

#include "oneTimePad.h"
#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

/* need to set up the "seed" for pseudo random generation */
typedef enum {FALSE = 0, TRUE = 1} boolean;
static boolean systemReady = FALSE;

void OTP_setup(){
    srand(time(NULL));
    systemReady = TRUE;
}

ByteArray OTP_generateKey(size_t keyLen){
    size_t index;
    ByteArray key;

    assert(systemReady);

    key = ByteArray_new(keyLen);
    if(key == NULL) 
        return NULL;

    for(index = 0; index < keyLen; index++){
        ByteArray_setByte(key, index, rand()%128 );
    }
    return key;
}

ByteArray OTP_stringToByteArray(const char *str){
    size_t index;
    size_t strLength; 
    ByteArray byteArr;

    assert(str != NULL);

    strLength = strlen(str);

    byteArr = ByteArray_new(strLength);
    if (byteArr == NULL)
        return NULL;

    for(index = 0; index < strLength; index++){
        ByteArray_setByte(byteArr, index, str[index]);
    }

    return byteArr;
}

ByteArray OTP_applyKey(ByteArray msg, ByteArray key){
    return NULL;
}

void OTP_print(ByteArray byteArr){
    size_t index;
    size_t length;

    assert(byteArr!=NULL);

    length = ByteArray_len(byteArr);

    for(index = 0; index < length; index++){
        printf("%c", ByteArray_getByte(byteArr, index));
    }

}