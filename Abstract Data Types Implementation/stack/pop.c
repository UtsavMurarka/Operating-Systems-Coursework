#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../linked_list/list.h"

struct stack* pop(struct stack* s){
	
	if(s->size == 0){
		printf("Stack is empty\n");
		return s;
	}
	s->head = pop_front(s->head);
	s->size = s->size - 1;
	if(s->head != NULL){
		s->top = s->head->data;
	}
	return s;
}