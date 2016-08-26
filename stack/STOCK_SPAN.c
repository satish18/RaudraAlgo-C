#include <stdio.h>
#include <stdlib.h>

int top = -1;

int isStackEmpty()
{
	return (top == -1);
}

void push(int stack[], int data, int size)
{
	if(top == size)
		printf("stack Full");
	else
		stack[++top] = data;
}

void pop(int stack[])
{
	if(isStackEmpty())
	{
		printf("stack Empty\n");
		return;
	}
	top--;
}

void evaluateSpan(int price[], int n, int stock[])
{
	int stack[n];
	push(stack, 0, n);
	stock[0] = 0;
	for(int i=1; i<n; i++)
	{
		while(!isStackEmpty() && price[stack[top]] <= price[i])
			pop(stack);

		stock[i] = (isStackEmpty() ? (i) : (i- stack[top]-1));
		push(stack, i, n);
	}
}

void printSpan(int stock[], int n)
{
	for(int i=0; i<n; i++)
		printf("%d  ", stock[i]);
}

int main()
{
	int price[] = {10, 4, 5, 90, 120, 80};
	int stock[6];
	evaluateSpan(price, 6, stock);
	printSpan(stock, 6);
	return 0;
}
