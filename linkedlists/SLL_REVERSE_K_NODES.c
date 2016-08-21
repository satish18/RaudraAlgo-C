/*Reverse every k nodes in a given linked list */

#include <stdio.h>
#include <stdlib.h>

//linked list node (self referential structure)
struct node
{
	int data;
	struct node *next;	
};

void insertAtBeginning(struct node **head, int data)
{
	// allocate new node
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*head);
	*head = temp;
}

struct node *reverseKNodes(struct node *head, int k)
{
	struct node *currentPtr=head, *prevPtr=NULL, *nextPtr;
	int count;
	for(count=0; currentPtr && count<k; count++)
	{
		nextPtr = currentPtr->next;
		currentPtr->next = prevPtr;
		prevPtr = currentPtr;
		currentPtr = nextPtr;
	}
	if(head && nextPtr)
		head->next = reverseKNodes(nextPtr, k);
	return prevPtr;
}

void printList(struct node *head)
{
	struct node *temp=head;
	if (!head)
	{ 
		printf("Empty List\n");
		return;
	}
	while(temp)
	{
		printf("%d\t", temp->data);
		temp = temp->next;
	}
}


int main() {
	struct node *head = NULL;
	int k;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	insertAtBeginning(&head, 60);
	printf("Enter number of nodes to reverse ");
	scanf("%d", &k);
	head = reverseKNodes(head, k);
	printList(head);
	return 1;
}
