#include <stdio.h>
#include <stdlib.h>

int minimum(int a, int b)
{
	return a > b? a: b;
}

int min(int a, int b, int c)
{
	return minimum(minimum(a, b), c);
}

void getMaxSubSquare(int **arr, int rows, int cols)
{
	int row, col, maxRow, maxCol, resultMax;

	int **temp = (int **)malloc(sizeof(int *) * rows);
    for(col = 0 ; col < cols; col++)
        temp[col] = (int *)malloc(sizeof(int) * rows);

	for(row = 0; row < rows; row++)
		temp[row][0] = arr[row][0];

	for(col = 0; col < cols; col++)
		temp[0][col] = arr[0][col];

	for(row = 1; row < rows; row++)
		for(col = 1; col < cols; col++)
			temp[row][col] = (arr[row][col] == 1)? 
			min(temp[row][col-1], temp[row - 1][col], temp[row - 1][col - 1]) + 1: 0;

	// resultMax = temp[0][0]; maxRow = 0; maxCol = 0;
	// for(row = 0; row < rows; row++)
	// {
	// 	for(col = 0; col < cols; col++)
	// 	{
	// 		if(resultMax < temp[row][col])
	// 		{
	// 			resultMax = temp[row][col];
	// 			maxRow = row; maxCol = col;
	// 		}
	// 	}
	// }
	// printf("\n Maximum size sub-matrix with 1's: \n");
	// for(row = maxRow; row > maxRow - resultMax; row--)
	// {
	// 	for(col = maxCol; col > maxCol - resultMax; col--)
	// 		printf("%d ", arr[row][col]);
	// 	printf("\n");
	// }
}

int main()
{
	int rows, cols, i, j;
	printf("Enter number of rows in matrix\n");
	scanf("%d", &rows);

	printf("Enter number of columns in matrix\n");
	scanf("%d", &cols);

	//allocate memory
	int **arr = (int **)malloc(sizeof(int *) * rows);
    for(i = 0 ; i < cols; i++)
        arr[i] = (int *)malloc(sizeof(int) * rows);

    printf("Enter elements in matrix\n");
    for(i = 0; i < rows; i++)
    	for(j = 0; j < cols; j++)
    		scanf("%d", &arr[i][j]);
    getMaxSubSquare(arr, rows, cols);
    return 0;

}