#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
/************************************************
 * AIM:
 * To design and implement a C program that finds the maximum 
 * length of a prefix from a given string 's' that exists as a 
 * subsequence within a second string 't'.
 * ***********************************************/

int check(char *str, char *cmp){
   int str_len = strlen(str);
   int cmp_len = strlen(cmp);
   /* ******************************
    * Using to variables cur , prev for
    * easy understanding.
    * how?:
    * s = "debugger"
    * t = "debianunDistos"
    * consider this two strings, form the string 's'
    * we need to find the larget substring that is
    * availabe in string 't' even in subsequence
    * order.
    * for that how cur, prev helps?:
    * checking the first letter of 's' which is 'd'
    * the cur pointer starts at the first character of 'd'
    * in the string .
    * STEP 1:
    * 'd' == cur ['d'] same next we need to move to the
    * next character on both sides.
    * 'e' == cur ['e'] same jump.
    * 'b' == cur ['b'] same jump.
    * 'u' == cur ['i'] not equal so we need to jump to 
    * nest character only in 't' so the cur ['a'].
    * STEP 2:
    * 'u' == cur['a'] not same jump to next char in 't'
    * 'u' == cur['n'] again
    * 'u' == cur['u'] now same again jump both the character.
    * until matching characters fount note the length, it is not
    * found end the loop.
    * **************************************************************/
   int cur;
   int prev = 0;
   int len = 0;
   int found = 0;
    
   for(int i =0;i<str_len;i++){
        found = 0;
        for(int j = prev;j<cmp_len;j++){
            if(str[i] == cmp[j]){
                cur = j;
                prev = cur + 1;
                len = len + 1;
                found = 1;
                break;
            }
        }
        if (found == 0){
            break;
        }
    }
    return len;
}

int main(){
    
	char *str;
	str = malloc(1024 * sizeof(char));
    	scanf("%1023s",str);
    
    	str = realloc(str,strlen(str)+1);
    
   	char *cmp;
   	cmp = malloc(1024* sizeof(char));
    	scanf("%1023s",cmp);
    
   	cmp = realloc(cmp,strlen(cmp)+1);
    
    	int len = check(str,cmp);
    
    	printf("%d",len);
    
    	return 0;
}

