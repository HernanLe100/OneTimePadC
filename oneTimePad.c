/* oneTimePad.c - Hernan Le */

#include "oneTimePad.h"
#include <stdlib.h>

ByteArray OTP_generateKey(size_t keyLen){
    size_t index;
    ByteArray key;

    key = ByteArray_new(keyLen);
    if(key != NULL) 
        return NULL;

    for(index = 0; index < keyLen; index++){
        ByteArray_setByte(key, index, rand()%128 );
    }
    return key;
}
