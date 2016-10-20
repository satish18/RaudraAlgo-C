#include <stdio.h>
#include <stdlib.h>

void seperateOand1(int arr[], int size)
{
	int leftIndex = 0, rightIndex = size-1; 
	while( leftIndex < rightIndex)
	{
		while((arr[leftIndex] == 0) && (leftIndex < rightIndex))
			leftIndex++;
		while((arr[rightIndex] == 1) && (rightIndex > leftIndex))
			rightIndex--;
		if(leftIndex < rightIndex)
		{
			arr[leftIndex++] = 0;
			arr[rightIndex--] = 1;
		}
	}
}

void printArray(int arr[], int size)
{
	for(int index = 0; index < size; index++)
		printf("%d\t", arr[index]);
}

int main()
{
	int arr[] = {0, 1, 1, 0, 1, 0, 1, 0, 0, 1};
	int size = sizeof(arr) / sizeof(arr[0]);
	seperateOand1(arr, size);
	printArray(arr, size);
	return 0;
}