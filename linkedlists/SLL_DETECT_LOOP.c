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

int detectLoop(struct node *head)
{
	struct node *fastPtr, *slowPtr;
	for(fastPtr=head, slowPtr=head; fastPtr&&slowPtr&&fastPtr->next;)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
		if (fastPtr == slowPtr) return 1;
	}	 	 
	return 0;
}

struct node *findStartNodeOfLoop(struct node *head)
{
	struct node *fastPtr, *slowPtr;
	for(fastPtr=head, slowPtr=head; fastPtr&&slowPtr&&fastPtr->next;)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
		if (fastPtr == slowPtr) break;
	}
	slowPtr = head;
	while(slowPtr != fastPtr)
	{
		slowPtr = slowPtr->next;
		fastPtr = fastPtr->next;
	}
	return slowPtr;
}

int main() {
	struct node *head = NULL, *loopStartNode;
	int flag;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	head->next->next->next->next = head->next->next;
	flag = detectLoop(head);
	printf(flag?"Loop Found": "Loop Not Found");
	if(flag)
		loopStartNode = findStartNodeOfLoop(head);
		printf("\nstarting node of loop is = %d", loopStartNode->data);
	return 1;
}
