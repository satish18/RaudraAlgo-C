/* Get maximum element in which all elements are distinct */
#include <stdio.h>
#include <stdlib.h>

int getMaximumElement(int *arr, int start, int end)
{
	if (start == end)
		return arr[start];

	if ((end == start + 1) && arr[start] >= arr[end])
		return arr[start];
	
	if ((end == start + 1) && arr[start] < arr[end])
        return arr[end];
 
    int middle = (start + end) / 2; 

    if (arr[middle] > arr[middle + 1] && arr[middle] > arr[middle - 1])
    	return arr[middle];

    return (arr[middle] > arr[middle + 1] && arr[middle] < arr[middle - 1])?
    getMaximumElement(arr, start, middle-1): getMaximumElement(arr, middle + 1, end);
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

	printf("The maximum element is = %d", getMaximumElement(arr, 0, size-1));
	return 0;
}