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
	 struct node *NthNode, *ref_ptr;
	 int count;
	 NthNode = ref_ptr = head;
	 for(count = 0; count < n; count++)
	 {
	 	if (ref_ptr != NULL)
	 		ref_ptr = ref_ptr->next;
	 	else return;
	 }
	 while (ref_ptr != NULL)
	 {
	 	NthNode = NthNode->next;
	 	ref_ptr = ref_ptr->next;
	 }
	 if (NthNode)
	 	printf("%d rd node from end is = %d", n, NthNode->data);
	 return;	 
}

int main() {
	struct node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	insertAtBeginning(&head, 60);
	getNthFromLast(head, 1);
	return 1;
}
