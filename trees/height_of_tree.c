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
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

int getHeightOfTree(struct node *root)
{
	if(root)
	{
		int lHeight = getHeightOfTree(root->left);
		int rHeight = getHeightOfTree(root->right);
		return (lHeight > rHeight) ? lHeight + 1: rHeight + 1;
	}
	return 0;
}

int main()
{
	struct node *root=NULL;
	root = newNode(10);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(40);
	root->right->left = newNode(50);
	printf("Height of the tree is = %d", getHeightOfTree(root));
	return 0;
}