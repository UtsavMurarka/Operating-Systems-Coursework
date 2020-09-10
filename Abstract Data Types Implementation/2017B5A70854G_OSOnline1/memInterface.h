#ifndef _MEM
#define _MEMHEADER


extern void addToMemory(int data, int* BobMem, int k);
   
extern void printMemoryState(int *BobMem, int k);

extern int initializeMemory(FILE* ip, int* BobMem, int k);

extern int memTest(int data, int* BobMem, int k);


#endif
