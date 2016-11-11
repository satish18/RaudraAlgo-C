#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp; 
}

void permutation(char *str, int start, int end)
{
	int index;
	if(start == end)
		printf("%s\n", str);
	else
	{
		for(index = start; index <= end; index++)
		{
			swap(&str[start], &str[index]);
			permutation(str, start+1, end);
			swap(&str[start], &str[index]);
		}
	}
}

int main()
{
	char str[100];
	printf("Enter string\n");
	scanf("%s", str);
	permutation(str, 0, strlen(str) - 1);
	return 0;
}