#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;	
};

void Enqueue(struct node **front, struct node **rear, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	if(!(*front) && !(*rear))
		*front = *rear = temp;
	else{
		(*rear)->next = temp;
		(*rear) = temp;
	}
}

void printQueue(struct node *front)
{
	struct node *temp;
	for(temp=front; temp; temp=temp->next)
		printf("%d ", temp->data);
}

int main()
{
	struct node *front, *rear;
	front = rear = NULL;
	Enqueue(&front, &rear, 10);
	Enqueue(&front, &rear, 20);
	Enqueue(&front, &rear, 30);
	Enqueue(&front, &rear, 40);
	printQueue(front);
	return 0;
}