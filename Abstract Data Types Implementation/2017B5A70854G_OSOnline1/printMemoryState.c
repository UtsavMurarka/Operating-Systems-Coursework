#include <stdio.h>
#include "memInterface.h"

void printMemoryState(int *BobMem, int k){
	int i;
	printf("Current State is : ");
	for(i=0; i<k; i++){
		if(BobMem[i] != -1){	
			printf("%d ", BobMem[i]);
		}
	}
	printf("\n");
}