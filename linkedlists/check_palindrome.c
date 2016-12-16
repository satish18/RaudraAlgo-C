#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

int compareList(struct node *list1, struct node *list2)
{
	for(; list2 && list1->data == list2->data; 
		list1 = list1->next, list2 = list2->next);
	return !list2 ? 1: 0;
}

struct node *findMiddleNode(struct node *head)
{
	struct node *fastPtr, *slowPtr;
	fastPtr = slowPtr = head;
	for(; fastPtr && fastPtr->next; 
		fastPtr = fastPtr->next->next, slowPtr = slowPtr->next);
	return slowPtr;
}

void reverseList(struct node **head)
{
	 struct node *currPtr, *prevPtr, *nextPtr;
	 currPtr = *head;
	 prevPtr = NULL;
	 while(currPtr != NULL)
	 {
	 	nextPtr = currPtr->next;
	 	currPtr->next = prevPtr;
	 	prevPtr = currPtr;
	 	currPtr = nextPtr;
	 }
	 *head = prevPtr;	 	 
}

int isPalindrome(struct node *head)
{
	int result;
	struct node *middleNode = findMiddleNode(head);
	struct node *secondHalf;
	if(!middleNode || !middleNode->next)
		return 1;
	secondHalf = middleNode->next;
	middleNode->next = NULL;
	reverseList(&secondHalf);
	result = compareList(head, secondHalf);
	reverseList(&secondHalf);
	middleNode->next = secondHalf;
	return result;
}

struct node *newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;
	return temp;
}

int main()
{
	struct node *head = newNode(10);
	head->next = newNode(20);
	head->next->next = newNode(30);
	head->next->next = newNode(20);
	head->next->next->next = newNode(10);
	if(isPalindrome(head))
		printf("Given list is palindrome\n");
	else
		printf("List is not a palindrome\n");
	return 0;
}