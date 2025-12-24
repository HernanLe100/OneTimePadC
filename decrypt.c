/* decrypt.c - Hernan Le */

#include "byteArray.h"
#include "oneTimePad.h"
#include <stdio.h>

/* If input is larger, input will be processed in chunks of 65536 */
enum{BUFFER_SIZE = 65536}; 

/* Takes in cipher and key file names as command line args and prints 
decrypted message to standard output */
int main(int argc, char *argv[]){
    ByteArray cipher; 
    ByteArray key; 
    ByteArray msg; 

    FILE * cipherFile; 
    FILE * keyFile; 

    char cipherStr[BUFFER_SIZE];
    char keyStr[BUFFER_SIZE];

    size_t index;
    int c = 0;

    if (argc != 3){
        fprintf(stderr, "Incorrect number of command-line arguments.");
        fprintf(stderr, "\n");
        return 1;
    }

    cipherFile = fopen(argv[1], "r");
    keyFile = fopen(argv[2], "r");

    /* continue until reach end of cipher */
    while(c != EOF){
        index = 0;
        /* fit within array bounds */
        while(index < BUFFER_SIZE){

            /* key bytes */
            c = fgetc(keyFile);
            if(c!=EOF)
                keyStr[index] = c;
            else
                keyStr[index] = 0;

            /* cipher bytes */
            c = fgetc(cipherFile);
            if(c == EOF)
                break;

            cipherStr[index] = c;
            index++;
        }

        cipher = OTP_stringToByteArray(cipherStr, index);
        key = OTP_stringToByteArray(keyStr, index);
        msg = OTP_applyKey(cipher, key);
        OTP_print(stdout, msg);

        ByteArray_free(msg);
        ByteArray_free(key);
        ByteArray_free(cipher);
    }

    fclose(cipherFile);
    fclose(keyFile);
    
    printf("\n");

    return 0;
}