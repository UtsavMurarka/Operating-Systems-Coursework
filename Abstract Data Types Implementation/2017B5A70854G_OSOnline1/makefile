runner.out: driver.c addToMemory.o initializeMemory.o memTest.o printMemoryState.o
	gcc -o runner.out driver.c addToMemory.o initializeMemory.o memTest.o printMemoryState.o

addToMemory.o: addToMemory.c memInterface.h
	gcc -c addToMemory.c

initializeMemory.o: initializeMemory.c memInterface.h
	gcc -c initializeMemory.c

memTest.o: memTest.c memInterface.h
	gcc -c memTest.c

printMemoryState.o: printMemoryState.c memInterface.h
	gcc -c printMemoryState.c

clean:
	rm -f *.o *.out

