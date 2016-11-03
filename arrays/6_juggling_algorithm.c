#include <stdio.h>
#include <stdlib.h>

int gcd(int size, int d)
{
	return (d == 0) ? size: gcd(d, (size % d));
}

void RotateLeft(int arr[], int d, int size)
{
	int index1, index2, index3, temp;
	for(index1 = 0; index1 < gcd(size, d); index1++)
	{
		temp = arr[index1];
		index2 = index1;
		while(1)
		{
			index3 = index2 + d;
			if(index3 >= size)
				index3 = index3 - size;
			if(index3 == index1)
				break;
			arr[index2] = arr[index3];
			index2 = index3;
		}
		arr[index2] = temp;
	}
}

void printArray(int arr[], int size)
{
	for(int index = 0; index < size; index++)
		printf("%d\t", arr[index]);
}

int main()
{
	int *arr, size, d;
	printf("Enter size of the array\n");
	scanf("%d", &size);
	printf("Enter elements in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);
	printf("Enter value of d\n");
	scanf("%d", &d);
	RotateLeft(arr, d, size);
	printArray(arr, size);
	return 0;
}