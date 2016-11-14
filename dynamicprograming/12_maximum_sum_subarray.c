#include <stdio.h>
#include <stdlib.h>

int maxSubArraySum(int *arr, int size)
{
	int maxSoFar = 0, maxEndingHere = 0;
	for(int index = 0; index < size; index++)
	{
		maxEndingHere = maxEndingHere + arr[index];
		if(maxEndingHere < 0)
			maxEndingHere = 0;
		else if(maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;
	}
	return maxSoFar;
}

int main()
{
	int size, *arr;
	printf("Enter size of the array\n");
	scanf("%d", &size);

	//allocate memory
	arr = (int *)malloc(sizeof(int) * size);

	printf("Enter elements in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	printf("Maximum contiguous sub array sum is = %d", maxSubArraySum(arr, size));
	return 0;
}