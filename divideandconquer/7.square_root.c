/*Floor square root */
#include <stdio.h>
#include <stdlib.h>

int squareRoot(int num)
{
	if(num == 0 || num == 1)
		return num;

	int start = 1, end = num, result, middle;

	while( start <= end)
	{
		middle = (start + end) / 2;
		if(middle * middle == num)
			return middle;

		if(middle * middle < num)
		{
			start = middle + 1;
			result = middle;
		}
		else
			end = middle - 1;

	}
	return result;
}

int main()
{
	int num;
	printf("Enter number to find square root\n");
	scanf("%d", &num);

	printf("Square root of number is = %d", squareRoot(num));
	return 0;

}