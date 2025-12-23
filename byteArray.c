/* byteArray.c - Hernan Le */

#include "byteArray.h"
#include <stdlib.h>
#include <assert.h>

/* Underlying struct for the ByteArray*/
struct ByteArrayStruct{
    size_t arrLen; /* track the length of the array */
    char *charArr; /* array of bytes */
};

ByteArray ByteArray_new(size_t len){

    ByteArray newByteArr; 
    newByteArr = (ByteArray) malloc(sizeof(struct ByteArrayStruct));
    if(newByteArr == NULL)
        return NULL; 
    
    newByteArr->charArr = (char *)calloc(len, sizeof(char));
    if(newByteArr->charArr == NULL){
        free(newByteArr);
        return NULL;
    }

    newByteArr->arrLen = len;
    return newByteArr;
}

void ByteArray_free(ByteArray byteArr){
    assert(byteArr!=NULL);
    free(byteArr->charArr);
    free(byteArr);
}

void ByteArray_setByte(ByteArray byteArr, size_t index, char value){
    assert(byteArr!=NULL);
    assert(index < byteArr->arrLen);

    byteArr->charArr[index] = value;
}
