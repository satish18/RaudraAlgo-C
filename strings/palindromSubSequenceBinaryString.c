#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkPalindrome(char *str)
{
	int left = 0, right = strlen(str) - 1;

	while(left < right)
		if(str[left++] != str[right--])
			return 0;
	return 1;
}

int minimumRemovals(char *str)
{
	if(!str[0])
		return 0;
	return checkPalindrome(str)? 1: 2;	
}

int main()
{
	char str[100];
	printf("Enter Binary string");
	scanf("%s", str);
	printf("Minimum removal is = %d", minimumRemovals(str));
	return 0;
}