/* create circular linked list */
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
	struct node *temp, *tail;
	temp = (struct node *)malloc(sizeof(struct node));
	tail = *head;
	temp->data = data;
	if(!tail)
	{
		temp->next = temp;
		*head = temp;
	}

	/*traverse list to find last node of list*/
	else {
		while(tail->next != (*head))
			tail = tail->next;
		tail->next = temp;
		temp->next = *head;
		*head = temp;
	}
	
}


void printList(struct node *head)
{
	struct node *temp=head;
	if(head)
	{
		do 
		{
			printf("%d ", temp->data);
			temp = temp->next;
		}while(temp != head);
	}
}

int main() {
	struct node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	insertAtBeginning(&head, 60);
	printList(head);
	return 1;
}
