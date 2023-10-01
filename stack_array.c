#include <stdio.h>
#include <stdlib.h>

int N = 5;
int stack[5], top;

void display(int stack[])
{
	if (top >= 0)
	{
		printf("\nIsi stack:\n");
		for (int i = top; i >= 0; i--)
		{
			printf("%d\n", stack[i]);
		}
	}
	else
	{
		printf("\nStack kosong.\n");
	}
	printf("\n");
}

void push(int stack[], int item)
{
	if (top == N - 1)
	{
		printf("\nStack penuh, tidak dapat menambah item baru.\n");
	}
	else
	{
		top++;
		stack[top] = item;
	}
}

void pop(int stack[])
{
	if (top == -1)
	{
		printf("Stack sudah kosong\n\n");
	}
	else
	{
		int delItem = stack[top];
		top--;
		printf("%d telah terhapus\n\n", delItem);
	}
}

int main()
{
	top = -1;
	int choice = 0;
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
			display(stack);
			break;
		case 2:
			int item = 0;
			printf("\nMasukkan item untuk ditambah: ");
			scanf("%d", &item);
			push(stack, item);
			printf("\n");
			break;
		case 3:
			pop(stack);
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