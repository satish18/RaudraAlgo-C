#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int printSolution(int *temp, int size)
{
	int k = (temp[size] == 1)? 1: printSolution(temp, temp[size]-1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", k, temp[size], size);
    return k;
}

void WordWrapProblem(int *lines, int size, int width)
{
	int extraSpace[size+1][size+1], lineCost[size+1][size+1], totalCost[size+1], 
	temp[size+1], i, j;

	for(i = 1; i <= size; i++)
	{
		extraSpace[i][i] = width - lines[i-1];
		for(j = i+1; j <= size; j++)
			extraSpace[i][j] = extraSpace[i][j-1] - lines[j-1] - 1;	
	}

	for(i = 1; i <= size; i++)
	{
		for(j = i; j <= size; j++)
		{
			if(extraSpace[i][j] < 0)
				lineCost[i][j] = INT_MAX;
			else if(j == size && extraSpace[i][j] >= 0)
				lineCost[i][j] = 0;
			else
				lineCost[i][j] = extraSpace[i][j] * extraSpace[i][j];
		}
	}
	totalCost[0] = 0;
	for(j = 1; j <= size; j++)
    {
    	totalCost[j] = INT_MAX;
        for(i = 1; i <= j; i++)
        {
        	if(totalCost[i-1] != INT_MAX && lineCost[i][j] != INT_MAX && 
        		(totalCost[i-1] + lineCost[i][j] < totalCost[j]))
        	{
                totalCost[j] = totalCost[i-1] + lineCost[i][j];
                temp[j] = i;
            }
        }
    } 
    printSolution(temp, size);
}
 
int main()
{
	int size, *lines, width;
	printf("Enter size of the array\n");
	scanf("%d", &size);

	//allocate memory
	lines = (int *)malloc(sizeof(int) * size);
	printf("Enter values of array\n");
	for(int index = 0; index < size; index++)
		scanf("%d", &lines[index]);

	printf("Enter width of line\n");
	scanf("%d", &width);
	WordWrapProblem(lines, size, width);
    return 0;
}