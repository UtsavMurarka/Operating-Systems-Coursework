stackrunner.out: driver.c push.o pop.o create_stack.o pop_front.o push_front.o
	gcc -o stackrunner.out driver.c push.o pop.o create_stack.o pop_front.o push_front.o

pop.o: pop.c stack.h ../linked_list/list.h
	gcc -c ../linked_list/pop_front.c
	gcc -c pop.c

push.o: push.c stack.h ../linked_list/list.h
	gcc -c ../linked_list/push_front.c
	gcc -c push.c

create_stack.o: create_stack.c stack.h
	gcc -c create_stack.c

clean:
	rm -f *.o *.out

