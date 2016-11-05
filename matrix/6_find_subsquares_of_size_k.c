#include <stdio.h>
#include <stdlib.h>

void printSumOfSubSquaresK(int **mat, int size, int k)
{
	if(k > size) return;
	int temp[size][size], i, j, sum;
	for(j = 0; j < size; j++)
	{
		sum = 0;
		for(i = 0; i < k; i++) sum += mat[i][j];

		temp[0][j] = sum;
		for(i = 1; i < size -k +1; i++)
		{
			sum += (mat[i + k -1][j] - mat[i-1][j]);
			temp[i][j] = sum;
		}
	}

	for(i = 0; i < size - k + 1; i++)
	{
		sum = 0;
		for(j = 0; j < k; j++)
			sum += temp[i][j];
		printf("%d\t", sum);
		for(j = 1; j < size - k + 1; j++)
		{
			sum += (temp[i][j+k-1] - temp[i][j-1]);
			printf("%d\t", sum);
		}
		printf("\n");
 
   }
	
}

int main()
{
	int size, i, j, k;
    printf("Enter size of the matrix\n");
    scanf("%d", &size);
    //allocate memory for 2-D array
    int **mat = (int **)malloc(sizeof(int *) * size);
    for(i = 0 ; i < size; i++)
        mat[i] = (int *)malloc(sizeof(int) * size);

    printf("Enter elements in matrix\n");
    for(i = 0; i < size; i++)
    	for(j = 0; j < size; j++)
    		scanf("%d", &mat[i][j]);

    printf("Enter the value of k\n");
    scanf("%d", &k);

    printSumOfSubSquaresK(mat, size, k);
    return 0;
}

// Time complexity: O(n^2)