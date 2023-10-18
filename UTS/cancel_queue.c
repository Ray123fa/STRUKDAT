#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int urut;
	struct node *next;
} Tnode;
typedef Tnode *ptrnode;

typedef struct queue
{
	ptrnode front;
	ptrnode rear;
} Tqueue;
typedef Tqueue *ptrq;

void init(ptrq q)
{
	q->front = q->rear = NULL;
}

ptrnode addnode(int pnumber)
{
	ptrnode newpasien = (ptrnode)malloc(sizeof(ptrnode));
	newpasien->urut = pnumber;
	newpasien->next = NULL;

	return newpasien;
}

void enq(ptrq q, int pnumber)
{
	ptrnode newpasien = addnode(pnumber);

	if (q->rear == NULL)
		q->front = q->rear = newpasien;
	else
	{
		q->rear->next = newpasien;
		q->rear = newpasien;
	}
}

void cancel(ptrq q, int pnumber)
{
	if (q->front->urut == pnumber)
	{
		ptrnode temp = q->front;

		q->front = temp->next;
		free(temp);
		printf("Sudah dibatalkan\n");
	}
	else
	{
		ptrnode cursor = q->front;

		while (cursor->next != NULL && cursor->next->urut != pnumber)
		{
			cursor = cursor->next;
		}

		ptrnode temp = cursor->next;
		cursor->next = temp->next;
		free(temp);
		printf("Sudah dibatalkan\n");
	}
}

void display(ptrq q)
{
	if (q->front == NULL)
	{
		printf("Antrian kosong.\n");
	}
	else
	{
		printf("\nAntrian saat ini: \n");
		ptrnode cursor = q->front;
		while (cursor != NULL)
		{
			printf("%d ", cursor->urut);
			cursor = cursor->next;
		}
		printf("\n");
	}
}

int main()
{
	ptrq antrian;
	init(antrian);

	int pnumber;
	enq(antrian, 5);
	enq(antrian, 7);
	enq(antrian, 9);
	enq(antrian, 11);

	cancel(antrian, 7);
	cancel(antrian, 11);

	display(antrian);

	return 0;
}