/* encrypt.c - Hernan Le */

/* ./encrypt [msgFile] keyFile cipherFile */

#include "byteArray.h"
#include "oneTimePad.h"
#include <stdio.h>

/* If input is larger, input will be processed in chunks of 65536 */
enum{BUFFER_SIZE = 65536}; 

/* Takes in name of input file from command-line or standard input at 
runtime and generates a one-time pass key to encrypt the input. 
Creates/writes to key and cipher files specified by command-line args. */
int main(int argc, char *argv[]){
    ByteArray msg; 
    ByteArray key; 
    ByteArray cipher; 

    FILE * inputStream; /* read msg from stdin or a file */
    FILE * keyFile; /* store the key */
    FILE * cipherFile; /* store result */

    char msgStr[BUFFER_SIZE]; 
    size_t index;
    int c = 0;

    if(argc == 3){
        /* User types in input or redirect from file */
        inputStream = stdin;
        keyFile = fopen(argv[1], "w");
        cipherFile = fopen(argv[2], "w");
        printf("Press Ctrl + D on a new line (Unix) ");
        printf("or Ctrl + Z and Enter (Windows) to end input.\n\n");
    }
    else if (argc == 4)
    {
        /* Command line arg specifies name of input file */
        inputStream = fopen(argv[1], "r");
        keyFile = fopen(argv[2], "w");
        cipherFile = fopen(argv[3], "w");
    }
    else{
        fprintf(stderr, "Invalid number of command-line arguments.");
        fprintf(stderr, "\n");
        
        fprintf(stderr, "Run with: ./encrypt [msgFile] keyFile cipherFile\n");
        return 1;
    }

    OTP_setup();
    
    /* continue until reach end of input */
    while(c != EOF){
        index = 0;
        /* fit within array bounds */
        while(index < BUFFER_SIZE){
            c = fgetc(inputStream);
            if(c == EOF)
                break;

            msgStr[index] = c;
            index ++;
        }
        /* need to go by char to be able to handle null byte */

        msg = OTP_stringToByteArray(msgStr, index);
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