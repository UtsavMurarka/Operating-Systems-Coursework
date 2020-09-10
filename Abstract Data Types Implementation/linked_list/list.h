#ifndef _LIST_HEADER
#define _LST_HEADER

struct node {
    int data;
    struct node* next;
};

/*
    Pre-condition:
        head is the current head of the Linked List
        val is the value to be added to the back of the Linked List

    Post-condition:
        Returns the head of modified Linked List
*/
extern struct node* push_back(struct node* head, int val);

/*
    Pre-condition:
        head is the current head of the Linked List
        val is the value to be added to the front of the Linked List

    Post-condition:
        Returns the head of modified Linked List
*/      
extern struct node* push_front(struct node* head, int val);

/*
    Pre-condition:
        head is the current head of the Linked List from which front element is to be popped out

    Post-condition:
        Returns the head of modified Linked List
*/
extern struct node* pop_front(struct node* head);

/*
    Pre-condition:
        head is the current head of the Linked List from which back element is to be popped out

    Post-condition:
        Returns the head of modified Linked List
*/
extern struct node* pop_back(struct node* head);

/*
	Pre-condition:
		head is the current head of Linked list to be printed
	Post-condition:
		Prints the entire Linked List;
*/
extern void print_list(struct node* head);


#endif