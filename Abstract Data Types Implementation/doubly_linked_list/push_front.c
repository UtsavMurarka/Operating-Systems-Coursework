#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct head_tail_pair push_front(struct head_tail_pair head_tail, int val){
	struct node* to_push = (struct node*)malloc(sizeof(struct node));
	to_push->data = val;
	to_push->prev = NULL;
	
	if(head_tail.head == NULL){
		head_tail.head = to_push;
		head_tail.tail = to_push;
		to_push->next = NULL;
		return head_tail;
	}

	head_tail.head->prev = to_push;
	to_push->next = head_tail.head;
	head_tail.head = head_tail.head->prev;

	return head_tail;
}