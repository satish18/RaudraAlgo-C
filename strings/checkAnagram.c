#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_CHARS 256

int checkAnagrams(char *str1, char *str2)
{
	int count1[TOTAL_CHARS] = {0};
	int count2[TOTAL_CHARS] = {0};
	int index;
	if (strlen(str1) != strlen(str2))
		return 0;
	for(index = 0; str1[index] && str2[index]; index++)
	{
		count1[str1[index]]++;
		count2[str2[index]]++;
	}
	for(index = 0; index < TOTAL_CHARS; index++)
		if(count1[index] != count2[index])
			return 0;
	return 1;
}

int main()
{
	char str1[] = "ravindrababuravula";
	char str2[] = "ravularavindrababu";
	if( checkAnagrams(str1, str2))
		printf("The two strings are anagram of each other");
	else
		printf("The two strings are not anagram of each other");
	return 0;
}