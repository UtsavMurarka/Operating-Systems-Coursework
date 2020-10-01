#include <linux/kernel.h>
#include <linux/types.h>
#include <linux/syscalls.h>
#include "string_to_float_syscall.h"

/*
	PRECONDITION : 
		s should be of valid representation of a float
		str_len > 0

	POSTCONDITION:
		int will be returned in float*1000 format if s is in range [-100000.0, -0.01] U [0.01, 100000.0]
		pecision till 5 decimals
*/

SYSCALL_DEFINE2(string_to_float_syscall, char*, s, int, str_len)
{
	int i,end;
	long answer, multiplier;
	bool has_dot = false; // flag to indicate if the string has decimal point or not
	char inp_str[str_len + 10];
	
	// copy the input string to kernel space so that it can be modified
	int iter=0;
	for(iter=0; iter<str_len; iter++){
		inp_str[iter] = s[iter];
		if(inp_str[iter] == '.') has_dot = true;
	}

	//append ".00000" or "00000" to avoid out of range exception
	if(has_dot == false){
		inp_str[str_len] = '.';
		inp_str[str_len+1] = '0';
		inp_str[str_len+2] = '0';
		inp_str[str_len+3] = '0';
		inp_str[str_len+4] = '0';
		inp_str[str_len+5] = '0';
	}
	else  {
		inp_str[str_len] = '0';
		inp_str[str_len+1] = '0';
		inp_str[str_len+2] = '0';
		inp_str[str_len+3] = '0';
		inp_str[str_len+4] = '0';
	}

	i=0;
	while(inp_str[i]!='.'){
		i++;
	}
	
	// end is end pointer, for 5 point precision
	end = i+5;

	multiplier = 1;
	answer = 0;
	while(end>=0){
		if(inp_str[end]=='.'){
			end--;
		}
		if(inp_str[end]=='-'){
			answer *= -1;
			break;
		}
		answer += (inp_str[end] - '0')*multiplier;
		multiplier *= 10;
		end--;
	}

	if(answer > 10000000000)
		return 10000200000;
	if(answer > -1000 && answer < 1000)
		return 10000300000;
	if(answer < -10000000000)
		return 10000400000;
	
	return answer;

}