// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
	char nama[30];
	struct node *left;
	struct node *right;
} Tnode;
typedef Tnode *ptrnode;

ptrnode createnode(char nama[])
{
	ptrnode newnode = (ptrnode)malloc(sizeof(Tnode));
	strcpy(newnode->nama, nama);
	newnode->left = NULL;
	newnode->right = NULL;

	return newnode;
}

// Fungsi insert berikut masih dapat menerima data duplikat, dan diletakkan di sebelah kanan temp
void insert(ptrnode *root, char nama[])
{
	ptrnode newnode = createnode(nama);

	if (*root == NULL)
		*root = newnode;
	else
	{
		int compare;
		ptrnode cursor = *root;
		ptrnode temp = NULL;

		while (cursor != NULL)
		{
			temp = cursor;
			// <0 jika urutan alphabet nama < cursor->nama
			// >0 jika urutan alphabet nama > cursor->nama
			// =0 jika nama = cursor->nama
			compare = strcmp(nama, cursor->nama);

			if (compare < 0)
				cursor = cursor->left;
			else
				cursor = cursor->right;
		}

		if (compare < 0)
			temp->left = newnode;
		else
			temp->right = newnode;
	}
}

/*
	Diberikan tipe data integer karena fungsi search akan diperuntukkan pada pengecekan apakah data yang ingin dihapus nanti terdapat pada binary tree atau tidak
	0 jika tidak terdapat pada binary tree
	1 jika terdapat pada binary tree
*/
// Pencarian nama masih dan harus menggunakan nama lengkap, tidak bisa hanya dengan nama depan/tengah/belakang saja
int search(ptrnode root, char nama[])
{
	ptrnode cursor = root;

	while (cursor != NULL && strcmp(nama, cursor->nama) != 0)
	{
		if (strcmp(nama, cursor->nama) < 0)
			cursor = cursor->left;
		else
			cursor = cursor->right;
	}

	if (cursor == NULL)
		return 0;
	else
		return 1;
}

// Sama dengan fungsi search, masih dan harus menggunakan nama lengkap
ptrnode deletenode(ptrnode root, char nama[])
{
	if (root == NULL)
		return root;

	int compare = strcmp(nama, root->nama);
	if (compare < 0)
		root->left = deletenode(root->left, nama);
	else if (compare > 0)
		root->right = deletenode(root->right, nama);
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

			strcpy(root->nama, cursor->nama);
			root->right = deletenode(root->right, cursor->nama);
		}
	}

	return root;
}

void displayPre(ptrnode root)
{
	if (root == NULL)
		return;

	printf("%s\n", root->nama);
	displayPre(root->left);
	displayPre(root->right);
}

void displayIn(ptrnode root)
{
	if (root == NULL)
		return;

	displayIn(root->left);
	printf("%s\n", root->nama);
	displayIn(root->right);
}

void displayPost(ptrnode root)
{
	if (root == NULL)
		return;

	displayPost(root->left);
	displayPost(root->right);
	printf("%s\n", root->nama);
}

int main()
{
	ptrnode root = NULL;

	do
	{
		int choose;
		char nama[30];

		system("cls");
		printf("Program Binary Tree\n\n");
		printf("1. Tambah node (nama)\n");
		printf("2. Tampilkan node (nama)\n");
		printf("3. Cari node (nama)\n");
		printf("4. Delete node (nama)\n");
		printf("Selain 1-4 untuk keluar\n");
		printf("Pilihan Anda: ");
		scanf("%d", &choose);
		printf("\n");

		switch (choose)
		{
		case 1:
			printf("Masukkan nama: ");
			getchar();
			scanf("%[^\n]s", nama);

			insert(&root, nama);
			printf("Nama berhasil ditambahkan\n\n");

			printf("Berikut nama-nama yang telah ditambahkan:\n");
			displayPre(root);

			break;
		case 2:
			if (root != NULL)
			{
				printf("Display Pre-order:\n");
				displayPre(root);
				printf("\n");

				printf("Display In-order:\n");
				displayIn(root);
				printf("\n");

				printf("Display Post-order:\n");
				displayPost(root);
			}
			else
				printf("Tidak ada yang dapat ditampilkan!\n");

			break;
		case 3:
			if (root != NULL)
			{
				printf("Masukkan nama yang ingin dicari: ");
				getchar();
				scanf("%[^\n]s", nama);

				if (search(root, nama))
					printf("Nama '%s' ditemukan\n", nama);
				else
					printf("Nama '%s' tidak ditemukan\n", nama);
			}
			else
				printf("Binary Tree masih kosong!\n");

			break;
		case 4:
			if (root != NULL)
			{
				printf("Masukkan nama yang ingin dihapus: ");
				getchar();
				scanf("%[^\n]s", nama);

				// Telusuri nama yang ingin dihapus dengan menggunakan fungsi search sebelum memanggil fungsi deletenode
				if (search(root, nama))
				{
					root = deletenode(root, nama);
					printf("Nama '%s' telah dihapus\n", nama);
				}
				else
					printf("Nama '%s' tidak ditemukan\n", nama);
			}
			else
				printf("Tidak ada yang dapat dihapus!\n");

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

	return 0;
}