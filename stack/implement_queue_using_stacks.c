#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct queue
{
	struct node *stack; 
};

struct queue *createQueue()
{
	struct queue *temp = (struct queue *)malloc(sizeof(struct queue));
	return temp;
}

struct node *createStack(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

void push(struct node **top, int data)
{
	struct node *temp = createStack(data);
	temp->next = (*top);
	(*top) = temp;
}

void enQueue(struct queue *q, int data)
{
	push(&q->stack, data);
}

int isQueueEmpty(struct queue *q)
{
	return q->stack ? 1: 0;
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

int deQueue(struct queue *q)
{
	int x, result;
	if(!q->stack->next)
		return pop(&q->stack);
	else
	{
		x = pop(&q->stack);
		result = deQueue(q);
		push(&q->stack, x);
		return result;
	}
}

void printQueue(struct queue *q)
{
	while(isQueueEmpty(q))
		printf("%d\n", deQueue(q));
}

int main()
{
	struct queue *q = createQueue();
	q->stack = NULL;

	enQueue(q, 10);
	enQueue(q, 20);
	enQueue(q, 30);

	printQueue(q);

	return 0;
}

