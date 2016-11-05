#include <stdio.h>
#include <stdlib.h>

void searchEleInMatrix(int **mat, int size, int ele)
{
	int row, col;
	for(row = 0, col = size - 1; row < size && col >= 0; )
	{
		if(mat[row][col] == ele)
		{
			printf("Element found at %d, %d\n", row, col);
			break;
		}
		mat[row][col]> ele ? col--: row++;
	}
	if(row == size && col == 0)
	   printf("\n Element not found\n");
}

int main()
{
    int size, i, j, ele;
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

    printf("Enter element to search\n");
    scanf("%d", &ele);
    searchEleInMatrix(mat, size, ele);
    return 0;
}