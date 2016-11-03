/* Given a sorted array find the smallest missing number */
#include <stdio.h>
#include <stdlib.h>

int findFirstSmallestMissing(int *arr, int start, int end)
{
	if(start > end)
		return end + 1;
	if(start != arr[start])
		return start;
	int middle = (start + end) / 2;

	return (arr[middle] > middle)? findFirstSmallestMissing(arr, start, middle): 
	findFirstSmallestMissing(arr, middle+1, end);
}

int main()
{
	int *arr, size;
	printf("Enter number of elements in an array\n");
	scanf("%d", &size);
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);
	printf("First smallest missing number is = %d", 
		findFirstSmallestMissing(arr, 0, size-1));
	return 0;
} 