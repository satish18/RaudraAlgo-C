#include <stdio.h>
#include <stdlib.h>

void findMinMax(int *arr, int *sum_upto, int *max, int *min, int size)
{
    for(int index = 1; index < size; index++)
    {
        sum_upto[index] = sum_upto[index-1] + ((arr[index] == 0)? 
                     -1: 1);
        if (sum_upto[index] < (*min))
            *min = sum_upto[index];
        if (sum_upto[index] > (*max))
            *max = sum_upto[index];
    }
}

void findLargestSubArray(int *arr, int size)
{
	int maxSize = -1, startIndex, sum_upto[size], 
    min = arr[0], max = arr[0], index, temp;
	sum_upto[0] = (arr[0] == 0)? -1: 1;
    findMinMax(arr, sum_upto, &max, &min, size);
    int hash[max - min + 1];
    for(index = 0; index < max - min + 1; index++)
    	hash[index] = -1;
    for (index = 0; index < size; index++) {
    	if (sum_upto[index] == 0) {
           maxSize = index + 1;
           startIndex = 0;
        }
        temp = sum_upto[index] - min;
        if (hash[temp] == -1)
            hash[temp] = index;
        else {
            if ((index - hash[temp]) > maxSize)
            {
                maxSize = index - hash[temp];
                startIndex = hash[temp] + 1;
            }
        }
    }
    if (maxSize == -1)
        printf("No such subarray");
    else
        printf("Largest sub array starts from %d to %d", 
        	startIndex, startIndex + maxSize - 1);
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

	findLargestSubArray(arr, size);
	return 0;
}