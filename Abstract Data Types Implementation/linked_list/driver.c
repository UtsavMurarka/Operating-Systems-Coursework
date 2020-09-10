#include "list.h"
#include <stdio.h>


int main() {
    struct node* head = NULL;
    // head = push_back(head, 1);
    // head = push_back(head, 2);
    // head = push_back(head, 3);
    // head = push_back(head, 4);
    // head = push_back(head, 5);
    // head = push_back(head, 6);
    // head = push_back(head, 7);
    // print_list(head);
    // head = push_front(head, 11);
    // head = push_front(head, 13);
    // head = push_front(head, 14);
    // head = push_front(head, 15);
    // head = push_front(head, 16);
    // head = push_front(head, 17);
    // print_list(head);
    // head = pop_front(head);
    // head = pop_front(head);
    // head = pop_front(head);
    // print_list(head);
    // head = pop_back(head);
    // head = pop_back(head);
    // head = pop_back(head);
    // print_list(head);
    
    while(1){
        char op[10];
        printf("Enter Operation: ");
        scanf("%s", &op);
        int val;
        if(strcmp(op, "pushback")==0){
            printf("Enter Value: ");
            scanf("%d", &val);
            head = push_back(head, val);
        }

        if(strcmp(op, "pushfront")==0){
            printf("Enter Value: ");
            scanf("%d", &val);
            head = push_front(head, val);
        }

        if(strcmp(op, "popback")==0){
            head = pop_back(head);
        }

        if(strcmp(op, "popfront")==0){
            head = pop_front(head);
        }

        if(strcmp(op, "print")==0){
            print_list(head);
        }
        if(strcmp(op, "quit")==0){
            printf("\n Exiting... \n");
            break;
        }
    }
    return 0;
}