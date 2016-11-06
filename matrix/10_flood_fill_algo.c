#include <stdio.h>
#include <stdlib.h>

void floodFillAlgo(int **mat, int x, int y, int rows, int cols, int prevColor, int newColor)
{
	if (x < 0 || x >= rows || y < 0 || y >= cols)
        return;
    if (mat[x][y] != prevColor)
        return;
    mat[x][y] = newColor;
 
    floodFillAlgo(mat, x+1, y, rows, cols, prevColor, newColor);
    floodFillAlgo(mat, x-1, y, rows, cols, prevColor, newColor);
    floodFillAlgo(mat, x, y+1, rows, cols, prevColor, newColor);
    floodFillAlgo(mat, x, y-1, rows, cols, prevColor, newColor);
}

void printScreen(int **mat, int rows, int cols)
{
	int i, j;
	for(i = 0; i < rows; i++)
		for(j = 0; j< cols; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
}

int main()
{
	int rows, cols, i, j, newColor;
	printf("Enter number of rows in matrix\n");
	scanf("%d", &rows);

	printf("Enter number of columns in matrix\n");
	scanf("%d", &cols);

    //allocate memory for 2-D array
    int **mat = (int **)malloc(sizeof(int *) * rows);
    for(i = 0 ; i < cols; i++)
        mat[i] = (int *)malloc(sizeof(int) * rows);

    printf("Enter elements in matrix\n");
    for(i = 0; i < rows; i++)
    	for(j = 0; j < cols; j++)
    		scanf("%d", &mat[i][j]);

    printf("Enter location(x, y) of color to change\n");
    scanf("%d %d", &i, &j);

    printf("Enter New Color\n");
    scanf("%d", &newColor);
    floodFillAlgo(mat, i, j, rows, cols, mat[i][j], newColor);
    printScreen(mat, rows, cols);
    return 0;
}

