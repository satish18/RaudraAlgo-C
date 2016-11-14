#include <stdio.h>
#include <stdlib.h>
#include <string.h>
  
int max(int a, int b)
{
	return a > b? a: b;
}
  
int LongestCommonSubSequence(char *str1, char *str2, int len1, int len2)
{
	int lcs[len1+1][len2+1], i, j;
    for (i = 0; i <= len1; i++)
    {
    	for (j = 0; j <= len2; j++)
    	{
    		if (i == 0 || j == 0)
    			lcs[i][j] = 0;
    		else if(str1[i-1] == str2[j-1])
    			lcs[i][j] = lcs[i-1][j-1] + 1;
    		else
    			lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
    	}
    }
    return lcs[len1][len2];
}  

int main()
{
  char str1[] = "AAACCGTGAGTTATTCGTTCTAGAA";
  char str2[] = "CACCCCTAAGGTACCTTTGGTTC";
  int len1 = strlen(str1);
  int len2 = strlen(str2);
  
  printf("Length of Longest Common Sub sequence is = %d\n", 
  	LongestCommonSubSequence(str1, str2, len1, len2));
 
  return 0;
}