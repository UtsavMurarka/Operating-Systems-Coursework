runner.out: driver.c stringToFloat.o
	gcc -o runner.out driver.c stringToFloat.o

stringToFloat.o: stringToFloat.c stringToFloat.h
	gcc -c stringToFloat.c
clean:
	rm -f *.o *.out