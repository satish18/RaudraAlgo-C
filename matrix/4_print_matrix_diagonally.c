#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
	return a > b? a: b;
}

int min(int a, int b)
{
	return a < b? a: b;
}

int minimum(int a, int b, int c)
{
	return min(min(a, b), c);
}

void printDiagonalOrder(int **mat, int rows, int cols)
{
	for(int line = 1; line <= (rows + cols -1); line++)
	{
		int start = max(0, line - rows);
		int count = minimum(line, (cols - start), rows);
		for(int index = 0; index < count; index++)
			printf("%d\t", mat[(min(rows, line)) - index - 1][start + index]);
		printf("\n");
	}
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

    printDiagonalOrder(mat, rows, cols);
    return 0;
}