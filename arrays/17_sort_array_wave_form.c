#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void printArray(int *arr, int size)
{
	for(int index = 0; index < size; index++)
		printf("%d\t", arr[index]);
}

void sortInWave(int *arr, int size)
{
	for(int index = 0; index < size; index += 2)
	{
		if(index > 0 && arr[index -1] > arr[index])
			swap(&arr[index], &arr[index - 1]);

		if(index < size - 1 && arr[index] < arr[index+1])
			swap(&arr[index], &arr[index + 1]);
	}
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

	sortInWave(arr, size);

	printArray(arr, size);
}