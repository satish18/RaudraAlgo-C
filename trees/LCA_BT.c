/* least common anscestor of two nodes in binary search tree */
#include <stdio.h>
#include <stdlib.h>

struct BTNode 
{
	int data;
	struct BTNode *left;
	struct BTNode *right;
};

struct BTNode *newNode(int data)
{
	struct BTNode *temp = (struct BTNode *)malloc(sizeof(struct BTNode));
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}


struct BTNode *RecursiveLCA(struct BTNode *root, int p, int q)
{
	if(!root) return root;
	if(root->data == p || root->data == q) return root;
	struct BTNode *left = RecursiveLCA(root->left, p, q);
	struct BTNode *right = RecursiveLCA(root->right, p, q);
	if(left && right)
		return root;
	return (left ? left: right);
}

int main()
{
	struct BTNode *root, *lca;
	root = newNode(25);
	root->left = newNode(10);
	root->right = newNode(30);
	root->left->left = newNode(5);
	root->left->right = newNode(15);
	root->left->right->left = newNode(12);
	lca = RecursiveLCA(root, 12, 30);
	printf("%d\n", lca ? lca->data: -1);
	return 0;
}