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
	struct node *fast_pointer, *slow_pointer;
	fast_pointer = slow_pointer = head;
	if (head != NULL)
	{
		while ( (fast_pointer != NULL) && (fast_pointer->next != NULL))
		{
			fast_pointer = fast_pointer->next->next;
			slow_pointer = slow_pointer->next;
		}
		printf("The middle element is = %d\n", slow_pointer->data);
	}
	else 
		printf("The list is empty");
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
