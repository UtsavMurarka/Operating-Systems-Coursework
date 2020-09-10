#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node* pop_back(struct node* head){
	if(head == NULL){
		printf("Linked List is empty!\n");
		return head;
	}
	struct node* curr = head;
	if(curr->next == NULL) {
		free(curr);
		return NULL;
	}
	while(curr->next->next != NULL){
		curr = curr->next;
	}
	struct node* last_node = curr->next;
	free(last_node);
	curr->next = NULL;

	return head;
}