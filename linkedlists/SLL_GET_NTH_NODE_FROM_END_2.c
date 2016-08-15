/* Recursive implementation of get nth node from end   */

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
	 static int i = 0;
	 if (head == NULL)
	 	return;
	 getNthFromLast(head->next, n);
	 if (++i == n)
	 	printf("%d rd node from end is = %d\n", n, head->data);
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


/* TIME COMPLEXITY is O(n)
   SPACE COMPLEXITY is O(n)
*/