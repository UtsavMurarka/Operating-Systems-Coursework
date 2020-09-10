#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct head_tail_pair pop_back(struct head_tail_pair head_tail){
	if(head_tail.head == NULL){
		printf("Linked List is empty!\n");
		return head_tail;
	}
	if(head_tail.head == head_tail.tail){
		head_tail.head = NULL;
		head_tail.tail = NULL;
		return head_tail;
	}

	struct node* curr_tail = head_tail.tail;
	head_tail.tail = head_tail.tail->prev;
	free(curr_tail);
	head_tail.tail->next = NULL;

	return head_tail;
}