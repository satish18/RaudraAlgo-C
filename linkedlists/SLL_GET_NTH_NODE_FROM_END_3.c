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

void getNthFromLast(struct node *head, int n)
{
	 struct node *NthNode, *refPtr;
	 int count;
	 NthNode = refPtr = head;
	 for(count = 0; count <= n; count++)
	 {
	 	if (refPtr)
	 		refPtr = refPtr->next;
	 	else return;
	 }
	 for(;refPtr; refPtr = refPtr->next, NthNode = NthNode->next);
	 if (NthNode)
	 	printf("%d rd node from end is = %d", n, NthNode->data);
}

int main() {
	struct node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	insertAtBeginning(&head, 60);
	getNthFromLast(head, 3);
	return 1;
}
