#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int max(int a, int b) 
{ 
	return (a > b)? a : b;
}

int cutttingRod(int *arr, int size)
{
	int temp[size + 1], i, j, maxVal;
	temp[0] = 0;
	for(i = 1; i <= size; i++)
	{
		maxVal = INT_MIN;
		for(j = 0; j < i; j++)
			maxVal = max(maxVal, arr[j] + temp[i - j - 1]);
		temp[i] = maxVal;
	}
	return temp[size];   
}
 
/* Driver program to test above functions */
int main()
{
	int size, *arr;
	printf("Enter size of the array\n");
	scanf("%d", &size);

	//allocate memory
	arr = (int *)malloc(sizeof(int) * size);
	printf("Enter prices in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

    printf("Maximum Value is %d\n", cutttingRod(arr, size));
    return 0;
}