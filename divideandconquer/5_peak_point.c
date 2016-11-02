#include <stdio.h>
#include <stdlib.h>

int findPeakIndex(int *arr, int size, int start, int end)
{
	int middle = start + (end - start)/2;

	if((middle == 0 || arr[middle - 1] <= arr[middle]) && 
		(middle == size-1 || arr[middle+1] <= arr[middle]))
		return middle;
	else 
		return (middle > 0 && arr[middle-1] > arr[middle])? 
	findPeakIndex(arr, size, start, (middle - 1)): 
	findPeakIndex(arr, size, (middle + 1), end);
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

	printf("Peak point is = %d\n", findPeakIndex(arr, size, 0, size-1));
	return 0;
}