// Muhammad Rayhan Faridh

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int nilai;
	struct node *next;
} Tnode;
typedef Tnode *ptrnode;

// Daftar Fungsi
ptrnode createnode(int);
void addnode(ptrnode *, int);
void input(ptrnode *);
void display(ptrnode);
void repeat(ptrnode *);

ptrnode createnode(int nilai)
{
	ptrnode newnode = (ptrnode)malloc(sizeof(Tnode));
	newnode->nilai = nilai;
	newnode->next = NULL;

	return newnode;
}

void addnode(ptrnode *head, int nilai)
{
	ptrnode newnode = createnode(nilai);
	ptrnode cursor = *head;

	if (*head == NULL || cursor->nilai < nilai)
	{
		newnode->next = *head;
		*head = newnode;
	}
	else
	{
		while (cursor->next != NULL && cursor->next->nilai >= nilai)
		{
			cursor = cursor->next;
		}
		newnode->next = cursor->next;
		cursor->next = newnode;
	}
}

void input(ptrnode *head)
{
	int nilai;
	printf("Masukkan angka yang ingin ditambah: ");
	scanf("%d", &nilai);

	addnode(head, nilai);
	display(*head);
	repeat(head);
}

void display(ptrnode head)
{
	ptrnode cursor = head;
	while (cursor != NULL)
	{
		printf("%d -> ", cursor->nilai);
		cursor = cursor->next;
	}
	printf("NULL\n");
}

void repeat(ptrnode *head)
{
	int repeat;

	printf("\nTambah repeat? (1=Ya / 0=Tidak): ");
	scanf("%d", &repeat);
	(repeat == 1) ? input(head) : printf("\nTerima kasih!");
	exit(0);
}

void main()
{
	ptrnode head = NULL;
	input(&head);
	repeat(&head);
}