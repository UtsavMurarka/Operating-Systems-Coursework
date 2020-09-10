#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void print_list(struct head_tail_pair head_tail){
	while(head_tail.head != NULL){
		printf("%d --> ", head_tail.head->data);
		head_tail.head = head_tail.head->next;
	}
	printf("\n");
}