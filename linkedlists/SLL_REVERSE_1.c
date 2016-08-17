/* Reverse a linked list by recursion
   ----------------------------------
   Algorithm:
   ==========
   1. Divide the list into two parts: first node and rest of the linked list
   2. apply recursion on rest of the linked list
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

void reverseList(struct node **head)
{
	 struct node *current_ptr, *prev_ptr, *next_ptr;
	 current_ptr = *head;
	 prev_ptr = NULL;
	 while ( current_ptr != NULL )
	 {
	 	next_ptr = current_ptr->next;
	 	current_ptr->next = prev_ptr;
	 	prev_ptr = current_ptr;
	 	current_ptr = next_ptr;
	 }
	 *head = prev_ptr;	 	 
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
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	insertAtBeginning(&head, 60);
	printf("Before Reverse the list is\n");
	printList(head);
	printf("\nAfter Reverse the list is\n");
	reverseList(&head);
	printList(head);
	return 1;
}
