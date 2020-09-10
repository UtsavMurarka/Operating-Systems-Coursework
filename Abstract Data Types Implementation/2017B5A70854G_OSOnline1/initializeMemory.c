#include <stdio.h>
#include <stdlib.h>
#include "memInterface.h"

int initializeMemory(FILE* ip, int* BobMem, int k){
	int iter;
	for(iter=0; iter<k; iter++){
		BobMem[iter] = -1;
	}

	int i=0;
	while(!feof(ip)){
		int data;
		fscanf(ip, "%d", &data);
		int it;
		int flag = 0;
		for(it=0; it<k; it++){
			if(BobMem[it] == data){
				flag = 1;
			}
		}

		if(flag == 0){
			BobMem[i] = data;
		}
		i++;
	}
	return i;
}