#include <stdio.h>
#define ROWS 6
#define COLS 5

int min(int a, int b)
{
	return a < b ? a: b;
}

int minimum(int a, int b , int c)
{
	return min(min(a, b), c);
}
 
void getMaximumSubSquare(int arr[ROWS][COLS])
{
	int i, j, temp[ROWS][COLS], resultMax, maxOfRow, maxOfCol;
	for(i = 0; i < ROWS; i++)
		temp[i][0] = arr[i][0];

	for(j = 0; j < COLS; j++)
		temp[0][j] = arr[0][j];

	for(i = 1; i < ROWS; i++)
	{
		for(j = 1; j < COLS; j++)
		{
			if(arr[i][j] == 1)
				temp[i][j] = minimum(temp[i][j-1], temp[i-1][j], temp[i-1][j-1]) + 1;
			else
				temp[i][j] = 0;
		}
	}
	resultMax = temp[0][0], maxOfRow = 0, maxOfCol = 0;
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			if(resultMax < temp[i][j])
			{
				resultMax = temp[i][j];
				maxOfRow = i;
				maxOfCol = j;
			}
		}
	}
	printf(" Maximum size sub-matrix is: \n");
	for( i = maxOfRow; i > maxOfRow - resultMax; i--)
	{
		for(j = maxOfCol; j > maxOfCol - resultMax; j--)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
}     
      
 
int main()
{
	int arr[ROWS][COLS] =  {{0, 1, 1, 0, 1}, 
                   {1, 1, 0, 1, 0}, 
                   {0, 1, 1, 1, 0},
                   {1, 1, 1, 1, 0},
                   {1, 1, 1, 1, 1},
                   {0, 0, 0, 0, 0}};
    getMaximumSubSquare(arr);
    return 0;                
} 

//Time complexity: O(m * n)
//Space complexity: O(m * n)