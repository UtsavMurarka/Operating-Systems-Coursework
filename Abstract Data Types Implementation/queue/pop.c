#include <stdio.h>
#include <stdlib.h>
#include "../doubly_linked_list/list.h"
#include "queue.h"

struct queue* pop(struct queue* q){
	
	if(q->size == 0){
		printf("Queue is empty\n");
		return q;
	}
	q->head_tail = pop_front(q->head_tail);
	q->size = q->size - 1;
	if(q->head_tail.head != NULL){
		q->front = q->head_tail.head->data;
	}
	return q;
}