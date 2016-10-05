#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 256

char getMaximumOccuringChar(char *str)
{
	int temp[COUNT] = {0};
	int len = strlen(str), max = -1, i;
	char result;
	for(i = 0; i < len; i++)
		temp[str[i]]++;
	for(i = 0; i < len; i++ )
	{
		if(max < temp[str[i]])
		{
			max = temp[str[i]];
			result = str[i];
		}
	}
	return result;
}

int main()
{
	char str[] = "GATEXCEL";
	printf("Maximum occuring character is = %c\n", getMaximumOccuringChar(str));
	return 0;	
}