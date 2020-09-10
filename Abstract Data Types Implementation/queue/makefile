queuerunner.out: driver.c push.o pop.o create_queue.o pop_front.o push_back.o
	gcc -o queuerunner.out driver.c push.o pop.o create_queue.o pop_front.o push_back.o

pop.o: pop.c queue.h ../doubly_linked_list/list.h
	gcc -c ../doubly_linked_list/pop_front.c
	gcc -c pop.c

push.o: push.c queue.h ../doubly_linked_list/list.h
	gcc -c ../doubly_linked_list/push_back.c
	gcc -c push.c

create_queue.o: create_queue.c queue.h
	gcc -c create_queue.c

clean:
	rm -f *.o *.out

