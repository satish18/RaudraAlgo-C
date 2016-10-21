//Check whether given integer x is a majority element or not in a sorted array 

#include <stdio.h>
#include <stdlib.h>

int isMajority(int *arr, int size, int X)
{
	//get last index according to even or odd 
	int lastIndex = size % 2 ? (size / 2 +1) : (size / 2);

	for(int index = 0; index < lastIndex; index++)
		if(arr[index] == X && arr[index+size/2] == X)
			return 1;
	return 0;
}


int main()
{
	int *arr, size, X;
	printf("Enter size of an array\n");
	scanf("%d", &size);
	//allocate memory for array
	arr = (int *)malloc(size * sizeof(int));

	printf("Enter Array elements in sorted order");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	printf("Enter element to check\n");
	scanf("%d", &X);
	if(isMajority(arr, size, X))
		printf("The %d appears more than n/2 times\n", X);
	else
		printf("The %d is not appears more than n/2 times \n", X);


} 	