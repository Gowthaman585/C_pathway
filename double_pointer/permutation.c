#include<stdio.h>
#include<string.h>
/* ******************************************************
 * swap_strings : 					*
 *  							*
 * Aim : to interchange address between two		*
 * strings to swap them.				*
 * 							*
 * Arguments : array of strings which is		*
 * extracted as double pointer, two index value's	*
 * here it taken has left and right.			*
 * 							*
 * return : since handling pointer, no need of		* 
 * returning values to program.				*
 * ******************************************************/

void swap_strings(char **arr, int left, int right){
	char *temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void reverse_strings(char **arr, int left , int right){
	while(left < right){
		swap_strings(arr,left,right);
		left++;
		right--;
	}
}

int next_permutation(int no_of_words, char **arr){
	
	int piviot = no_of_words - 2;
	
	while(piviot >=0 && strcmp(arr[piviot],arr[piviot+1]) >=0){
		piviot--;
	}

	/* **************************************
	 * if the piviot <0 which is 		*
	 * negative number indicating		*
	 * it traversed and compared 		*
	 * with all the elements in strings	*
	 * but no piviot element found which	*
	 * is end of all possible permutation.	*
	 * *************************************/
	if(piviot < 0){
		return 0;
	}

	int great_then_piviot = no_of_words - 1;
	while(strcmp(arr[great_then_piviot],arr[piviot]) <=0){
		great_then_piviot--;
	}
	swap_strings(arr,great_then_piviot,piviot);
	/* **********************************************
	 * Reverse all the elements that is right to	*
	 * the piviot element to last element of the	*
	 * string.					*
	 * *********************************************/
	reverse_strings(arr,piviot+1,no_of_words-1);

	return 1;

}

