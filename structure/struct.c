#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int main(){
	struct part{
		int number;
		int array[SIZE];
	}arr[SIZE];

	arr[0].array[2] = 1;
	arr[0].number = 100;
	printf("arr[0].array[2]= %d - arr[0].number= %d\n",arr[0].array[2],arr[0].number);
	printf("&arr[0]= %p ,&arr[0].number= %p &arr[0].array[0]= %p &arr[0].array[2]=%d\n", &arr[0],&arr[0].number,&arr[0].array[0],arr[0].array[2]);
	printf("&arr= %p\n", &arr);
	arr[1].array[2] = 2;
	arr[1].number = 200;
	printf("arr[1].array[2]= %d, arr[1].number= %d\n",arr[1].array[2],arr[1].number);
	printf("&arr= %p &arr[1]= %p, &arr[1].number= %p &arr[1].array[2]=%p\n",&arr,&arr[1],&arr[1].number,&arr[1].array[2]);
	printf("sizeof(part)= %zu",sizeof(struct part));

	return 0;
}

