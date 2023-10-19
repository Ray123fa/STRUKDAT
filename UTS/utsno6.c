// Muhammad Rayhan Faridh

#include <stdio.h>

#define N 10
int q[N], front, rear;

void insert(int nilai)
{
	if (rear == N - 1)
	{
		printf("Antrian penuh!\n");
		return;
	}

	if (front == -1)
		front = 0;

	q[rear++] = nilai;
}

void _remove()
{
	if (rear == -1)
	{
		printf("Antrian kosong!\n");
		return;
	}

	if (front == rear)
		front = rear = -1;
	else
		front++;
}

void display()
{
	for (int i = front; i < rear; i++)
	{
		printf("%d ", q[i]);
	}
	printf("\n");
}

void main()
{
	insert(5);
	insert(7);
	insert(12);
	display();

	_remove();
	display();

	insert(10);
	display();
}