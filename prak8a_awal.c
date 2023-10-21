#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} Tnode;
typedef Tnode *ptrnode;

ptrnode newNode(int data)
{
	ptrnode newnode = (ptrnode)malloc(sizeof(Tnode));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

void displayPre(ptrnode root)
{
	if (root == NULL)
		return;

	printf("%d ", root->data);
	displayPre(root->left);
	displayPre(root->right);
}

void displayIn(ptrnode root)
{
	if (root == NULL)
		return;

	displayIn(root->left);
	printf("%d ", root->data);
	displayIn(root->right);
}

void displayPost(ptrnode root)
{
	if (root == NULL)
		return;

	displayPost(root->left);
	displayPost(root->right);
	printf("%d ", root->data);
}

void main()
{
	ptrnode root = newNode(8);
	root->left = newNode(3);
	root->left->right = newNode(1);
	root->left->left = newNode(6);
	root->left->right->right = newNode(4);
	root->left->right->left = newNode(7);
	root->right = newNode(10);
	root->right->left = newNode(14);
	root->right->left->right = newNode(13);

	displayPre(root);
	printf("\n");
	displayIn(root);
	printf("\n");
	displayPost(root);
}