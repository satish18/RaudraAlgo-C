#include <stdio.h>
#include <stdlib.h>

void RotateLeftByOne(int arr[], int size)
{
	int first = arr[0], index;
	for(index = 0; index < size - 1 ; index++)
		arr[index] = arr[index+1];
	arr[index] = first;
}

void RotateLeft(int arr[], int d, int size)
{
	for(int index = 0; index < d; index++)
		RotateLeftByOne(arr, size);
}

void printArray(int arr[], int size)
{
	for(int index = 0; index < size; index++)
		printf("%d\t", arr[index]);
}

int main()
{
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int size = sizeof(arr) / sizeof(arr[0]);
	RotateLeft(arr, 3, size);
	printArray(arr, size);
	return 0;
}