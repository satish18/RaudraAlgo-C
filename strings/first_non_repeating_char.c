#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define NO_OF_CHARS 256

struct countChar
{
	int count, index;
};

struct countChar *getCharCountArray(char *str)
{
	struct countChar *count = (struct countChar*)calloc(sizeof(struct countChar), NO_OF_CHARS);
	int index;
	for(index = 0; str[index]; index++)
	{
		(count[str[index]].count)++;
		if (count[str[index]].count == 1)
			count[str[index]].index = index;
	}
	return count;
}

int getFirstNonRepeatingChar(char *str)
{
	struct countChar *count = getCharCountArray(str);
	int result = INT_MAX, index;
	for(index = 0; index < NO_OF_CHARS; index++)
	{
		if(count[index].count == 1 && result > count[index].index)
			result = count[index].index;
	}
	free(count);
	return result;	
}

int main()
{
	char str[] = "ravindra ravula";
	int index = getFirstNonRepeatingChar(str);
	if(index == INT_MAX)
		printf("Either all characters are repeating or string is empty\n");
	else
		printf("First non repeating char is = %c\n", str[index]);

	return 0;
}