#include <stdio.h>
#include <stdlib.h>

int getMaxDifference(int *arr, int size)
{
	int diff = arr[1] - arr[0];
	int currSum = diff, maxSum = currSum;

	for(int index = 1; index < size; index++)
	{
		diff = arr[index + 1] - arr[index];
		currSum = currSum > 0 ? currSum + diff: diff;
		if(currSum > maxSum)
			maxSum = currSum;
	}
	return maxSum;
}


int main()
{
	int *arr, size;
	printf("Enter size of the array\n");
	scanf("%d", &size);

	arr = (int *)malloc(sizeof(int) * size);
	printf("Enter elements in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	printf("Max Difference is = %d", getMaxDifference(arr, size));
	return 0;
}