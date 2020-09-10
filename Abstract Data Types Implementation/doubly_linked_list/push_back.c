#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct head_tail_pair push_back(struct head_tail_pair head_tail, int val){
	struct node* to_push = (struct node*)malloc(sizeof(struct node));
	to_push->data = val;
	to_push->next = NULL;
	
	if(head_tail.head == NULL){
		head_tail.head = to_push;
		head_tail.tail = to_push;
		to_push->prev = NULL;
		return head_tail;
	}

	head_tail.tail->next = to_push;
	to_push->prev = head_tail.tail;
	head_tail.tail = head_tail.tail->next;

	return head_tail;
}