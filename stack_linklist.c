#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node *item;

item top; // set as global var

void init()
{
	top = NULL;
}

void push(int val)
{
	item newnode;
	newnode = (item)malloc(sizeof(struct node));
	newnode->data = val;
	newnode->next = top;
	top = newnode;
}

void pop()
{
	item tmp;
	tmp = top;
	top = top->next;
	free(tmp);
}

void display(item head)
{
	if (head != NULL)
	{
		printf("%d\n", head->data);
		if (head->next != NULL)
		{
			display(head->next);
		}
	}
	else
	{
		printf("Stack kosong.\n");
	}
	printf("\n");
}

int main()
{
	init();

	int choice;
	do
	{
		printf("Opsi Tersedia\n");
		printf("1. Display\n");
		printf("2. Tambah (PUSH)\n");
		printf("3. Hapus (POP)\n");
		printf("4. Exit\n");
		printf("Masukkan Pilihan: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			display(top);
			break;
		case 2:
			int n;
			printf("\nMasukkan item untuk ditambah: ");
			scanf("%d", &n);
			push(n);
			printf("\n");
			break;
		case 3:
			if (top == NULL)
			{
				printf("Stack kosong");
			}
			else
			{
				pop();
			}
			break;
		case 4:
			printf("Keluar");
			break;
		default:
			printf("Pilihan tidak valid!");
		}
	} while (choice != 4);

	return 0;
}