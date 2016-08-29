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

void getMirrorTree(struct node *root)
{	
	if(root)
	{
		getMirrorTree(root->left);
		getMirrorTree(root->right);
		struct node *temp;
		temp = root->left;
		root->left = root->right;
		root->right = temp;
	}
}

void inorder(struct node *root)
{
	if(root)
	{		
		inorder(root->left);
		printf("%d\t", root->data);
		inorder(root->right);
	}
}

int main()
{
	struct node *root=NULL;
	root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->right->left = newNode(50);
	getMirrorTree(root);
	inorder(root);
	return 0;
}