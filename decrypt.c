/* decrypt.c - Hernan Le */

#include "byteArray.h"
#include "oneTimePad.h"
#include <stdio.h>

/* If input is larger, input will be processed in chunks of 65536 */
enum{BUFFER_SIZE = 65536}; 

/* Takes in cipher and key file names as command line args and prints 
decrypted message to standard output */
int main(int argc, char *argv[]){

    char cipherStr[BUFFER_SIZE];
    char keyStr[BUFFER_SIZE];


    if (argc != 3){
        fprintf(stderr, "Incorrect number of command-line arguments.");
        fprintf(stderr, "\n");
        return 1;
    }




    return 0;
}