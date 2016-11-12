#include <stdio.h>
#include <stdlib.h>

int MaximumSumIncreasingSubsequence(int *arr, int size)
{
	int i, j, maxSum = 0, temp[size];
	for(i = 0; i < size; i++)
		temp[i] = arr[i];

	for(i = 1; i < size; i++)
		for(j = 0; j < i; j++)
			if(arr[i] > arr[j] && temp[i] < (temp[j] + arr[i]))
				temp[i] = temp[j] + arr[i];

	for(i = 0; i < size; i++)
		if(maxSum < temp[i])
			maxSum = temp[i];

    return maxSum; 
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

    printf("Maximum sum increasing sub sequence is = %d\n", 
    	MaximumSumIncreasingSubsequence(arr, size));
    return 0;
}