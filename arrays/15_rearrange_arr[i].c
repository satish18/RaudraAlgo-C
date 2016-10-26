/*Rearrange an array so that arr[i] becomes arr[arr[i]] with O(1) extra space */

#include <stdio.h>
#include <stdlib.h>

void Rearrange(int *arr, int size)
{
	int index;

	for(index = 0 ; index < size; index++)
		arr[index] += (arr[arr[index]] % size) * size;

	for(index = 0; index < size; index++)
		arr[index] /= size;
}

void printArray(int *arr, int size)
{
	for(int index = 0; index < size; index++)
		printf("%d\t", arr[index]);
}

int main()
{
	int *arr, size;
	printf("Enter size of array\n");
	scanf("%d", &size);

	//allocate memory 
	arr = (int *) malloc(sizeof(int) * size);

	printf("Enter elements in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	Rearrange(arr, size);

	printArray(arr, size);
	return 0;
}