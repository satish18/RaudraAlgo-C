#include <stdio.h>
#include <stdlib.h>

void printTwoOddNumbers(int arr[], int size)
{
	int xor = arr[0], index, num1 = 0, num2 = 0, setBit;
	for(index = 1; index < size; index++)
		xor = xor ^ arr[index];
	setBit = xor & ~(xor - 1);
	for(index = 0; index < size; index++)
	{
		if(arr[index] & setBit)
			num1 = num1 ^ arr[index];
		else
			num2 = num2 ^ arr[index];
	}
	printf("The Two Odd numbers are %d and %d", num1, num2);
}

int main()
{
	int *arr, size;
	printf("Enter size of the array\n");
	scanf("%d", &size);
	printf("Enter elements in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);
	printTwoOddNumbers(arr, size);
	return 0;
}