#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NO_OF_CHARS 256

int max(int a, int b)
{
    return a > b? a: b;
}

void badCharHeuristic(char *str, int size, int *badChar)
{
    int index;
    for(index = 0; index < NO_OF_CHARS; index++)
        badChar[index] = -1;
 
    for (index = 0; index < size; index++)
        badChar[(int)str[index]] = index;
}

void BoyerMooreSearch(char *txt, char *pat)
{
    int pLen = strlen(pat);
    int tLen = strlen(txt);
    int badChar[NO_OF_CHARS], index;
    badCharHeuristic(pat, pLen, badChar);
    for(int shift = 0; shift <= (tLen - pLen); )
    {
        index = pLen - 1;
        while(index >= 0 && pat[index] == txt[shift + index])
            index--;
        if(index < 0)
        {
            printf("Pattern occurs at shift = %d", shift);
            shift += (shift + pLen < tLen)? pLen - badChar[txt[shift + pLen]] : 1; 
        }
 
        else
            shift += max(1, index - badChar[txt[shift + index]]);
    }
}
 
int main()
{
    char txt[100], pat[100];
    printf("Enter text string\n");
    scanf("%s", txt);
    printf("Enter pattern string\n");
    scanf("%s", pat);
    BoyerMooreSearch(txt, pat);
    return 0;
}