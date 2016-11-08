#include <stdio.h>
#include <stdlib.h>

void productArrayWithoutDivision(int *arr, int size)
{

    int temp = 1, *product, index;

    //allocate memory
    product = (int *)malloc(sizeof(int) * size);
    for(index = 0; index < size; index++)
    {
        product[index] = temp;
        temp *= arr[index];
    }
    temp = 1;
    for(index = size - 1; index >= 0; index--)
    {
        product[index] *= temp;
        temp *= arr[index];
    }
    for(index = 0; index < size; index++)
        printf("%d\t", product[index]);
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

	productArrayWithoutDivision(arr, size);
	return 0;
}