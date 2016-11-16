#include <stdio.h>
#include <stdlib.h>
#define ROWS 4
#define COLS 4

int min(int a, int b)
{
	return a < b ? a: b;
}

int minimum(int a, int b int c)
{
	return min(min(a, b), c);
}

int minCostPath(int cost[ROWS][COLS], int m, int n)
{
	int i, j, temp[ROWS][COLS];
	temp[0][0] = cost[0][0];

	for(i = 1; i <= m; i++)
		temp[i][0] = temp[i-1][0] + cost[i][0];

	for(j = 1; j <= n; j++)
		temp[0][j] = temp[0][j-1] + cost[0][j];

	for(i = 1; i <= m; i++)
		for(j = 1; j <= n; j++)
			temp[i][j] = minimum(temp[i-1][j-1], temp[i-1][j], temp[i][j-1]) + cost[i][j];
	return temp[m][n];
}

int main()
{
	int cost[ROWS][COLS] = { {1, 2, 3, 4},
							 {4, 5, 8, 3},
							 {1, 5, 9, 2},
							 {6, 2, 4, 3}};
	printf("Minimum cost path is = %d\n", minCostPath(cost, 3, 3));
	return 0;
}

//Time complexity: O(m * n)
//Space complexity: O(m * n)