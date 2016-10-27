#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
	return a < b ? a: b;
}

int max(int a, int b)
{
	return a > b ? a: b;
}

int MaximumIndexDifference(int *arr, int size)
{
	int maxDifference = -1, index1, index2;

	int *leftMin = (int *)malloc(sizeof(int) * size);
	int *rightMax = (int *)malloc(sizeof(int) * size);

	leftMin[0] = arr[0];
	for(index1 = 1; index1 < size; index1++)
		leftMin[index1] = min(arr[index1], leftMin[index1 - 1]);

	rightMax[size - 1] = arr[size - 1];
	for(index1 = size - 2; index1 >=0; index1--)
		rightMax[index1] = max(arr[index1], rightMax[index1+1]);

	//traverse both arrays
	index1 = 0, index2 = 0;

	while( index2 < size && index1 < size)
	{
		if(leftMin[index1] < rightMax[index2])
		{
			maxDifference = max(maxDifference, index2 - index1);
			index2 += 1;
		}
		else
			index1 += 1;
	} 
	return maxDifference;
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

	printf("Maximum Index Difference = %d", MaximumIndexDifference(arr, size));

	return 0;
}