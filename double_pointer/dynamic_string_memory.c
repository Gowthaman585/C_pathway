/********************************************************
* DYNAMIC MEMORY ALLOCATION USING MALLOC
* *******************************************************
* Aim : 
* 	using double pointer allocate a default memory size to get a line
* of strings and based on the length trim the memory size.
* *******************************************************
* DISCLAMIER !!!
* *******************************************************
* The intended program is suitable for input		*
* which has no space between the strings in single line	*
* if multiple space between in single line each		*
* string in same line is considered to be as 		*
* different line					*
* ******************************************************/


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	
	char **arr;
	
	/* Default memory size taken as 1024 [Suggested}
	 * the size of char* depends upon the os
	 */
	
	arr = malloc(1024 * sizeof(char*));

	/* Get the number of lines of the strings */
	
	int lines;
	scanf("%d",&lines);

	for(int i =0;i<lines;i++){

		/* ************************************
		 * Since the default size is 1024 
		 * allocating same size for each line of strings intially
		 * ************************************/
		*(arr + i) = malloc(1024* sizeof(char));

		scanf("%s",*(arr + i));

		/* ************************************
		 * After deriving the line of strings 
		 * according to the size of the entered line of strings
		 * trimming them with realloc along 
		 * with strlen()
		 * ************************************/
		*(arr + i) = realloc(*(arr + i),strlen(*(arr + i)) + 1);
	}
	
	/* **********************
	 * Printing the size of each line
	 * **********************/
	printf("=============================");
	printf("\nSize of strings in each line");
	printf("\n=============================\n");
	for(int i =0;i<lines;i++){
		printf("Line %d : %d\n",i,strlen(*(arr + i)));
	}

	for (int i =0;i<lines;i++){
		free(*(arr+i));
	}
	free(arr);
	return 0;
}
