#include <stdio.h>
#include <stdlib.h>

int countWaysReachNthStair(int steps, int m)
{
	int result[steps+1], i, j;
	result[0] = result[1] = 1;
	for(i = 2; i <= steps; i++)
	{
		result[i] = 0;
		for(j = 1; j <= m && j <= i; j++)
			result[i] += result[i-j];
	}
	return result[steps];
}

int main()
{
	int steps, m;
	printf("Enter number of steps\n");
	scanf("%d", &steps);
	printf("Enter maximum steps climb at a time\n");
	scanf("%d", &m);
	printf("Number of ways to reach nth stair is = %d", countWaysReachNthStair(steps, m));
	return 0;
}