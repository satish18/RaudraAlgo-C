#include <stdio.h>
#include <stdlib.h>    

int findPartion(int *arr, int size)
{
	int sum = 0, i, j;
	for(i = 0; i < size; i++)
		sum += arr[i];
	if(sum%2 != 0)
		return 0;
	int partition[sum/2 + 1][size + 1];
	for(i = 0; i <= size; i++)
		partition[0][i] = 1;
	for(i = 1; i <= sum/2; i++)
		partition[i][0] = 0;
	for(i = 1; i <= sum/2; i++)
	{
		for(j = 1; j <= size; j++)
		{
			partition[i][j] = partition[i][j-1];
			if(i >= arr[j-1])
				partition[i][j] = partition[i][j] || partition[i-arr[j-1]][j-1];
		}
	}
	return partition[sum/2][size];
}     
 
int main()
{
	int *arr, size, index;
	printf("Enter size of the array\n");
	scanf("%d", &size);

	//allocate memory 
	arr = (int *)malloc(sizeof(int) * size);
	for(index = 0; index < size; index++)
		scanf("%d", &arr[index]);
	if(findPartion(arr, size))
		printf("Given array can be divided into two subsets of equal sum\n");
	else
		printf("Given array can't be divided into two subsets of equal sum\n");
	return 0;
}


//Time complexity: O(sum * n)
//Space complexity: O(sum * n)