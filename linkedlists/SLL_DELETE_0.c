#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int data;
	struct node *next;
	
};

/* Given a reference to the head of the list and insert a new
node at beginning of a list*/
void insertAtBeginning(struct node **head, int data)
{
	// allocate new node
	struct node *temp = (struct node*) malloc(sizeof(struct node));
	temp->data = data;
	temp->next = (*head);
	*head = temp;
}

int deleteAtBeginning(struct node **head)
{
	struct node *p = *head;
	int data;
	if (p != NULL)
	{
		data = p->data;
		*head = p->next;
		p->next = NULL;
		free(p);
	}
	return data; 
}

// Traversing a list
void printList(struct node *head)
{
	struct node *p = head;
	while(p != NULL){
		printf("%d ->", p->data);
		p = p->next;
	}
}

int main() {
	struct node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	printf("Before Deletion The list is\n");
	printList(head);
	printf("\nThe deleted node is = %d\n", deleteAtBeginning(&head));
	printf("After deletion the list is\n");	
	printList(head);
	return 1;

}