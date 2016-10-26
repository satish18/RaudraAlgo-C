#include <stdio.h>
#include <stdlib.h>

void findCommonElements(int *arr1, int *arr2, int *arr3, int size1, int size2, int size3)
{
	int index1 = 0, index2 = 0, index3 = 0;

	while(index1 < size1 && index2 < size2 && index3 < size3)
	{
		if(arr1[index1] == arr2[index2] && arr2[index2] == arr3[index3])
		{
			printf("%d\t", arr1[index1]);
			index1++;	index2++;	index3++;
		}
		else if(arr1[index1] < arr2[index2])
			index1++;

		else if(arr2[index2] < arr3[index3])
			index2++;

		else
			index3++;
	}
}

int main()
{
	int size1, size2, size3, *arr1, *arr2, *arr3, index;
	printf("Enter sizes of Three arrays\n");
	scanf("%d %d %d", &size1, &size2, &size3);

	//allocate memory
	arr1 = (int *)malloc(sizeof(int) * size1);
	arr2 = (int *)malloc(sizeof(int) * size2);
	arr3 = (int *)malloc(sizeof(int) * size3);

	printf("Enter elements in first array\n");
	for(index = 0; index < size1; index++)
		scanf("%d", &arr1[index]);

	printf("Enter elements in second array\n");
	for(index = 0; index < size2; index++)
		scanf("%d", &arr2[index]);

	printf("Enter elements in third array\n");
	for(index = 0; index < size3; index++)
		scanf("%d", &arr3[index]);

	findCommonElements(arr1, arr2, arr3, size1, size2, size3);

	return 0;

}