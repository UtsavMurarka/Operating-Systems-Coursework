#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

struct stack* create_stack(){

	struct stack *s = (struct stack*)malloc(sizeof(struct stack));
	s->head = NULL;
	s->size = 0;
	s->top = NULL;

	return s;
}