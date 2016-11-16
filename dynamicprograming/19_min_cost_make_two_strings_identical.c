#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return a > b? a: b;
}

int LongestCommonSubSequence(char *str1, char *str2, int len1, int len2)
{
	int temp[len1+1][len2+1], i, j;
	for(i = 0; i <= len1; i++)
	{
		for(j = 0; j <= len2; j++)
		{
			if(i == 0 || j == 0)
                temp[i][j] = 0;
 
            else if(str1[i-1] == str2[j-1])
                temp[i][j] = temp[i-1][j-1] + 1; 
            else
                temp[i][j] = max(temp[i-1][j], temp[i][j-1]);
		}
	}
	return temp[len1][len2];
}

int getMinimumCost(char *str1, char *str2, int cost1, int cost2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int lenOfLCS = LongestCommonSubSequence(str1, str2, len1, len2);
	return cost1 * (len1 - lenOfLCS) + cost2 * (len2 - lenOfLCS);
}

int main()
{
	char str1[] = "RAVI";
	char str2[] = "AIBC";
	printf("Minimum cost to make two string identical is = %d", 
		getMinimumCost(str1, str2, 1, 2));
	return 0;
}