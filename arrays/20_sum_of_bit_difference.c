#include <stdio.h>
#include <stdlib.h>

int sumBitDifferencesAllPairs(int *arr, int size)
{
    int result = 0, count;
    for (int index = 0; index < 32; index++)
    {
        count = 0;
        for (int index2 = 0; index2 < size; index2++)
            if ((arr[index2] & (1 << index)))
                count++;
        result += (count * (size - count) * 2);
    } 
    return result;
}

int main()
{
    int *arr, size;
	printf("Enter number of elements in an array\n");
	scanf("%d", &size);

	//allocate memory for array
	arr = (int *) malloc(size * sizeof(int));
	
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

    printf("Sum of bit difference is = %d", sumBitDifferencesAllPairs(arr, size));
    return 0;
}