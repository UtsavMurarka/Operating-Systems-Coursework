#include <stdio.h>
#include <stdlib.h>
#include "memInterface.h"

void addToMemory(int data, int* BobMem, int k){
	int i;
	int idx = -1;
	for(i=0; i<k; i++){
		if(BobMem[i] == data){
			idx = i;
		}
	}

	int j;
	if(idx != -1){
		for(j = idx-1; j>=0; j--){
			BobMem[j+1] = BobMem[j];
		}
		BobMem[0] = data;
	}
	else {
		for(j = k-2; j>=0; j--){
			BobMem[j+1] = BobMem[j];
		}
		BobMem[0] = data;
	}
}