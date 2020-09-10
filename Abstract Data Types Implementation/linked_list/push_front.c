#include <stdio.h>
#include <stdlib.h>
#include "list.h"

struct node* push_front(struct node* head, int val){
	struct node* to_push = (struct node*)malloc(sizeof(struct node));
	if(head == NULL){
		head = to_push;
		return head;
	}
	to_push->next = head;
	to_push->data = val;
	head = to_push;
	return head;
}