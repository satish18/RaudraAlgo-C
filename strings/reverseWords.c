/*Reverese words in a given string */

/*
Algorithm
=========

step1: Reverse the individual words
step2: Reverse the whole string from start to end
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char *start, char *end)
{
	char temp;
	while(start < end)
	{
		temp = *start;
		*start++ = *end;
		*end-- = temp;
	}
}

void RevereseWords(char *str)
{
	char *wordBegin, *temp;
	wordBegin = '\0';
	temp = str;
	//reverse the individual words
	while(*temp)
	{
		if((wordBegin == '\0') && (*temp != ' '))
			wordBegin = temp;
		if(wordBegin && ((*(temp+1) == ' ') || (*(temp + 1) == '\0')))
		{
			reverse(wordBegin, temp);
			wordBegin = '\0';
		}
		temp++;
	}
	//reverse the whole string from start to end
	reverse(str, temp-1);
}

int main()
{
	char str[] = "Raudra Edu Services";
	RevereseWords(str);
	printf("%s\n", str);
	return 0;
}