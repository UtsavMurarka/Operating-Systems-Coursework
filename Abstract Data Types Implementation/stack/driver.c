#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


int main() {
    struct stack* s = create_stack();

    while(1){
        char op[5];
        printf("Enter Operation : ");
        scanf("%s", &op);
        if(strcmp(op, "push") == 0){
            printf("Enter Value : ");
            int val;
            scanf("%d", &val);
            s = push(s, val);
        }

        if(strcmp(op, "pop") == 0){
            s = pop(s);
        }

        if(strcmp(op, "top") == 0){
            printf("Top of Stack is : %d\n", s->top);
        }

        if(strcmp(op, "size") == 0){
            printf("Size of Stack is : %d\n", s->size);
        }

        if(strcmp(op, "exit") == 0){
            printf("Exiting .... \n");
            break;
        }
    }


    
}