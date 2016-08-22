#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;	
};

void insertAtBegin(struct node **head, int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*head);
	(*head) = temp;
}

void segregateEvenOdd(struct node **head)
{
	struct node *currPtr, *prevPtr, *endPtr, *newEndPtr;
	currPtr = endPtr = (*head);
	for(;endPtr->next; endPtr=endPtr->next);
	newEndPtr = endPtr;
	while(currPtr->data %2 != 0 && currPtr != endPtr)
	{
		newEndPtr->next = currPtr;
		currPtr = currPtr->next;
		newEndPtr->next->next = NULL;
		newEndPtr = newEndPtr->next;
	}
	if(currPtr->data %2 == 0)
	{
		(*head) = currPtr;
		while(currPtr != endPtr)
		{
			if((currPtr->data)%2 == 0)
			{
				prevPtr = currPtr;
				currPtr = currPtr->next;
			}
			else
			{
				prevPtr->next = currPtr->next;
				currPtr->next = NULL;
				newEndPtr->next = currPtr;
				newEndPtr = currPtr;
				currPtr = prevPtr->next;
			}
		}

	}
	else prevPtr = currPtr;
	if (newEndPtr != endPtr && (endPtr->data)%2 != 0)
	{
		prevPtr->next = endPtr->next;
		endPtr->next = NULL;
		newEndPtr->next = endPtr;
	}
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
	struct node *head = NULL;
	insertAtBegin(&head, 17);
	insertAtBegin(&head, 15);
	insertAtBegin(&head, 8);
	insertAtBegin(&head, 12);
	insertAtBegin(&head, 10);
	insertAtBegin(&head, 5);
	insertAtBegin(&head, 4);
	insertAtBegin(&head, 1);
	insertAtBegin(&head, 7);
	printList(head);
	segregateEvenOdd(&head);
	printList(head);
	return 0;
}