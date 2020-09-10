#include <stdio.h>
#include <stdlib.h>
#include "../doubly_linked_list/list.h"
#include "queue.h"

struct queue* push(struct queue* q, int val){
	
	q->head_tail = push_back(q->head_tail, val);
	q->size = q->size + 1;

	return q;
}