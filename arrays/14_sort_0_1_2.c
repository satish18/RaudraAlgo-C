#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void sort012(int *arr, int size)
{
	int start = 0, end = size-1, middle = 0;

	while( middle <= end)
	{
		switch(arr[middle])
		{
			case 0: swap(&arr[start++], &arr[middle++]);
					break;

			case 1: middle++;
					break;

			case 2: swap(&arr[middle], &arr[end--]);
					break;
		}
	}
}

void printO12(int *arr, int size)
{
	for(int index = 0; index < size; index++)
		printf("%d\t", arr[index]);
}

int main()
{
	int *arr, size;
	printf("Enter size of array\n");
	scanf("%d", &size);

	//allocate memory 
	arr = (int *) malloc(sizeof(int) * size);

	printf("Enter elements in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	sort012(arr, size);
	printO12(arr, size);
	return 0;
}