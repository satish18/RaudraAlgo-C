#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int getCount(int **mat, int size, int k)
{
    int i = size - 1, j = 0, count = 0;
    while(i >= 0 && j < size)
    {
        if(mat[i][j] <= k)
        {
            count += i+1;
            j++;
        }
        else
            i--;
    } 
    return count;
}

void KthSmallestInMatrix(int **mat, int size, int k)
{
    int start = mat[0][0], end = mat[size - 1][size -1];

    while (start < end)
    {
        int middle = (start + end) / 2;
        int count = getCount(mat, size, middle);
        if(count < k)
            start = middle + 1;
        else
            end = middle;
    }
    printf("The %d th smallest element is = %d", k, end);
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
    KthSmallestInMatrix(mat, size, k);
    return 0;
}