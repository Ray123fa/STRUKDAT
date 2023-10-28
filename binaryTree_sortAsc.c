#include <stdio.h>
#include <stdlib.h>

/*
	Program ini menggabungkan logika binary search dengan binary tree agar inputan user dapat disesuaikan secara otomatis oleh program. Sehingga nantinya ketika ingin melakukan pencarian untuk data tertentu dapat dilakukan dengan efisien.
*/

typedef struct node
{
	int data;
	struct node *left;
	struct node *right;
} Tnode;
typedef Tnode *ptrnode;

ptrnode createnode(int data)
{
	ptrnode newnode = (ptrnode)malloc(sizeof(Tnode));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

void insert(ptrnode *root, int data)
{
	ptrnode newnode = createnode(data);

	if (*root == NULL)
		*root = newnode;
	else
	{
		int isleft;
		ptrnode cursor = *root;
		ptrnode prev = NULL;

		while (cursor != NULL)
		{
			prev = cursor;
			if (data < cursor->data)
			{
				isleft = 1;
				cursor = cursor->left;
			}
			else
			{
				isleft = 0;
				cursor = cursor->right;
			}
		}

		if (isleft == 1)
			prev->left = newnode;
		else
			prev->right = newnode;
	}
}

ptrnode deletenode(ptrnode root, int data)
{
	if (root == NULL)
		return root;

	if (data < root->data)
		root->left = deletenode(root->left, data);
	else if (data > root->data)
		root->right = deletenode(root->right, data);
	else
	{
		ptrnode cursor;
		if (root->left == NULL)
		{
			cursor = root->right;
			free(root);
			return cursor;
		}
		else if (root->right == NULL)
		{
			cursor = root->left;
			free(root);
			return cursor;
		}
		else
		{
			cursor = root->right;
			while (cursor->left != NULL)
				cursor = cursor->left;

			root->data = cursor->data;
			root->right = deletenode(root->right, cursor->data);
		}
	}

	return root;
}

int search(ptrnode root, int data)
{
	ptrnode cursor = root;

	if (root == NULL)
		printf("Belum terdapat node satupun!\n");
	else
	{
		while (cursor != NULL && cursor->data != data)
		{
			if (data > cursor->data)
				cursor = cursor->right;
			else
				cursor = cursor->left;
		}

		if (cursor == NULL)
			return 0; // Jika node tidak ditemukan
		else
			return 1; // Jika node ditemukan
	}
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
	ptrnode root = NULL;

	do
	{
		int choose, data;

		system("cls");
		printf("Program Binary Tree\n\n");
		printf("1. Tambah node\n");
		printf("2. Tampilkan node\n");
		printf("3. Cari node\n");
		printf("4. Delete node\n");
		printf("Selain 1-4 untuk keluar\n");
		printf("Pilihan Anda: ");
		scanf("%d", &choose);
		printf("\n");

		switch (choose)
		{
		case 1:
			printf("Masukkan node: ");
			scanf("%d", &data);
			insert(&root, data);
			printf("Node berhasil ditambahkan\n\n");

			printf("Berikut node yang Anda miliki: ");
			displayPre(root);
			printf("\n");
			break;
		case 2:
			printf("Display Pre-order: ");
			displayPre(root);
			printf("\n");

			printf("Display In-order: ");
			displayIn(root);
			printf("\n");

			printf("Display Post-order: ");
			displayPost(root);
			printf("\n");
			break;
		case 3:
			printf("Masukkan node yang ingin dicari: ");
			scanf("%d", &data);
			if (search(root, data))
				printf("Node %d ditemukan\n", data);
			else
				printf("Node %d tidak ditemukan\n", data);
			break;
		case 4:
			printf("Masukkan node yang ingin dihapus: ");
			scanf("%d", &data);
			// Telusuri node yang ingin dihapus dengan menggunakan fungsi search
			if (search(root, data))
			{
				deletenode(root, data);
				printf("Node %d telah dihapus\n", data);
			}
			else
				printf("Node %d tidak ditemukan\n", data);
			break;
		default:
			printf("Terima kasih!");
			exit(1);
		}

		// Selama user tidak menekan enter, user belum dapat memilih menu lagi
		printf("\nTekan Enter untuk memilih menu lagi...");
		while (getchar() != '\n')
			;
		getchar();
	} while (1);
}