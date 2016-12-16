#include <stdio.h>
#include <stdlib.h>

struct  node
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

// void splitAlternateNodes(struct node *head, struct node **head1, struct node **head2)
// {
// 	if(!head || !head->next)
// 		return;
// 	struct node *temp1, *temp2;
// 	*head1 = head;
// 	*head2 = head->next;
// 	for(temp1 = *head1, temp2 = *head2; temp1 && temp2; 
// 		temp1 = temp1->next, temp2 = temp2->next)
// 	{
// 		temp1->next = temp2->next;
// 		temp2->next = temp1->next ? temp1->next->next: NULL;
// 	}
// }
void splitAlternateNodes(struct node *head, struct node **head1, struct node **head2)
{
	*head1 = head;
	*head2 = head->next;
	if(!head || !head->next)
		return;
	struct node *temp;	
	while(head)
	{
		temp = head->next;
		head->next = temp ? temp->next: temp;
		head = temp;
	}
}
void printList(struct node *head)
{
	for(; head; head = head->next)
		printf("%d\t", head->data);
	printf("\n");
}

int main()
{
	struct node *head = newNode(10);
	// head->next = newNode(20);
	// head->next->next = newNode(30);
	// head->next->next->next = newNode(40);
	// head->next->next->next->next = newNode(50);
	// // head->next->next->next->next->next = newNode(60);
	struct node *head1, *head2;
	head1 = head2 = NULL;
	splitAlternateNodes(head, &head1, &head2);
	printList(head1);
	printList(head2);
	return 0;
}


 