#include <stdio.h>
#include <stdlib.h>
#define MAX 8

int stack[MAX+1], top=-1;

int isStackEmpty()
{
	return (top == -1);
}

void push(int data, int size)
{
	if(!(top == size))
		stack[++top] = data;		
}

int pop()
{
	if(!isStackEmpty())
		return stack[top--];
}

int getMaxRectangleArea(int areas[], int n)
{
	int prev_top, maximum_area=0, area_top;
	for(int i=0; i<n; )
	{

		if(isStackEmpty() || areas[stack[top]] <= areas[i])
			push(i++, n);
		else
		{
			prev_top = pop()
			area_top = areas[prev_top]*(isStackEmpty() ? i : (i-areas[top]-1));
			if(maximum_area < area_top)
				maximum_area = area_top;
		}
	}
	return maximum_area;
}

int main()
{
	int areas[] = {2, 1, 2, 3, 1, 4, 5, 4};
	printf("Maximum rectangle area is = %d", getMaxRectangleArea(areas, 8));
	return 1;
}