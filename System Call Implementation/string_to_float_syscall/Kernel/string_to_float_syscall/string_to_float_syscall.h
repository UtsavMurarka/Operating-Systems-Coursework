#ifndef _STRING_TO_FLOAT_SYSCALL_H_
#define _STRING_TO_FLOAT_SYSCALL_H_
#include <linux/linkage.h>
asmlinkage long sys_string_to_float_syscall(char*, int);
#endif