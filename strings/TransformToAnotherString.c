/*Convert one string to another using minimum number of operations*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TOTAL_CHARS 256

int minimumOperations(char *str1, char *str2)
{
	int len1 = strlen(str1);
	int len2 = strlen(str2);
	int index, index2, result = 0;

	if( len1 != len2)
		return -1;
	int count[TOTAL_CHARS] = {0};
	for(index = 0; index < len1; index++)
	{
		count[str2[index]]++;
		count[str1[index]]--;
	}
	for(index = 0; index < TOTAL_CHARS; index++)
		if( count[index] )
			return -1;
	for(index = len1-1, index2 = len1 - 1; index >= 0; )
	{
		//if there is a mismatch, incrementing result
		for(; index >= 0 && str1[index] != str2[index2]; index--, result++ );
		if(index-- >= 0)
			index2--;
	}
	return result;
}

int main()
{
	char str1[] = "FBDCE";
	char str2[] = "FBCDE";
	printf("Minimum number of operations required is = %d", 
		minimumOperations(str1, str2));
	return 0;
}