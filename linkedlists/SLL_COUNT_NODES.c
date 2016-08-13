/* Given a single linked list, find count of nodes present in a list.
   For example, if given list is 10 -> 20 -> 30 -> 40 -> 50,
   then output should return 5
*/

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

// Traversing a list and count nodes
void countNodes(struct node *head)
{
	struct node *p = head;
  int count = 0;
	while(p != NULL){
		printf("%d -> ", p->data);
		p = p->next;
    count += 1;
	}
  printf("\nTotal nodes in a list = %d\n", count);
}

int main() {
	struct node *head = NULL;
	insertAtBeginning(&head, 10);
	insertAtBeginning(&head, 20);
	insertAtBeginning(&head, 30);
	insertAtBeginning(&head, 40);
	insertAtBeginning(&head, 50);
	countNodes(head);
	return 1;
}


/* Time Complexity is O(n) -> count nodes in a list
  because we need to traverse entire list */
