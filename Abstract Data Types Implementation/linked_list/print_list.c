#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_list(struct node* head){
	while(head != NULL){
		printf("%d --> ", head->data);
		head = head->next;
	}
	printf("\n");
}