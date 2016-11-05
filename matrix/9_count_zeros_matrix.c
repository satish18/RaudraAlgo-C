#include <stdio.h>
#include <stdlib.h>

int countZeros(int **mat, int size)
{
	int row, col, count = 0;
	for(row = size - 1, col = 0; col < size; col++)
	{
		while(mat[row][col])
			if(--row < 0)
				return count;
		count += (row + 1);
	}
	return count;
}


int main()
{
	int size, i, j;
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

    printf("%d", countZeros(mat, size));   

    return 0;
}