#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>

int sum(int count ,...){
	/* ******************************************************
	 * The va_list is an build-in varibale			*
	 * provided by <stdarg.h> header file.			*
	 * 							*
	 * va_list helps to access the argument			* 
	 * list of a functions parameters that			*
	 * avialabe in the stack. 				*		
	 * 							*
	 * it only points to the memory of the arguments.	*
	 * *****************************************************/
	
	va_list args;

	/* ******************************************************
	 * va_start is used to point to the very next element	*
	 * to the count(which is the first argument of this 	*
	 * function -> int sum(int count ,...) 			*
	 * ******************************************************/
	
	va_start(args,count);

	int total_sum = 0;

	for(int i =0;i<count;i++){
		total_sum = total_sum + va_arg(args,int);
	}

	va_end(args);

	return total_sum;
}
	
int min(int count,...){
	va_list args;
	va_start(args,count);
	int min = va_arg(args,int);

	for(int i =0;i<count-1;i++){
		int cur = va_arg(args,int);
		if(cur < min){
			min = cur;
		}
	}

	va_end(args);

	return min;
}

int max(int count,...){
	va_list args;
	va_start(args,count);

	int max = va_arg(args,int);

	for(int i =0;i<count-1;i++){
		int cur = va_arg(args,int);
		if(cur > max){
			max = cur;
		}
	}
	va_end(args);
	return max;
}
