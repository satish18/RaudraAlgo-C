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

int countNodes(struct node *head)
{
	int count;
	for(count = 0; head; head = head->next, count++);
	return count;
}

int _getIntersectionNode(int diff, struct node *head1, struct node *head2)
{
	for(int count = 0; count < diff; count++, head1 = head1->next)
		if(!head1)
			return -1;
	for(; head1 && head2; head1 = head1->next, head2 = head2->next)
		if(head1 == head2)
			return head1->data;
	return -1;
}

int getIntersectionNode(struct node *head1, struct node *head2)
{
	int l1 = countNodes(head1);
	int l2 = countNodes(head2);
	int diff = abs(l1 - l2);
	return (l1 > l2)? _getIntersectionNode(diff, head1, head2): 
	_getIntersectionNode(diff, head2, head1);
}

int main()
{
	struct node *head1 = newNode(10);
	head1->next = newNode(20);
	head1->next->next = newNode(30);
	head1->next->next->next = newNode(40);
	struct node *head2 = newNode(50);
	head2->next = head1->next->next;
	printf("%d", getIntersectionNode(head1, head2));
	return 0;

}