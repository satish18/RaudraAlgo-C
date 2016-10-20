#include <stdio.h>
#include <stdlib.h>

int getMajorityElement(int arr[], int size)
{
	int majorityIndex=0, count=1;
	for(int index = 1; index < size; index++)
	{
		if(arr[majorityIndex] == arr[index])
			count++;
		else
			count--;
		if(count == 0)
		{
			majorityIndex = index;
			count = 1;
		}
	}
	return arr[majorityIndex];
}

int isMajorityElement(int arr[], int size, int majorityElement)
{
	int count=0;
	for(int index = 0; index < size; index++)
		if(arr[index] == majorityElement)
			count++;
	return (count > size/2)? 1: 0;
}

int main()
{
	int arr[] = {1, 4, 4, 1, 4, 4};
	int size = (sizeof(arr)/sizeof(arr[0]));
	int majorityElement = getMajorityElement(arr, size);
	isMajorityElement(arr, size, majorityElement)?
	printf("Majority Element is = %d", majorityElement) : printf("No majority Element");
}
