#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
 
int MatrixChainMultiplication(int *arr, int size)
{
	int mat[size][size]; 
    int i, j, k, L, q;
    for (i = 1; i < size; i++)
        mat[i][i] = 0; 

    for (L = 2; L < size; L++)
    {
        for (i = 1; i < size-L+1; i++)
        {
            j = i+L-1;
            mat[i][j] = INT_MAX;
            for (k = i; k <= j-1; k++)
            {
                q = mat[i][k] + mat[k+1][j] + arr[i-1]*arr[k]*arr[j];
                if (q < mat[i][j])
                    mat[i][j] = q;
            }
        }
    }
 
    return mat[1][size-1];
}
 
int main()
{
	int size, *arr;
	printf("Enter number of matrices\n");
	scanf("%d", &size);

	//allocate memory
	arr = (int *)malloc(sizeof(int) * size);

	printf("Enter dimention of matrix\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &arr[index]);

	printf("Minimum number of multiplications needed is = %d\n", 
		MatrixChainMultiplication(arr, size));
	return 0;    
}
