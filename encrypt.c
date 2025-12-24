/* encrypt.c - Hernan Le */

#include "byteArray.h"
#include "oneTimePad.h"
#include <stdio.h>

/* If input is larger, input will be processed in chunks of 65536 */
enum{BUFFER_SIZE = 65536}; 

/* Takes in name of input file from command line or standard input at 
runtime and generates a one-time pass key to encrypt the input. */
int main(int argc, char *argv[]){
    ByteArray msg; 
    ByteArray key; 
    ByteArray cipher; 

    FILE * inputStream; /* read msg from stdin or a file */
    FILE * keyFile = fopen("key", "w"); /* store the key */
    FILE * cipherFile = fopen("cipher", "w"); /* store result */

    char msgStr[BUFFER_SIZE]; 
    size_t index = 0;
    int c = 0;

    if(argc == 1){
        /* No command line args. 
        User types in input or redirect from file */
        inputStream = stdin;
        printf("Press Ctrl + D on a new line (Unix) ");
        printf("or Ctrl + Z and Enter (Windows) to end input.\n\n");
    }
    else if (argc == 2)
    {
        /* Command line arg is name of input file */
        inputStream = fopen(argv[1], "r");
    }

    OTP_setup();
    
    /* continue until reach end of input */
    while(c != EOF){
        index = 0;
        /* fit within array bounds */
        while(index < BUFFER_SIZE - 1){
            c = fgetc(inputStream);
            if(c == EOF)
                break;

            msgStr[index] = c;
            index ++;
        }
        msgStr[index] = '\0';


        msg = OTP_stringToByteArray(msgStr);
        key = OTP_generateKey( ByteArray_len(msg) );
        OTP_print(keyFile, key);
        cipher = OTP_applyKey(msg, key);
        OTP_print(cipherFile, cipher);

        ByteArray_free(msg);
        ByteArray_free(key);
        ByteArray_free(cipher);
    }

    if(inputStream == stdin)
        printf("\n\n Encryption complete.\n");

    fclose(cipherFile);
    fclose(keyFile);
    fclose(inputStream);

    return 0;
}