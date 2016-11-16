#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int max(int a, int b)
{
	return a > b? a: b;
}

int LongestPalindromicSubsequence(char *str)
{
	int len = strlen(str);
	int i, j, ls, LPS[len][len];

	for(i = 0; i < len; i++)
		LPS[i][i] = 1;
	for(ls = 2; ls <= len; ls++)
	{
		for(i = 0; i < len-ls+1; i++)
		{
			j = i+ls-1;
			if(str[i] == str[j] && ls == 2)
               LPS[i][j] = 2;
            else if (str[i] == str[j])
               LPS[i][j] = LPS[i+1][j-1] + 2;
            else
               LPS[i][j] = max(LPS[i][j-1], LPS[i+1][j]);
		}
	}
	return LPS[0][len-1];
}

int main()
{
	char str[] = "raudra";
	printf("The length of the Longest Palindromic Subsequence is = %d\n", 
		LongestPalindromicSubsequence(str));
	return 0;
}