#include <stdio.h>
#include <unistd.h>
#include "stringToFloat.h"

float getFloat(char* s, int str_len){
	// Check if string is valid
	int i = 0;
	int dotcount = 0;
	for(int i=0; i<str_len; i++){
		if(s[i] == '.') dotcount++;
		if(s[i] != '.' && s[i] != '-' && (s[i]-'0' < 0 || s[i]-'0' > 9)) return 100001.0;
		if(s[i] == '-' && i!=0) return 100001.0;
	}
	if(dotcount > 1) return 100001.0;

	// call syscall
	long answer;
	answer = syscall(441, s, str_len);
	
	// return 
	double inter = (double) answer / 100000;
	float ans_ret = (float) inter;
	return ans_ret;
}
