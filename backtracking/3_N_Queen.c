#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
 
void printSolution(int board[SIZE][SIZE])
{
	int i, j;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE; j++)
            printf(" %d ", board[i][j]);
        printf("\n");
    }
}

int isSafe(int board[SIZE][SIZE], int row, int col)
{
    int i, j; 
    for(i = 0; i < col; i++)
        if(board[row][i])
            return 0; 
    for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0; 
    for(i = row, j = col; j >= 0 && i < SIZE; i++, j--)
        if (board[i][j])
            return 0;
    return 1;
} 

int solveNQueen(int board[SIZE][SIZE], int col)
{
	int index;
	if (col >= SIZE)
		return 1;

	for(index = 0; index < SIZE; index++)
	{
		if(isSafe(board, index, col))
		{
			board[index][col] = 1;
			if(solveNQueen(board, col+1))
				return 1;
			board[index][col] = 0;
		}
	}    
    return 0;
}
 
int main()
{
	int board[SIZE][SIZE] = { {0, 0, 0, 0},
							  {0, 0, 0, 0},
							  {0, 0, 0, 0},
							  {0, 0, 0, 0}};
	if(solveNQueen(board, 0))
		printSolution(board);
	else
		printf("Solution doesn't exist\n");    
    return 0;
}
