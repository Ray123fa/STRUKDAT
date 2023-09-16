// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node *mynode;

// fungsi berikut akan menambahkan node baru di depan
// contoh node1 = 3, node2 = 5
// maka urutan dalam linked list menjadi 5 -> 3
mynode createNode(mynode *head, int nilai)
{
	mynode newNode;
	newNode = (mynode)malloc(sizeof(struct node));
	newNode->data = nilai;
	newNode->next = *head;
	*head = newNode;

	return newNode;
}

int hitungNode(mynode head)
{
	int count = 0;

	struct node *now = head;
	while (now != NULL)
	{
		count++;
		now = now->next;
	}

	return count;
}

void displayList(mynode head)
{
	mynode current = head;
	while (current != NULL)
	{
		printf("%d -> ", current->data);
		current = current->next;
	}
	printf("NULL\n");
}

void main()
{
	mynode head = NULL;

	createNode(&head, 10);
	createNode(&head, 20);
	createNode(&head, 30);

	int sumNode = hitungNode(head);
	printf("Jumlah node dalam linked list adalah %d\n", sumNode);
	displayList(head);
}