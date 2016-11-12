#include <stdio.h>
#include <stdlib.h>

int LongestBitonicSearch(int *arr, int size)
{
	int i, j, LIS[size], LDS[size], maxLen;
	for(i = 0; i < size; i++)
		LIS[i] = LDS[i] = 1;

	for(i = 1; i < size; i++)
		for (j = 0; j < i; j++)
			if (arr[i] > arr[j] && LIS[i] < LIS[j] + 1)
				LIS[i] = LIS[j] + 1;

	for(i = size-2; i >= 0; i--)
		for(j = size-1; j > i; j--)
			if(arr[i] > arr[j] && LDS[i] < LDS[j] + 1)
				LDS[i] = LDS[j] + 1;

    maxLen = LIS[0] + LDS[0] - 1;
    for(i = 1; i < size; i++)
    	if(LIS[i] + LDS[i] - 1 > maxLen)
    		maxLen = LIS[i] + LDS[i] - 1;
    return maxLen;
}

 
int main()
{
	int size, *arr;
	printf("Enter size of the array\n");
	scanf("%d", &size);

	//allocate memory
	arr = (int *)malloc(sizeof(int) * size);
	printf("Enter values of array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	printf("Length of Longest bitonic search is = %d\n", 
		LongestBitonicSearch(arr, size));
    return 0;
}