#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_LENGTH 30

// Definisi struct untuk node binary tree
typedef struct Node
{
	char name[NAME_LENGTH];
	struct Node *left;
	struct Node *right;
} Node;

// Fungsi untuk membuat node baru
Node *createNode(char name[])
{
	Node *newNode = (Node *)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

// Fungsi untuk menambahkan node ke dalam binary tree
Node *insertNode(Node *root, char name[])
{
	if (root == NULL)
	{
		return createNode(name);
	}

	if (strcmp(name, root->name) < 0)
	{
		root->left = insertNode(root->left, name);
	}
	else if (strcmp(name, root->name) > 0)
	{
		root->right = insertNode(root->right, name);
	}

	return root;
}

// Fungsi untuk mencari node berdasarkan substring pada binary tree
void printNodesWithSubstring(Node *root, char substring[])
{
	if (root == NULL)
	{
		return;
	}

	if (strstr(root->name, substring) != NULL)
	{
		printf("Name found: %s\n", root->name);
	}

	printNodesWithSubstring(root->left, substring);
	printNodesWithSubstring(root->right, substring);
}

// Fungsi untuk menampilkan isi binary tree dalam urutan preorder
void displayPreorder(Node *root)
{
	if (root != NULL)
	{
		displayPreorder(root->left);
		printf("%s\n", root->name);
		displayPreorder(root->right);
	}
}

int main()
{
	Node *root = NULL;

	root = insertNode(root, "John");
	insertNode(root, "Faridha");
	insertNode(root, "Jane");
	insertNode(root, "M Rayhan Faridh");
	insertNode(root, "Rayhan Faridh");

	printf("Names with substring 'Rayhan':\n");
	printNodesWithSubstring(root, "Faridh");

	printf("\nPreorder traversal:\n");
	displayPreorder(root);

	return 0;
}