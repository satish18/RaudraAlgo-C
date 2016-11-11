#include <stdio.h>
#include <stdlib.h>
int max(int a, int b)
{
	return a>b ? a: b;
}

int KnapSack(int *profit, int *wt, int size, int Weight)
{
	int i, w;
   int temp[size + 1][Weight + 1];
 
   for (i = 0; i <= size; i++)
   {
       for (w = 0; w <= Weight; w++)
       {
           if (i==0 || w==0)
               temp[i][w] = 0;
           else if (wt[i - 1] <= w)
                 temp[i][w] = max(profit[i-1] + temp[i-1][w-wt[i-1]],  temp[i-1][w]);
           else
                 temp[i][w] = temp[i-1][w];
       }
   } 
   return temp[size][Weight];
}

int main()
{
	int *profit, *wt, Weight, size, index;
	printf("Enter number of items\n");
	scanf("%d", &size);

	profit = (int *)malloc(sizeof(int) * size);
	wt = (int *)malloc(sizeof(int) * size);

	printf("Enter profits \n");
	for(index = 0; index < size; index++)
		scanf("%d", &profit[index]);
	printf("Enter weiths \n");
	for(index = 0; index < size; index++)
		scanf("%d", &wt[index]);
	printf("Enter capacity of knapsack\n");
	scanf("%d", &Weight);

	printf("Total profit is = %d", KnapSack(profit, wt, size, Weight));
	return 0;
}

