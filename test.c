/* */

#include "oneTimePad.h"
#include <stdio.h>

int main(void){

    ByteArray key;
    ByteArray msg;
    OTP_setup();

    key = OTP_generateKey(100);
    OTP_print(key);
    printf("\n\n");
    ByteArray_free(key);

    msg = OTP_stringToByteArray("Hello World");
    OTP_print(msg);
    ByteArray_free(msg);
    printf("\n\n");

    return 0;
}
