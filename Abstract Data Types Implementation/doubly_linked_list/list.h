#ifndef _LIST_HEADER
#define _LST_HEADER

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

struct head_tail_pair{
    struct node* head;
    struct node* tail;
};

/*
    Pre-condition:
        head_tail is an instance of struct head_tail_pair and contains the current head and tail of the Linked List
        val is the value to be added to the back of the Linked List

    Post-condition:
        Returns the head_tail_pair of modified Linked List
*/
extern struct head_tail_pair push_back(struct head_tail_pair head_tail, int val);

/*
    Pre-condition:
        head_tail is an instance of struct head_tail_pair and contains the current head and tail of the Linked List
        val is the value to be added to the front of the Linked List

    Post-condition:
        Returns the head of modified Linked List
*/      
extern struct head_tail_pair push_front(struct head_tail_pair head_tail, int val);

/*
    Pre-condition:
        head_tail is an instance of struct head_tail_pair and contains the current head and tail of the Linked List

    Post-condition:
        Returns the head_tail_pair of modified Linked List
*/
extern struct head_tail_pair pop_front(struct head_tail_pair head_tail);

/*
    Pre-condition:
        head_tail is an instance of struct head_tail_pair and contains the current head and tail of the Linked List

    Post-condition:
        Returns the head_tail_pair of modified Linked List
*/
extern struct head_tail_pair pop_back(struct head_tail_pair head_tail);

/*
	Pre-condition:
		head is the current head of Linked list to be printed
	Post-condition:
		Prints the entire Linked List;
*/
extern void print_list(struct head_tail_pair head_tail);


#endif