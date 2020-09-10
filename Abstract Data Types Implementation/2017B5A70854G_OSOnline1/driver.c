#include <stdio.h>
#include "memInterface.h"

int main(int argc, char* argv[]){
	int k = *argv[1] - '0';
	if(k>5 || k<2){
		printf("ERROR: Invalid Value of K.\n");
		return 0;
	}

	int BobMem[k];

	FILE *ip1;
    ip1 = fopen(argv[2], "r");

    FILE *ip2;
    ip2 = fopen(argv[3], "r");

    FILE *op;
    op = fopen(argv[4], "w+");

    int numInitialized;
    numInitialized = initializeMemory(ip1, BobMem, k);

    int attemp = 0;
    int score = 0;

    while(!feof (ip2)){
        int query;

        fscanf(ip2, "%d", &query);
        if(!(query==1 || query==2 || query==3)){
        	printf("ERROR: Invalid Query type : %d\n", query);
        	continue;
        }
        if(query == 1){
        	int data;
        	fscanf(ip2, "%d", &data);
        	score = score + memTest(data, BobMem, k);
        	addToMemory(data, BobMem, k);
        	attemp++;
        }
        if(query == 2){
        	printMemoryState(BobMem, k);
        }
        if(query == 3){
        	printf("Current Score: %d and Attemps: %d\n", score, attemp);
        }
    }
    fclose(ip1);
    fclose(ip2);
    fclose(op);
}