#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

int isStackEmpty(struct node *top)
{
	return !top ? 1: 0;
}

void push(struct node **top, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	if(!temp)
	{
		printf("Stack Overflow\n");
		exit(0);
	}
	temp->data = data;
	temp->next = (*top);
	(*top) = temp;
}

int pop(struct node **top)
{
	int result;
	struct node *temp = (*top);
	result = temp->data;
	(*top) = temp->next;
	free(temp);
	return result;
}

void insertAtBottom(struct node **top, int data)
{
	if(isStackEmpty(*top))
		push(top, data);
	else
	{
		int item = pop(top);
		insertAtBottom(top, data);
		push(top, item);
	}

}

void reverseStack(struct node **top)
{
	if(!isStackEmpty(*top))
	{
		int data = pop(top);
		reverseStack(top);
		insertAtBottom(top, data);
	}
}

void printStack(struct node *top)
{
	for(; top; top = top->next)
		printf("%d\t", top->data);
}

int main()
{
	struct node *stack = NULL;
	push(&stack, 10);
	push(&stack, 20);
	push(&stack, 30);
	push(&stack, 40);
	reverseStack(&stack);
	printStack(stack);
	return 0;
}