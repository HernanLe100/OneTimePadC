all: test encrypt decrypt

byteArray.o: byteArray.c byteArray.h
	gcc -c byteArray.c

oneTimePad.o: oneTimePad.c oneTimePad.h byteArray.h
	gcc -c oneTimePad.c

encrypt.o: encrypt.c oneTimePad.h byteArray.h
	gcc -c encrypt.c
encrypt: encrypt.o oneTimePad.o byteArray.o
	gcc encrypt.o oneTimePad.o byteArray.o -o encrypt

decrypt.o: decrypt.c oneTimePad.h byteArray.h
	gcc -c decrypt.c
decrypt: decrypt.o oneTimePad.o byteArray.o
	gcc decrypt.o oneTimePad.o byteArray.o -o decrypt


test.o: test.c oneTimePad.h
	gcc -c test.c
test: test.o oneTimePad.o byteArray.o
	gcc test.o oneTimePad.o byteArray.o -o test