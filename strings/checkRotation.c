/*Program to check where given strings are rotations to each other with concatenation*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int checkRotations(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	char *temp;
	void *ptr;
	if (len1 != len2)
		return 0;
	temp = (char *)malloc(sizeof(char)*(len1*2 + 1));
	temp[0] = '\0';
	//concatinating string1
	strcat(temp, str1);
	strcat(temp, str1);
	//check string2 is substring of temp or not
	ptr = strstr(temp, str2);
	free(temp);
	return ptr ? 1: 0;	
}

int main()
{
	char str1[100], str2[100];
	printf("Enter string1");
	scanf("%s", str1);
	printf("Enter string2");
	scanf("%s", str2);
	if (checkRotations(str1, str2))
		printf("Strings are rotations of each other\n");
	else
		printf("Strings are not rotations to each other");
	return 0;
}