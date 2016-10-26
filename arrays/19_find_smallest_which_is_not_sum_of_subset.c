/*Find the smallest positive integer value that cannot be represented as sum of any subset of a given array*/
#include <stdio.h>
#include <stdlib.h>

int findSmallestInt(int *arr, int size)
{
	int result = 1;

	for (int index = 0; index < size && arr[index] <= result; index++)
		result += arr[index];
	return result;
}

int main()
{
	int *arr, size;
	printf("Enter number of elements in an array\n");
	scanf("%d", &size);

	//allocate memory for array
	arr = (int *) malloc(size * sizeof(int));
	
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	printf("Smallest positive integer is = %d", findSmallestInt(arr, size));
	return 0;
}
