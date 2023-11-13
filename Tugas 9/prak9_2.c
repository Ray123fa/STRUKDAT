// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char nama[30];
	int height;
	struct node *left;
	struct node *right;
};

struct node *newNode(char nama[])
{
	struct node *node = (struct node *)malloc(sizeof(struct node));
	strcpy(node->nama, nama);
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}

int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}

int getHeight(struct node *N)
{
	if (N == NULL)
		return 0;
	return N->height;
}

// Hitung Balance factor untuk node N
int getBalanceFactor(struct node *N)
{
	if (N == NULL)
		return 0;
	return getHeight(N->left) - getHeight(N->right);
}

struct node *rightRotate(struct node *T)
{
	struct node *new_root = T->left;
	struct node *orphan = new_root->right;

	// Lakukan rotasi
	new_root->right = T;
	T->left = orphan;

	// Update height

	T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
	new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

	// Return root baru
	return new_root;
}

struct node *leftRotate(struct node *T)
{
	struct node *new_root = T->right;
	struct node *orphan = new_root->left;

	// Lakukan rotasi
	new_root->left = T;
	T->right = orphan;

	// Update height
	T->height = max(getHeight(T->left), getHeight(T->right)) + 1;
	new_root->height = max(getHeight(new_root->left), getHeight(new_root->right)) + 1;

	// Return root baru
	return new_root;
}

struct node *insert(struct node *root, char new_data[])
{
	// 1. Lakukan BST insert biasa
	if (root == NULL)
		return (newNode(new_data));
	// asumsi tidak boleh ada nilai yang sama dalam BST
	if (strcmp(new_data, root->nama) == -1)
		root->left = insert(root->left, new_data);
	else if (strcmp(new_data, root->nama) == 1)
		root->right = insert(root->right, new_data);
	// 2. Update height dari node baru sampai root
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
	// 3. Hitung balance factor untuk menentukan apakah node unbalanced
	int balance = getBalanceFactor(root);

	// Jika tidak balanced, return hasil rotation
	// Kasus 1: Left Left
	if (balance > 1 && strcmp(new_data, root->left->nama) == -1)
	{
		return rightRotate(root);
	}
	// Kasus 2: Right Right
	if (balance < -1 && strcmp(new_data, root->right->nama) == 1)
	{
		return leftRotate(root);
	}

	// Kasus 3: Right Left
	if (balance < -1 && strcmp(new_data, root->right->nama) == -1)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	// Kasus 4: Left Right
	if (balance > 1 && strcmp(new_data, root->left->nama) == 1)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}

	// return node jika balanced
	return root;
}

void displayPreorder(struct node *node)
{
	if (node == NULL)
		return;

	printf("%s ", node->nama);		// root
	displayPreorder(node->left);	// subtree kiri
	displayPreorder(node->right); // subtree kanan
}

void displayInorder(struct node *node)
{
	if (node == NULL)
		return;

	displayInorder(node->left);	 // subtree kiri
	printf("%s ", node->nama);	 // root
	displayInorder(node->right); // subtree kanan
}

void displayPostorder(struct node *node)
{
	if (node == NULL)
		return;

	displayPostorder(node->left);	 // subtree kiri
	displayPostorder(node->right); // subtree kanan
	printf("%s ", node->nama);		 // root
}

void printByLevel(struct node *root, int level)
{
	if (root == NULL)
	{
		return;
	}

	if (level == 1)
	{
		printf("%s ", root->nama);
	}
	else if (level > 1)
	{
		printByLevel(root->left, level - 1);
		printByLevel(root->right, level - 1);
	}
}

void displayByLevels(struct node *root)
{
	int h = getHeight(root);
	for (int i = 1; i <= h; i++)
	{
		printByLevel(root, i);
	}
}

void search_node(struct node *root, char nama[])
{
	struct node *cursor = root;

	while (strcmp(cursor->nama, nama) != 0)
	{
		if (cursor != NULL)
		{
			if (strcmp(nama, cursor->nama) == 1)
			{
				cursor = cursor->right;
			}
			else
			{
				cursor = cursor->left;
			}

			if (cursor == NULL)
			{
				printf("\nNode %d tidak ditemukan", nama);
			}
		}
	}

	printf("\nNode %s ditemukan", nama);
	return;
}

struct node *delete_node(struct node *root, char deletedData[])
{
	if (root == NULL)
	{
		return NULL;
	}

	struct node *cursor;
	if (strcmp(deletedData, root->nama) == 1)
		root->right = delete_node(root->right, deletedData);
	else if (strcmp(deletedData, root->nama) == -1)
		root->left = delete_node(root->left, deletedData);
	else
	{
		// 1 CHILD
		if (root->left == NULL)
		{
			cursor = root->right;
			free(root);
			root = cursor;
		}
		else if (root->right == NULL)
		{
			cursor = root->left;
			free(root);
			root = cursor;
		}
		// 2 CHILDS NODE
		else
		{
			cursor = root->right;
			while (cursor->left != NULL)
			{
				cursor = cursor->left;
			}
			strcpy(root->nama, cursor->nama);
			root->right = delete_node(root->right, cursor->nama);
		}
	}
	return root;

	// Jika setelah dilakukan delete, tree kosong maka return root
	if (root == NULL)
	{
		return root;
	}
	// 2. Update height dari node
	root->height = 1 + max(getHeight(root->left), getHeight(root->right));

	// 3. Hitung balance factor untuk menentukan apakah root unbalanced
	int balance = getBalanceFactor(root);

	// Jika tidak balanced, return hasil rotation

	// Kasus 1: Left Left
	if (balance > 1 && getBalanceFactor(root->left) >= 0)
		return rightRotate(root);

	// Kasus 2: Right Right
	if (balance < -1 && getBalanceFactor(root->right) <= 0)
		return leftRotate(root);

	// Kasus 3: Right Left
	if (balance < -1 && getBalanceFactor(root->right) > 0)
	{
		root->right = rightRotate(root->right);
		return leftRotate(root);
	}

	// Kasus 4: Left Right
	if (balance > 1 && getBalanceFactor(root->left) < 0)
	{
		root->left = leftRotate(root->left);
		return rightRotate(root);
	}
}

int main()
{
	struct node *root = newNode("curry");
	root = insert(root, "giannis");
	root = insert(root, "tatum");
	root = insert(root, "klay");
	root = insert(root, "jokic");
	root = insert(root, "davis");
	root = insert(root, "wemby");
	root = insert(root, "murray");
	root = insert(root, "durant");

	printf("Menampilkan nama secara pre order : ");
	displayPreorder(root);

	printf("\nMenampilkan nama secara in order : ");
	displayInorder(root);

	printf("\nMenampilkan nama secara post order : ");
	displayPostorder(root);

	printf("\nMenampilkan nama berdasarkan ketinggian : ");
	displayByLevels(root);

	printf("\n\nMencari nama : ");
	search_node(root, "klay");

	printf("\n\nMenghapus nama 'durant'");
	delete_node(root, "durant");

	printf("\n\nMenampilkan nama secara in order : ");
	displayInorder(root);

	printf("\nMenampilkan nama berdasrkan ketinggian : ");
	displayInorder(root);

	return 0;
}