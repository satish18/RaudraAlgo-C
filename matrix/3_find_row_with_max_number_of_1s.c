#include <stdio.h>
#include <stdlib.h>

int firstRow(int *first, int start, int end)
{
	if(end >= start)
	{
		int middle = (start + end) / 2;
		if((middle == 0 || first[middle - 1] == 0) && first[middle] == 1)
			return middle;
		else
			return (first[middle] == 0)? firstRow(first, (middle + 1), end):
		firstRow(first, start, (middle - 1));
	}
	return -1;
}

int getRowWithMax1s(int **mat, int rows, int cols)
{
	int maxRowIndex = 0;
	int col = firstRow(mat[0], 0, cols-1);
	if(col == -1)
		col = cols - 1;
	for(int row = 1; row < rows; row++)
		for(; col >= 0 && mat[row][col] == 1; col--)
			maxRowIndex = row;
	return maxRowIndex;
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

    printf("%d rd row has maximum number of 1's\n", 
    	getRowWithMax1s(mat, rows, cols));
    return 0;
}