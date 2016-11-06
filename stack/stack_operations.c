#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *prev, *next;
};

struct stack
{
	struct node *head, *middle;
	int count;
};

struct stack *createStack()
{
	struct stack *s = (struct stack *)malloc(sizeof(struct stack));
	s->count = 0;
	return s;
}

void push(struct stack *s, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->prev = NULL;
	temp->next = s->head;
	s->count += 1;
	if(s->count == 1)
		s->middle = temp;
	else
	{
		s->head->prev = temp;
		if(s->count & 1)
			s->middle = s->middle->prev;
	}
	s->head = temp;
}

int pop(struct stack *s)
{
	if(!s->count)
	{
		printf("Stack is Empty\n" );
		return -1;
	}
	struct node *temp = s->head;
	int item = temp->data;
	s->head = temp->next;
	if(s->head)
		s->head->prev = NULL;
	s->count -= 1;
	if(!((s->count) & 1))
		s->middle = s->middle->next;
	free(temp);
	return item;
}

int getMiddleEle(struct stack *s)
{
	return !(s->count)? -1: s->middle->data; 
}

int main()
{
	struct stack *s = createStack();
	push(s, 10);
	push(s, 20);
	push(s, 30);
	push(s, 40);
	push(s, 50);
	push(s, 60);
	push(s, 70);
	printf("Middle element is = %d\n", getMiddleEle(s));
	printf("Item popped from stack is = %d\n", pop(s));
	printf("Item popped from stack is = %d\n", pop(s));
	printf("Middle element is = %d\n", getMiddleEle(s));
	return 0;
}