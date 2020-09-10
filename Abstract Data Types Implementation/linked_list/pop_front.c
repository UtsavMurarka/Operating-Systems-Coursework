#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node* pop_front(struct node* head){
	if(head == NULL){
		printf("Linked List is empty!\n");
		return head;
	}
	struct node* curr = head;
	head = head->next;
	free(curr);
	return head;
}