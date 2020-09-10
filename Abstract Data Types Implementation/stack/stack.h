#ifndef _STACK_HEADER
#define _STACK_HEADER

struct stack{
    struct node* head;
    int size;
    int top;
};

extern struct stack* create_stack();

extern struct stack* push(struct stack *s, int val);
      
extern struct stack* pop(struct stack *s);

#endif