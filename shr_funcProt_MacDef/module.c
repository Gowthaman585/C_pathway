#include<stdio.h>
#include "config.h"
Status print_status(int st){
	if(st == success){
		printf("status : %d\n",success);
	}
	else if(st == failure){
		printf("status : %d\n",failure);
	}
	else if(st == max_limit){
		printf("status : %d\n",max_limit);
	}
	else{
		printf("status : Invalid input");
	}
}
