#include <stdio.h>
#include <stdlib.h>

struct stack
{
	int data;
	struct stack *next;
};

int isStackEmpty(struct stack *top)
{
	return top ? 1: 0;
}

void push(struct stack **top, int data)
{
	struct stack *temp = (struct stack *)malloc(sizeof(struct stack));
	temp->data = data;
	temp->next = (*top);
	(*top) = temp;
}

int pop(struct stack **top)
{
	struct stack *temp;
	int item = (*top)->data;
	temp = *top;
	*top = (*top)->next;
	free(temp);
	return item;
}

int getTop(struct stack *top)
{
	return top->data;
}

void sortedInsert(struct stack **top, int data)
{
	if(isStackEmpty(*top) || data > getTop(*top))
	{
		push(top, data);
		return;
	}
	int item = pop(top);
	sortedInsert(top, data);
	push(top, item);
}

void RecursiveSortStack(struct stack **top)
{
	if(!isStackEmpty(*top))
	{
		int item = pop(top);
		RecursiveSortStack(top);
		sortedInsert(top, item);
	}
}

void printStack(struct stack *top)
{
	for(; top; top = top->next)
		printf("%d\t", top->data);
}

int main()
{
	struct stack *top = NULL;
	push(&top, 10);
	push(&top, -5);
	push(&top, 8);
	push(&top, -3);
	RecursiveSortStack(&top);
	printStack(top);
	return 0;
}