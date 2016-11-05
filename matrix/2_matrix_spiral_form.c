#include <stdio.h>
#include <stdlib.h>

void printSpiralForm(int **mat, int rows, int cols)
{
	int index, k = 0, l = 0;
	while(k < rows && l < cols)
	{
		for(index = l; index < cols; index++) 
			printf("%d ", mat[k][index]);
		k++;
		for(index = k; index < rows; index++) 
			printf("%d ", mat[index][cols - 1]);
		cols--;
	    if(k < rows)
	    {
	    	for(index = rows-1; index >= l; index--) 
	    		printf("%d ", mat[rows - 1][index]);
	    	rows--;
	    }
	    if(l < cols)
	    {
	    	for(index = rows - 1; index >= k; index--) 
	    		printf("%d ", mat[index][l]);
	    	l++;
	    }
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

    printSpiralForm(mat, rows, cols);
    return 0;
}