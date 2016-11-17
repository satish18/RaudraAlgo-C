#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 256

char getMaximumOccuringChar(char *str)
{
	int temp[COUNT] = {0};
	int len = strlen(str), max = -1, index;
	char result;
	for(index = 0; index < len; index++)
		temp[str[index]]++;
	for(index = 0; index < len; index++ )
	{
		if(max < temp[str[index]])
		{
			max = temp[str[index]];
			result = str[index];
		}
	}
	return result;
}

int main()
{
	char str[] = "ravindra ravula";
	printf("Maximum occuring character is = %c\n", getMaximumOccuringChar(str));
	return 0;	
}