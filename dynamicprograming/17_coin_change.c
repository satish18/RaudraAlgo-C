#include <stdio.h>
#include <stdlib.h>

int minCoinChange(int *coins, int size, int amount)
{
	int i, j, x, y, temp[amount+1][size];
    
    for(i = 0; i < size; i++)
    	temp[0][i] = 1;
 
    for(i = 1; i < amount+1; i++)
    {
        for(j = 0; j < size; j++)
        {
            x = (i-coins[j] >= 0)? temp[i - coins[j]][j]: 0; 
            y = (j >= 1)? temp[i][j-1]: 0; 
            temp[i][j] = x + y;
        }
    }
    return temp[amount][size-1];
}

int main()
{
	int *coins, size, amount, index;
	printf("Enter size of the coins\n");
	scanf("%d", &size);

	//allocate memory
	coins = (int *)malloc(sizeof(int) * size);
	for(index = 0; index < size; index++)
		scanf("%d", &coins[index]);
	printf("Enter the amount\n");
	scanf("%d", &amount);
	printf("Minimum coin change is = %d", minCoinChange(coins, size, amount));
	return 0;
}

//Time complexity: O(m * n)
//Space complexity: O(m * n)