#include <stdio.h>
#include <stdlib.h>

int min(int a, int b) { return a < b ? a: b; }
int max(int a, int b) { return a > b ? a: b; }

int maxSubArrayProduct(int arr[], int size)
{
	int currentMaxProduct = 1, currentMinProduct = 1, maximumSoFar = 1, temp;
	for(int index = 0; index < size; index++)
	{
		if(arr[index] > 0)
		{
			currentMaxProduct = currentMaxProduct * arr[index];
			currentMinProduct = min(currentMinProduct * arr[index], 1);			 
		}
		else if(arr[index] == 0)
			currentMaxProduct = currentMinProduct = 1;
		else
		{
			temp = currentMaxProduct;
			currentMaxProduct = max(currentMinProduct * arr[index], 1);
			currentMinProduct = temp * arr[index];
		}
		if(maximumSoFar < currentMaxProduct)
			maximumSoFar = currentMaxProduct;
	} 
	return maximumSoFar;
}

int main()
{
	int arr[] = {0, -1, -4, 0, 8, 0, -2};
	int size = sizeof(arr) / sizeof(arr[0]);
	printf("Maximum sub array product is = %d", maxSubArrayProduct(arr, size));
}