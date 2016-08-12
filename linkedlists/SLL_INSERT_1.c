#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int data;
	struct node *next;
	
};

/* Given a reference to the head of the list and insert a new
node at Ending of a list*/
void insertAtLast(struct node **head, int data)
{
	// allocate new node
	struct node *temp, *p;
	temp = (struct node*) malloc(sizeof(struct node));
	p = *head;
	temp->data = data;
	temp->next = NULL;
	
	if (p == NULL)
		*head = temp;

	else{

		while(p->next != NULL)
			p = p->next;
		p->next = temp;
	}	
}

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
	insertAtLast(&head, 10);
	insertAtLast(&head, 20);
	insertAtLast(&head, 30);
	insertAtLast(&head, 40);
	insertAtLast(&head, 50);
	printList(head);
	return 1;

}