all: test 

byteArray.o: byteArray.c byteArray.h
	gcc -c byteArray.c

oneTimePad.o: oneTimePad.c oneTimePad.h byteArray.h
	gcc -c oneTimePad.c

test.o: test.c oneTimePad.h
	gcc -c test.c

test: test.o oneTimePad.o byteArray.o
	gcc test.o oneTimePad.o byteArray.o -o test