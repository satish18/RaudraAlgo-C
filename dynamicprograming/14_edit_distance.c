#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int min(int a, int b)
{
    return a < b? a: b;
}

int minimum(int a, int b, int c)
{
    return min(min(a, b), c);
}

int minEditDistance(char *str1, char *str2, int len1, int len2)
{
    int ED[len1+1][len2+1];
    for(int i = 0; i <= len1; i++)
    {
        for(int j = 0; j <= len2; j++)
        {
            if(i == 0)
                ED[i][j] = j;
            else if(j == 0)
                ED[i][j] = i;
            else if(str1[i-1] == str2[j-1])
                ED[i][j] = ED[i-1][j-1];
            else
                ED[i][j] = 1 + minimum(ED[i][j-1], ED[i-1][j], ED[i-1][j-1]);
        }
    }
    return ED[len1][len2];
}
             
int main()
{
    char str1[] = "abcdef";
    char str2[] = "azced";
    printf("Mininum edit distance = %d", 
        minEditDistance(str1, str2, strlen(str1), strlen(str2))); 
    return 0;
}