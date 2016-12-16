#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *next;
};

struct node *newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

struct node *mergeTwoSortedLists(struct node *head1, struct node *head2)
{
	struct node *mergeList, *temp;
	if(head1->data <= head2->data) {
		mergeList = head1;
		head1 = head1->next;
	}
	else {
		mergeList = head2;
		head2 = head2->next;
	}
	temp = mergeList;
	while ( head1 && head2 ) {
		if(head1->data <= head2->data) {
			temp->next = head1;
			temp = temp->next;
			head1 = head1->next;
		}
		else {
			temp->next = head2;
			temp = temp->next;
			head2 = head2->next;
		}		
	}
	temp->next = (!head1)? head2: head1;
	return mergeList; 
}

void printList(struct node *head)
{
	for(; head; head = head->next)
		printf("%d\t", head->data);
}

int main()
{
	struct node *head1 = newNode(10);
	head1->next = newNode(30);
	head1->next->next = newNode(50);
	head1->next->next->next = newNode(70);
	struct node *head2 = newNode(20);
	head2->next = newNode(40);
	head2->next->next = newNode(60);
	printList(mergeTwoSortedLists(head1, head2));
	return 0;
}