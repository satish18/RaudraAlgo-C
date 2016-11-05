#include <stdio.h>
#include <stdlib.h>

int checkDiagonal(int **mat, int row, int col, int rows, int cols)
{
	int result = mat[row][col];
	while(++row < cols && ++col < rows)
		if(mat[row][col] != result)
			return 0;
	return 1;
}

int isToepliz(int **mat, int rows, int cols)
{
	int index;
	for(index = 0; index < rows; index++)
		if(!checkDiagonal(mat, 0, index, rows, cols))
			return 0;

	for(index = 1; index < cols; index++)
		if(!checkDiagonal(mat, index, 0, rows, cols))
			return 0;
	return 1;
}

int main()
{
	int rows, cols, i, j;
	printf("Enter number of rows in matrix\n");
	scanf("%d", &rows);

	printf("Enter number of columns in matrix\n");
	scanf("%d", &cols);

	//allocate memory
	int **mat = (int **)malloc(sizeof(int *) * rows);
    for(i = 0 ; i < cols; i++)
        mat[i] = (int *)malloc(sizeof(int) * rows);

    printf("Enter elements in matrix\n");
    for(i = 0; i < rows; i++)
    	for(j = 0; j < cols; j++)
    		scanf("%d", &mat[i][j]);
    if(isToepliz(mat, rows, cols))
    	printf("Given Matrix is a Toepliz\n");
    else
    	printf("Given Matrix is not Toepliz\n");

    return 0;
}