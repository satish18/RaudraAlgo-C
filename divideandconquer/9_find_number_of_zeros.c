/*Find number of zeros in an array */
#include <stdio.h>
#include <stdlib.h>

int getFirstZero(int *arr, int start, int end)
{
	if( end >= start )
	{
		int middle = start + (end - start) / 2;
		if (( middle == 0 || arr[middle - 1] == 1) && arr[middle] == 0)
            return middle;

        return (arr[middle] == 1) ? getFirstZero(arr, (middle + 1), end):
        getFirstZero(arr, start, (middle - 1));
	}
	return -1;
}

int countNumberOfZeros(int *arr, int size)
{
	int first = getFirstZero(arr, 0, size-1);
	return first == -1 ? 0: size - first;
}

int main()
{
	int *arr, size, ele;
	printf("Enter size of an array\n");
	scanf("%d", &size);
	//allocate memory for array
	arr = (int *)malloc(size * sizeof(int));

	printf("Enter Array elements ");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	printf("The number of zeros present is = %d", 
		countNumberOfZeros(arr, size));
	return 0;
}
