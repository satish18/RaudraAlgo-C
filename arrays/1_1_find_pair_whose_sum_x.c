#include <stdio.h>
#include <stdlib.h>
#define MAX 10000

void findPairs(int *arr, int size, int sum)
{
	int index, temp;
	int hash[MAX] = {0};

	for(index = 0; index < size; index++)
	{
		temp = sum - arr[index];
		if(temp >= 0 && hash[temp] == 1)
			printf("Pair with given sum  %d is (%d, %d)\n", sum, arr[index], temp);
		hash[arr[index]] = 1;
	}
}

int main()
{
	int size, index, sum, *arr;
	printf("Enter number of Elements in an array \n");
	scanf("%d", &size);
	//allocate memory for array
	arr = (int *) malloc(sizeof(int) * size);
	printf("Enter elements to array\n");
	for(index = 0; index < size; index++)
		scanf("%d", &arr[index]);
	printf("Enter sum value");
	scanf("%d", &sum);
	findPairs(arr, size, sum);
	return 0;
}