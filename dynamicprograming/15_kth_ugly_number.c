#include <stdio.h>
#include <stdlib.h>

int min(int a, int b)
{
	return a < b ? a: b;
}

int minimum(int a, int b, int c)
{
	return min(min(a, b), c);
}

int getKthUglyNumber(int num)
{
	int *ugly = (int *)malloc(sizeof(int) * num);
	int i2 = 0, i3 = 0, i5 = 0, index, nextMulipleOf2 = 2, nextMulipleOf3 = 3,
	nextMulipleOf5 = 5, nextUglyNumber = 1;
	ugly[0] = 1;
	for(index = 1; index < num; index++)
	{
		nextUglyNumber = minimum(nextMulipleOf2, nextMulipleOf3, nextMulipleOf5);
		ugly[index] = nextUglyNumber;
		if(nextUglyNumber == nextMulipleOf2)
		{
			i2 += 1;
			nextMulipleOf2 = *(ugly + i2)*2;
		}
		if(nextUglyNumber == nextMulipleOf3)
		{
			i3 += 1;
			nextMulipleOf3 = *(ugly + i3)*3;
		}
		if(nextUglyNumber == nextMulipleOf5)
		{
			i5 += 1;
			nextMulipleOf5 = *(ugly + i5)*5;
		}
	}
	return nextUglyNumber;
}
 
int main()
{
	int num;
	printf("Enter number\n");
	scanf("%d", &num);
	printf("%d th ugly number is = %d", num, getKthUglyNumber(num));
    return 0;
}
