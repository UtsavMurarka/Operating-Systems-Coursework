#include <stdio.h>
#include <stdlib.h>
#include "../doubly_linked_list/list.h"
#include "queue.h"

struct queue* create_queue(){

	struct queue *q = (struct queue*)malloc(sizeof(struct queue));
	q->head_tail.head = NULL;
	q->size = 0;
	q->front = NULL;

	return q;
}