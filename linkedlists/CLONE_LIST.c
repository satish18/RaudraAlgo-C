#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

struct node
{
	int data;
	struct node *next;
	struct node *random;
	
};

struct node *newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = temp->random = NULL;
	return temp;
}

void setRandomPointers(struct node *current)
{
	while(current) {
		current->next->random = current->random->next;
		current = current->next->next;
	}
}

void splitAlternateNodes(struct node *head, struct node **head1, struct node **head2)
{
	*head1 = head;
	*head2 = head->next;
	if(!head || !head->next)
		return;
	struct node *temp;	
	while(head) {
		temp = head->next;
		head->next = temp ? temp->next: temp;
		head = temp;
	}
}

struct node *getCloneList(struct node *head)
{
	struct node *temp, *mainList, *cloneList, *currPtr;
	currPtr = mainList = cloneList = head;
	while(currPtr) {
		temp = newNode(currPtr->data);
		temp->next = currPtr->next;
		currPtr->next = temp;
		currPtr = temp->next;
	}
	setRandomPointers(head);
	splitAlternateNodes(head, &mainList, &cloneList);
	return cloneList;
}

void printCloneList(struct node *head)
{
	for(; head; head = head->next)
		printf("%d\t", head->data);
	printf("\n");
}


int main() {
	struct node *head = newNode(10);
	head->next = newNode(20);
	head->next->next = newNode(30);
	head->next->next->next = newNode(40);
	head->next->next->next->next = newNode(50);
	head->random = head->next->next;
	head->next->next->random= head->next->next->next->next;
	head->next->next->next->next->random = head->next;
	head->next->next->next->random = head->next->next;
	head->next->random = head;
	printCloneList(head);
	printCloneList(getCloneList(head));
	return 1;
}