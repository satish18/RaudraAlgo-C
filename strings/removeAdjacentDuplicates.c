// recursively remove adjacent duplicates
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* removeDuplicates(char *str, char *lastRemoved)
{	
	char *removeStr;
	//return string if length is either 1 or 0
	if( (str[0] == '\0') || (str [1] == '\0') )
		return str;

	if( str[0] == str[1])
	{
		*lastRemoved = str[0];
		while(str[1] && str[0] == str[1])
			str++;
		return removeDuplicates(++str, lastRemoved);
	}
	removeStr = removeDuplicates(str+1, lastRemoved);
	if( removeStr[0] && removeStr[0] == str[0])
	{
		*lastRemoved = str[0];
		return (removeStr+1);
	}
	if( removeStr == '\0' && *lastRemoved == str[0])
		return removeStr;
	removeStr--;
	removeStr[0] = str[0];
	return removeStr;
}

int main()
{
	char str[] = "adbbcbbbc";
	char lastRemoved = '\0';
	printf("%s", removeDuplicates(str, &lastRemoved));
	return 0;
}