#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;	
};

void Push(struct node **top, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*top);
	*top = temp;
}

void pop(struct node **top)
{
	struct node *temp = (*top);
	if(!(*top))
	{
		printf("Stack is empty");
		return;
	}
	(*top) = (*top)->next;
	free(temp);
}

void printStack(struct node *top)
{
	struct node *temp;
	if(!top)
	{
		printf("Stack Empty\n");
		return;
	}
	for(temp=top; temp; temp=temp->next)
		printf("%d  ", temp->data);
}

int main()
{
	struct node *top = NULL;
	Push(&top, 10);
	Push(&top, 20);
	Push(&top, 30);
	Push(&top, 40);
	Push(&top, 50);
	printStack(top);
	pop(&top);
	printStack(top);	
	return 0;
}