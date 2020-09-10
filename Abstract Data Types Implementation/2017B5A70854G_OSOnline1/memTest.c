#include <stdio.h>
#include "memInterface.h"

int memTest(int data, int* BobMem, int k){
	int i;
	for(i=0; i<k; i++){
		if(BobMem[i] == data){
			return 1;
		}
	}
	return 0;
}