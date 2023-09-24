// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *prev;
	struct node *next;
};
typedef struct node *mynode;

// set as a global variable
mynode head = NULL;

// simpul awal
mynode createNode(int nilai)
{
	mynode newNode;
	newNode = (mynode)malloc(sizeof(struct node));
	newNode->data = nilai;
	newNode->prev = NULL;
	newNode->next = NULL;

	return newNode;
}

// fungsi utk mencari ujung linked list
mynode find_tail(mynode head)
{
	mynode cursor = head;

	while (cursor->next != NULL)
		cursor = cursor->next;

	return cursor;
}

// insert sebagai node akhir
mynode insert_tail(int nilai)
{
	mynode newNode = createNode(nilai);

	if (head == NULL)
	{
		head = newNode;
	}
	else
	{
		mynode tail = find_tail(head);
		tail->next = newNode;
		newNode->prev = tail;
	}

	return newNode;
}

// remove tail
mynode remove_tail()
{
	if (head->next == NULL)
	{
		free(head);
		return NULL;
	}
	else
	{
		mynode cursor = find_tail(head);
		mynode temp = cursor;

		cursor = cursor->prev;
		temp->prev = NULL;
		cursor->next = NULL;

		free(temp);
		return head;
	}
}

// untuk menampilkan linked list
void display()
{
	mynode current = head;

	while (current != NULL)
	{
		if (current->prev == NULL)
		{
			printf("NULL <- %d <-> ", current->data);
		}
		else if (current->next == NULL)
		{
			printf("%d -> NULL\n\n", current->data);
		}
		else
		{
			printf("%d <-> ", current->data);
		}
		current = current->next;
	}
}

void menu()
{
	int pil;

	do
	{
		printf("1. Buat/Tambah Data\n");
		printf("2. Tampilkan Data\n");
		printf("3. Hapus Data\n");
		printf("Input selain 1 - 3 untuk keluar.\n");
		printf("Pilihan Anda: ");
		scanf("%d", &pil);

		switch (pil)
		{
		case 1:
			int i, n, nilai;
			printf("\nBanyak data yang ingin ditambahkan: ");
			scanf("%d", &n);
			for (i = 1; i <= n; i++)
			{
				printf("Data ke-%d: ", i);
				scanf("%d", &nilai);
				insert_tail(nilai);
			}
			printf("Data berhasil ditambahkan.\n\n");
			break;

		case 2:
			if (head == NULL)
			{
				printf("Tidak ada data yang dapat ditampilkan.\n\n");
			}
			else
			{
				display();
			}
			break;

		case 3:
			if (head == NULL)
			{
				printf("Tidak ada data yang dapat dihapus.\n\n");
			}
			else
			{
				head = remove_tail();
				printf("Data terakhir telah dihapus.\n\n");
			}
			break;

		default:
			printf("\nTerima kasih!\n");
			exit(0);
		}
	} while (1);
}

int main()
{
	menu();

	return 0;
}