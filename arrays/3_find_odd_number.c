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
	int arr[] = {3, 4, 6, 5, 6, 3, 5, 4, 6, 3, 5, 5, 3};
	int size = sizeof(arr) / sizeof(arr[0]);
	int result = getOddOccurrenceNumber(arr, size); 
	result ? printf("The odd occurence number is = %d", result): printf("Not found");
	return 0;
}