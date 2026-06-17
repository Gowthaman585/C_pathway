#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
/****************************************************************
 * Aim:								*
 * 	To convert every first character of word in a sentence	*
 * into capitalize. 						*
 * Example: 							*
 * Hello world learning c is super fun 				*
 * >>>>>> Hello World Learning C is Super Fun <<<<<<< 		*
 * *************************************************************/
int main(){
	char *arr;
	/* Intializing a default safe size of 1024 byte for ch 
	 * using malloc */
	arr = malloc(1024 * sizeof(char));
	/* getchar() is used to get char-by-char util a newline 
	 * or reached EOF */
	int ch;
	int length=0;
	while((ch = getchar())!=EOF && ch!='\n'){
		/* No white spaces is considered as characters,
		 * so other then that all are included in the 
		 * char array */
		if(ch!=' '){
			*(arr + length) = ch;
			length = length + 1;
		}
		/* After reaching the whitespace we probably 
		 * reached end of a word. according to the size
		 * of the word the arr get trimmed using
		 * realloc() */
		else if(ch == ' '){
			arr = realloc(arr, length+1);
			/* Reassuring the string with proper
			 * null termination */
			*(arr + length+1) = '\0';
			*(arr + 0 ) = toupper(*(arr + 0));
			printf("%s",arr);
			length = 0;
		}
	}
	free(arr);
	return 0;
}
