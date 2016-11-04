#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LEN 100

char *runLengthEncoding(char *sourceStr)
{
	int len = strlen(sourceStr), resultLen, index, j=0, k;
	char *finalStr = (char *)malloc(sizeof(char)*(len*2 + 1));
	char count[MAX_LEN];
	for(index = 0; index < len; index++)
	{
		finalStr[j++] = sourceStr[index];
		for(resultLen = 1; index + 1 < len && sourceStr[index] == sourceStr[index+1];
			resultLen++, index++);
		//copy resultLen in a character array count[]
		sprintf( count, "%d", resultLen);

		//copy the count[] to finalStr
		for(k = 0; count[k]; k++, j++)
			finalStr[j] = count[k];
	}
	finalStr[j] = '\0';
	return finalStr;
}

int main()
{
	char str[100];
	printf("Enter string");
	scanf("%s", str);	
	printf("%s\n", runLengthEncoding(str));
	return 0;
}