#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;	
};

void insertAtBegin(struct node **head, int data)
{
	struct node *temp=(struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*head);
	(*head) = temp;
}

struct node *deleteMiddleNode(struct node **head)
{
	struct node *prevPtr, *fastPtr, *slowPtr;
	if((*head) == NULL)
		return NULL;
	if((*head)->next == NULL)
	{
		free(head);
		return NULL;
	}
	for(slowPtr=(*head), fastPtr=(*head); slowPtr && fastPtr && fastPtr->next; )
	{
		fastPtr = fastPtr->next->next;
		prevPtr = slowPtr;
		slowPtr = slowPtr->next;
	}
	prevPtr->next = slowPtr->next;
	free(slowPtr);
	return (*head);
}

void printList(struct node *head)
{
	struct node *temp=head;
	while(temp)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	struct node *head=NULL;
	insertAtBegin(&head, 10);
	insertAtBegin(&head, 20);
	insertAtBegin(&head, 30);
	insertAtBegin(&head, 40);
	insertAtBegin(&head, 50);
	printList(head);
	head = deleteMiddleNode(&head);
	printList(head);
	return 0;
}