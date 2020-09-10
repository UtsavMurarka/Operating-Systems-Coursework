#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "../linked_list/list.h"

struct stack* push(struct stack* s, int val){
	
	s->head = push_front(s->head, val);
	s->size = s->size + 1;
	s->top = val;

	return s;
}