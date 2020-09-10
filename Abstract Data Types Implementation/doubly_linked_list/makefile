llrunner.out: driver.c push_back.o pop_back.o push_front.o pop_front.o print_list.o
	gcc -o llrunner.out driver.c push_back.o pop_back.o push_front.o pop_front.o print_list.o

pop_back.o: pop_back.c list.h
	gcc -c pop_back.c

pop_front.o: pop_front.c list.h
	gcc -c pop_front.c

push_back.o: push_back.c list.h
	gcc -c push_back.c

push_front.o: push_front.c list.h
	gcc -c push_front.c

print_list.o: print_list.c list.h
	gcc -c print_list.c

clean:
	rm -f *.o *.out

