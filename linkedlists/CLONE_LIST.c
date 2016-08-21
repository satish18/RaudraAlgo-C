#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int data;
	struct node *next;
	struct node *random;
	
};

/* Given a reference to the head of the list and insert a new
node at beginning of a list*/
void insertAtBeginning(struct node **head, int data)
{
	// allocate new node
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->random = NULL;
	temp->next = (*head);
	*head = temp;
}

struct node *getCloneList(struct node *head)
{
	struct node *temp, *result, *currPtr, *nextPtr;
	currPtr = head;
	while(currPtr)
	{
		temp = (struct node *)malloc(sizeof(struct node));
		temp->data = currPtr->data;
		temp->random = NULL;
		temp->next = currPtr->next;
		nextPtr = currPtr->next;
		currPtr->next = temp;
		currPtr = nextPtr;
	}
	result = head->next;
	currPtr = head;
	while(currPtr)
	{
		currPtr->next->random = currPtr->random->next;
		currPtr = currPtr->next->next;
	}
	//restore the original and clone of linked lists
	currPtr = head;
	temp = head->next;
	while(currPtr && temp)
	{
		currPtr->next = temp->next->next;
		currPtr = currPtr->next;
		if(temp->next)
		{
			temp->next = temp->next->next;
			temp = temp->next;
		}
	}
	return result;

}

void printCloneList(struct node *copyList)
{
	struct node *temp=copyList;
	while(temp)
	{
		printf("%d->%d\n", temp->data, temp->random->data);
		temp = temp->next;
	}
}



int main() {
	struct node *head = NULL, *copyList;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	head->random = head->next->next;
	head->next->next->random= head->next->next->next->next;
	head->next->next->next->next->random = head->next;
	head->next->next->next->random = head->next->next;
	head->next->random = head;
	printCloneList(head);
	copyList = getCloneList(head);
	printCloneList(copyList);
	return 1;

}