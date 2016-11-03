/*Given an array of positive integers. 
All numbers occur even number of times except one number 
which occurs odd number of times.*/

#include <stdio.h>
#include <stdlib.h>

int getOddOccurrenceNumber(int arr[], int size)
{
	int index, result = 0;
	for(index = 0; index < size; index++)
		result = result ^ arr[index];
	return result;
}

int main()
{
	int *arr, size;
	printf("Enter size of the array\n");
	scanf("%d", &size);
	printf("Enter elements in array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);
	int result = getOddOccurrenceNumber(arr, size); 
	result ? printf("The odd occurence number is = %d", result): printf("Not found");
	return 0;
}