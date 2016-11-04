#include <stdio.h>
#include <stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};

struct node *newNode(int data)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

void VerticalSumDLL(struct node *root, struct node *head)
{
	head->data = head->data + root->data;
	if(root->left)
	{
		if(!head->left)
		{
			head->left = newNode(0);
			head->left->right = head;
		}
		VerticalSumDLL(root->left, head->left);
	}
	if(root->right)
	{
		if(!head->right)
		{
			head->right = newNode(0);
			head->right->left = head;
		}
		VerticalSumDLL(root->right, head->right);
	}
}


void VerticalSumBinaryTree(struct node *root)
{
	struct node *head = newNode(0);
	VerticalSumDLL(root, head);

	while(head->left)
		head = head->left;

	while(head)
	{
		printf("%d\t", head->data);
		head = head->right;
	}
}

int main()
{
	struct node *root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->left->right = newNode(50);
	root->right->left = newNode(60);
	root->right->right = newNode(70);
	VerticalSumBinaryTree(root);
	return 0;
}