#include <stdio.h>
#include <stdlib.h>
#define SIZE 4 
 
 
void printSolution(int solution[SIZE][SIZE])
{
    int i, j;
    for(i = 0; i < SIZE; i++)
    {
        for(j = 0; j < SIZE; j++)
            printf(" %d ", solution[i][j]);
        printf("\n");
    }
}
 
int isSafe(int maze[SIZE][SIZE], int x, int y)
{
    return (x >= 0 && x < SIZE && y >= 0 && y < SIZE && maze[x][y] == 1);
}

int solveMaze(int maze[SIZE][SIZE], int x, int y, int solution[SIZE][SIZE])
{
    if(x == SIZE-1 && y == SIZE-1)
    {
        solution[x][y] = 1;
        return 1;
    }

    if(isSafe(maze, x, y))
    {
        solution[x][y] = 1; 
        if (solveMaze(maze, x+1, y, solution) || solveMaze(maze, x, y+1, solution))
            return 1;
        solution[x][y] = 0;
        return 0;
    }    
    return 0;
}

int solveRatInMaze(int maze[SIZE][SIZE])
{
    int solution[SIZE][SIZE] = { {0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0},
                                 {0, 0, 0, 0}
                               };
    if(!solveMaze(maze, 0, 0, solution))
    {
        printf("Solution doesn't exist\n");
        return 0;
    }
    printSolution(solution);
    return 1;
}
 
int main()
{
    int maze[SIZE][SIZE]  =  { {1, 1, 0, 0},
                               {1, 1, 1, 1},
                               {0, 0, 1, 0},
                               {1, 1, 1, 1}
                             };
 
    solveRatInMaze(maze);
    return 0;
}