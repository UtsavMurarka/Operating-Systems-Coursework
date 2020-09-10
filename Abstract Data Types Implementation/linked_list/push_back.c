#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node* push_back(struct node* head, int val){
	struct node* to_push = (struct node*)malloc(sizeof(struct node));
	to_push->next = NULL;
	to_push->data = val;

	if(head == NULL){
		return to_push;	
	}

	struct node* curr = head;
	while(curr->next != NULL){
		curr = curr->next;
	}
	curr->next = to_push;

	return head;
}