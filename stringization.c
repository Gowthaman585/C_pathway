/***************************************************
 * STRINGIZATION
 * MACROS-PREPROC
 * EXAMPLE CODE
 ***************************************************/
#include<stdio.h>
/***************************************************
 * Need to use printf along with the macro definiton not in main function
 * immediate used of arguments of macros #'arg' is required must not any space
 ***************************************************/
#define stringization(num1,num2) printf(#num1 " + " #num2 " = %d\n", (num1+num2))
int main(void){
	stringization(10,100);
	return 0;
}
