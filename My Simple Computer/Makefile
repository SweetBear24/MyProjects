all: libmySP.a

mySimpleComputer.o: mySimpleComputer.c mySimpleComputer.h
	gcc -c mySimpleComputer.c -o mySimpleComputer.o

libmySP.a: mySimpleComputer.o
	ar cr libmySP.a mySimpleComputer.o

all: myTern.a

LB2.o: LB2.c LB2.h
	gcc -c LB2.c -o LB2.o

myTern.a: LB2.o
	ar cr myTern.a LB2.o

all: myBigChar.a

myBigChar.o: myBigChar.c myBigChar.h
	gcc -c myBigChar.c -o myBigChar.o

myBigChar.a: myBigChar.o
	ar cr myBigChar.a myBigChar.o

all: myReadkeys.a

myReadkey.o: myReadkey.c keys.h
	gcc -c myReadkey.c -I . -o myReadkey.o

myReadkeys.a: myReadkey.o
	ar cr myReadkeys.a myReadkey.o

all: myCU.a

myCu.o: myCU.c myCU.h
	gcc -c myCU.c -I . -o myCU.o

myCU.a: myCu.o
	ar cr myCU.a myCU.o

all: myALU.a

myALU.o: myALU.c myALU.h
	gcc -c myALU.c -I . -o myALU.o

myALU.a: myALU.o
	ar cr myALU.a myALU.o

all: mySignal.a

mySignal.o: mySignal.c mySignal.h
	gcc -c mySignal.c -I . -o mySignal.o

mySignal.a: mySignal.o
	ar cr mySignal.a mySignal.o

all: myInterface.a

myInterface.o: myInterface.c myInterface.h
	gcc -c myInterface.c -I . -o myInterface.o
 
myInterface.a: myInterface.o
	ar cr myInterface.a myInterface.o

clean: 
	rm -rf *.o
