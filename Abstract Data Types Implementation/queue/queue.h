#ifndef _Q_HEADER
#define _Q_HEADER

struct queue{
    struct head_tail_pair head_tail;
    int size;
    int front;
};

extern struct queue* create_queue();

extern struct queue* push(struct queue *q, int val);
      
extern struct queue* pop(struct queue *q);

#endif