#include <stdio.h>
#include <stdlib.h>
#define SIZE 8
 
int isSafe(int x, int y, int solution[SIZE][SIZE])
{
    return ( x >= 0 && x < SIZE && y >= 0 && y < SIZE && solution[x][y] == -1);
}
 
void printSolution(int solution[SIZE][SIZE])
{
	int x, y;
    for(x = 0; x < SIZE; x++)
    {
        for(y = 0; y < SIZE; y++)
            printf(" %2d ", solution[x][y]);
        printf("\n");
    }
}

int solveKT(int x, int y, int moveI, int solution[SIZE][SIZE],
                int xMove[SIZE], int yMove[SIZE])
{
	int k, nextX, nextY;
	if(moveI == SIZE*SIZE)
		return 1;
	for (k = 0; k < SIZE; k++)
	{
		nextX = x + xMove[k];
        nextY = y + yMove[k];
        if (isSafe(nextX, nextY, solution))
        {
        	solution[nextX][nextY] = moveI;
        	if(solveKT(nextX, nextY, moveI+1, solution, xMove, yMove))
        		return 1;
        	else
        		solution[nextX][nextY] = -1;
       }
   } 
   return 0;
}
 
int solveKnightTour()
{
    int solution[SIZE][SIZE], x, y; 
    for(x = 0; x < SIZE; x++)
        for(y = 0; y < SIZE; y++)
            solution[x][y] = -1;
 
    int xMove[8] = {  2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = {  1, 2,  2,  1, -1, -2, -2, -1 };
 
    solution[0][0]  = 0; 
    if(solveKT(0, 0, 1, solution, xMove, yMove))
    	printSolution(solution);
    else
    {
    	printf("Solution does not exist");
        return 0;
    }    
    return 1;
}
 
int main()
{
    solveKnightTour();
    return 0;
}