#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue
{
	int stack1[MAX_SIZE];
	int stack2[MAX_SIZE];
	int top1, top2;
};

void initialize(struct Queue *queue)
{
	queue->top1 = -1; // Inisialisasi stack 1
	queue->top2 = -1; // Inisialisasi stack 2
}

void enqueue(struct Queue *queue, int value)
{
	if (queue->top1 == MAX_SIZE - 1)
	{
		printf("Queue is full. Cannot enqueue.\n");
		return;
	}
	else
	{
		queue->stack1[++queue->top1] = value;
	}
}

int dequeue(struct Queue *queue)
{
	if (queue->top1 == -1 && queue->top2 == -1)
	{
		printf("Queue is empty. Cannot dequeue.\n");
		exit(1);
	}

	if (queue->top2 == -1)
	{
		// Transfer semua elemen dari stack1 ke stack2
		while (queue->top1 >= 0)
		{
			queue->stack2[++queue->top2] = queue->stack1[queue->top1--];
		}
	}

	// Pop elemen dari stack2
	return queue->stack2[queue->top2--];
}

void display(struct Queue *queue)
{
	printf("Queue Contents: ");

	// Mencetak elemen-elemen dari stack2 terlebih dahulu (elemen yang telah didequeue)
	for (int i = queue->top2; i >= 0; i--)
	{
		printf("%d ", queue->stack2[i]);
	}

	// Mencetak elemen-elemen dari stack1 (elemen yang belum didequeue)
	for (int i = 0; i <= queue->top1; i++)
	{
		printf("%d ", queue->stack1[i]);
	}

	printf("\n");
}

int main()
{
	struct Queue queue;
	initialize(&queue);

	enqueue(&queue, 1);
	enqueue(&queue, 2);
	enqueue(&queue, 3);

	display(&queue); // Cetak antrian sebelum dequeue
	printf("Dequeued: %d\n", dequeue(&queue));
	display(&queue); // Cetak antrian sesudah dequeue

	enqueue(&queue, 4);

	display(&queue); // Cetak antrian setelah enqueue

	return 0;
}