#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int data;
	struct node *next;

};

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
	insertAtPos(&head, 10);
	insertAtPos(&head, 20);
	insertAtPos(&head, 30);
	insertAtPos(&head, 40);
	insertAtPos(&head, 50);
	printList(head);
	return 1;

}
