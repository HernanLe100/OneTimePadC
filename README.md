# OneTimePadC

by Hernan Le



## encrypt
./encrypt [msgFile] keyFile cipherFile

- msgFile - optional, contains input to be encrypted
- generates a (pseudo) random key and writes to keyFile
- resulting cipher written to cipherFile

## decrypt
./decrypt cipherFile keyFile [msgFile]

- cipherFile contains the cipher to be decrypted
- key from keyFile is applied to the cipher to decrypt
- optional: decrypted message is written to msgFile

## ByteArray
Represents an array of set bytes

## oneTimePad
Interface uses ByteArrays and applies XOR operations to the bits to encrypt/decrypt using one-time padding
