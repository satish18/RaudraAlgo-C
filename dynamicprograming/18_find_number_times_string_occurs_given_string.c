#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countString(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int temp[len1+1][len2+1], i, j;

	for(i = 0; i <= len1; i++)
		for(j = 0; j <= len2; j++)
			temp[i][j] = 0;

	for(i = 0; i <= len2; i++)
		temp[0][i] = 0;

	for(i = 0; i <= len1; i++)
        temp[i][0] = 1;

    for(i = 1; i <= len1; i++)
        for(j = 1; j <= len2; j++)
        	temp[i][j] = (str1[i - 1] == str2[j - 1])? (temp[i - 1][j - 1] + temp[i - 1][j]):
        	temp[i-1][j];
 
    return temp[len1][len2];
}

int main()
{
	char str1[] = "abade";
	char str2[] = "ae";
	printf("The number of times string occurs is = %d ", countString(str1, str2));
	return 0;
}