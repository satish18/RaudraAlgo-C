/* Algorithm
   ---------

   1. Find the length of a linked list
   2. print (len-n+1)th node from the beginning of a linked list

   */

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
	 struct node *p = head;
	 int len = 0, i;
	 //find length of linked list
	 while (p != NULL)
	 {
	 	len++;
	 	p = p->next;
	 }

	 if (len < n)
	 	return;

	 p = head;
	 //get len-n+1 th node from beginning of list
	 for(i = 1; i < (len-n+1); i++)
	 	p = p->next;
	 printf("%d rd node from last is = %d\n", n, p->data);	 
	 return;
}

int main() {
	struct node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	getNthFromLast(head, 3);
	return 1;
}


