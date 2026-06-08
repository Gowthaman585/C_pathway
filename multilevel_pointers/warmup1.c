#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(){
	
	char *word1 = "Ich";
	char *word2 = "bin";
	char *word3 = "aus";
	char *word4 = "Tamilnadu";

	char *sentence[] = {word1,word2,word3,word4};

	char ** paragraph[] = {sentence};

	char *** document[] = {paragraph};

	printf("*(sentence+1) : %s\n",*(sentence+1));

	printf("*(paragraph+0) : %s\n",*(paragraph + 0));
	printf("*(*(pargraph + 0)+3) : %s\n",*(*(paragraph+0)+3));
	

	printf("document[0][0][0]: %s\n",document[0][0][0]);
	printf("*(*(*(document + 0)+0)+1): %s\n",(*(*(*(document+0)+0)+1)));
	
	return 0;
}



