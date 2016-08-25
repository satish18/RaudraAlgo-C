#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int isEmpty(int *top)
{
	return ((*top) == -1);
}

void pop(int a[], int *top, int *minEle)
{
	if(!isEmpty(top))
	{
		if(a[(*top)] < *minEle)
			*minEle = *minEle - a[(*top)];
		(*top)--;
	}
	else
		printf("Stack Is Empty");
}

void push(int a[], int num, int *top, int *minEle)
{
	if((*minEle) > num)
	{
		a[++(*top)] = ((*top) == -1)? num : num - *minEle;
		*minEle = num;
	}
	if(isEmpty(top) || (*minEle <= num))
		a[++(*top)] = num;	
}

void display(int a[], int *top)
{
	for(int i=(*top); i>=0; i++)
		printf("%d", a[i]);
}

int main()
{
	int a[10], *top, *minEle;
	*top = -1;
	*minEle = INT_MAX;
	push(a, -1, top, minEle);
	display(a, top);
	// push(a, 5, &top, &minEle);
	// push(a, 2);
	// push(a, 5);
	// push(a, 7);
	// push(a, 1);
	// push(a, 15);
	// // display(a);
	// printf("%d\n", getMinimum());
	// pop(a);
	// printf("%d\n", getMinimum());
	// pop(a);
	// printf("%d\n", getMinimum());
	// pop(a);
	// printf("%d\n", getMinimum());
	// pop(a);
	// printf("%d\n", getMinimum());
	// pop(a);
	// printf("%d\n", getMinimum());
	// pop(a);
	// printf("%d\n", getMinimum());
	// pop(a);
	// printf("%d\n", ;
	// pop(a);
	printf("%d\n", minEle);
	// pop(a);

}