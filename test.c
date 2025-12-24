/* */

#include "oneTimePad.h"
#include <stdio.h>

int main(void){

    ByteArray key;
    ByteArray msg;
    ByteArray result;
    OTP_setup();

    key = OTP_generateKey(100);
    OTP_print(stdout, key);
    printf("\n\n");
    ByteArray_free(key);

    msg = OTP_stringToByteArray("Hello World");
    OTP_print(stdout, msg);
    ByteArray_free(msg);
    printf("\n\n");

    key = OTP_generateKey(5);
    msg = OTP_stringToByteArray("Hello World");
    result = OTP_applyKey(msg, key);
    OTP_print(stdout, result);
    printf("\n\n");
    ByteArray_free(key);
    ByteArray_free(msg);
    ByteArray_free(result);

    return 0;
}
