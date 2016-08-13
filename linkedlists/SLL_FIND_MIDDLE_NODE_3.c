/* Traverse the linked list using two pointers. Move one pointer by one step and 
another pointer by two steps. When faster pointer moves to end of the list then
slow pointer will reach middle of the list*/

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

void findMiddleNode(struct node *head)
{
	/*Single pointer mid is used to find out middle node in a list
	  'mid' pointer will move only when nodes count will 
		become odd while traversing list */
	 struct node *mid, *temp;
	 int count = 0;
	 mid = temp = head;	 
	 while (temp != NULL) 
	 {
	 	if (count & 1)
	 		mid = mid->next;
	 	count += 1;
	 	temp = temp->next;
	 }
	 if (mid != NULL)
	 	printf("The middle node is = %d", mid->data);	
}

int main() {
	struct node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	insertAtBeginning(&head, 60);
	insertAtBeginning(&head, 70);
	findMiddleNode(head);
	return 1;
}
