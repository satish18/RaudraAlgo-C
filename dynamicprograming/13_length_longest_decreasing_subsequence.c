#include <stdio.h>
#include <stdlib.h>

int LongestDecreasingSubsequence(int *arr, int size)
{
	int *lds, i, j, maxLen = 0;
	lds = (int *)malloc(sizeof(int) * size);

	for(i = 0; i < size; i++)
		lds[i] = 1;

	for (i = size-2; i >= 0; i--)
      for (j = size-1; j > i; j--)
         if (arr[i] > arr[j] && lds[i] < lds[j] + 1)
            lds[i] = lds[j] + 1;
 
    for (i = 0; i < size; i++ )
        if (maxLen < lds[i])
            maxLen = lds[i];
    free(lds); 
    return maxLen;
}

int main()
{
	int *arr, size;
	printf("Enter size of the array\n");
	scanf("%d", &size);

	//allocate memory 
	arr = (int *)malloc(sizeof(int) * size);

	printf("Enter elements in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	printf("Length of longest decreasing sub sequence is = %d", 
		LongestDecreasingSubsequence(arr, size));

	return 0;
}