#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max(int a, int b)
{
	return a > b? a: b; 
}

int maximum(int a, int b, int c)
{
	return max(max(a, b), c);
}

int middleCrossingSum(int *arr, int start, int middle, int end)
{
    // Include elements on left of mid.
    int sum = 0, leftSum = INT_MIN, rightSum = INT_MIN, index;
    for (index = middle; index >= start; index--)
    {
        sum += arr[index];
        if (sum > leftSum)
        	leftSum = sum;
    }
    sum = 0;
    for (index = middle+1; index <= end; index++)
    {
        sum += arr[index];
        if (sum > rightSum)
          rightSum = sum;
    }
    return leftSum + rightSum;
}

int maximumSubArraySum(int *arr, int start, int end)
{
	if(start == end)
		return arr[start];

	int middle = (start + end) / 2;

	return maximum(maximumSubArraySum(arr, start, middle),
			   maximumSubArraySum(arr, middle+1, end),
			   middleCrossingSum(arr, start, middle, end));
}

int main()
{
	int *arr, size;
	printf("Enter size of an array\n");
	scanf("%d", &size);
	//allocate memory for array
	arr = (int *)malloc(size * sizeof(int));

	printf("Enter Array elements ");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);
	printf("Maximum contiguous sub array sum is = %d", 
		maximumSubArraySum(arr, 0, size-1));
	return 0;
}