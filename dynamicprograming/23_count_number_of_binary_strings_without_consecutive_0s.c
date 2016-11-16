#include <stdio.h>
#include <stdlib.h>

int countStrings(int num)
{
	int temp1[num], temp2[num], index;
	temp1[0] = temp2[0] = 1;
	for(index = 1; index < num; index++)
    {
        temp1[index] = temp1[index-1] + temp2[index-1];
        temp2[index] = temp1[index-1];
    }
    return temp1[num-1] + temp2[num-1];


}

int main()
{
	int num;
	printf("Enter a number\n");
	scanf("%d", &num);
	printf("The number of binary strings withou consecutive 0's = %d",
		countStrings(num));
	return 0;
}