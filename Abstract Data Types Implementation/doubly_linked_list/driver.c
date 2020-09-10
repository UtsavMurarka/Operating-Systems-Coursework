#include "list.h"
#include <stdio.h>


int main(int argc, char* argv[]) {
    // struct node* head = NULL;
    // struct node* tail = NULL;
    struct head_tail_pair htp;
    htp.head = NULL;
    htp.tail = NULL;

    FILE *ip;
    ip = fopen(argv[1], "r");
    
    while(!feof (ip)){
        char op[10];
        //printf("Enter Operation: ");
        fscanf(ip, "%s", &op);
        int val;

        if(strcmp(op, "pushback")==0){
            //printf("Enter Value: ");
            fscanf(ip, "%d", &val);
            htp = push_back(htp, val);
        }

        if(strcmp(op, "pushfront")==0){
            //printf("Enter Value: ");
            fscanf(ip, "%d", &val);
            htp = push_front(htp, val);
        }

        if(strcmp(op, "popback")==0){
            htp = pop_back(htp);
        }

        if(strcmp(op, "popfront")==0){
            htp = pop_front(htp);
        }

        if(strcmp(op, "print")==0){
            print_list(htp);
        }
    }
    fclose(ip);
    return 0;
}