#include <stdio.h>
#include <stdlib.h>

//find triplet using sorting
int compareFun(const void *a, const void *b)
{
	return ( *(int*)a - *(int*)b);
}

int findTriplet(int arr[], int size, int sum)
{
	int leftIndex, rightIndex, tripletSum;
	qsort(arr, size, sizeof(int), compareFun);
	for(int index = 0; index < size; index++)
	{
		leftIndex = index + 1;
		rightIndex = size - 1;
		while( leftIndex < rightIndex)
		{
			tripletSum = arr[index] + arr[leftIndex] + arr[rightIndex];
			if(tripletSum == sum)
			{
				printf("Triplet is %d, %d and %d", arr[index], arr[leftIndex], arr[rightIndex]);
				return 1;
			}
			if(tripletSum < sum)
				leftIndex++;
			else
				rightIndex--;
		}
	}
	return 0;
}

int main()
{
	int arr[] = {2, 5, 35, 8, 12, 9};
	int sum = 25;
	int size = sizeof(arr) / sizeof(arr[0]);
	if(!findTriplet(arr, size, sum))
		printf("Triplet not found");
	return 0;
}