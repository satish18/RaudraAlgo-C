/* Write an algorithm to remove all duplicates from a given string */
/*
Method-1
========
Algorithm:

step1: Sort the all characters in a given string
step2: Remove duplicates by comparing the current character with previous character.

The above algorithm doesn't keep the original order of the input string. But still 
remove the duplicates in a given string
*/

/* 
Method-2 (Using Hashing)
========================

*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define COUNT 256

char *removeDuplicates(char *str)
{
	int hash[COUNT] = {0};
	int currentIndex, finalIndex = 0;
	char temp;
	for(currentIndex = 0; str[currentIndex]; currentIndex++)
	{
		temp = str[currentIndex];
		if(hash[temp] == 0)
		{
			hash[temp] = 1;
			str[finalIndex++] = str[currentIndex];
		}
	}
	str[finalIndex] = '\0';
	return str;
}

int main()
{
	char str[] = "ravindra ravula";
	printf("The final string after remove of duplicates is = %s\n", 
		removeDuplicates(str));

}