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
  // traverse the list two times.
	struct node *p = head;
  // Traverse the list to find count.
  int count = 0, i;
	while(p != NULL){
		p = p->next;
    count += 1;
	}
  //Traverse list upto count/2
  p = head; // assign p pointer to head node
  for(i=0; i<count/2; i++)
    p = p->next;
  if (p != NULL)
    printf("Middle element in a given list is %d\n", p->data);
  else
    printf("Middle Element Not Found\n");
}

int main() {
	struct node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	findMiddleNode(head);
	return 1;
}
