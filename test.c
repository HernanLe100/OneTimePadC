/* */

#include "oneTimePad.h"
#include <stdio.h>

int main(void){

    ByteArray key;
    OTP_setup();

    key = OTP_generateKey(100);
    OTP_print(key);
    printf("\n");
    ByteArray_free(key);

    key = OTP_stringToByteArray("Hello World");
    OTP_print(key);
    ByteArray_free(key);
    printf("\n");

    return 0;
}
