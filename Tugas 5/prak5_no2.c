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

// untuk menampilkan linked list
void display()
{
	mynode current = head;

	int idx = 1; // indeks
	while (current != NULL)
	{
		printf("Node %d: %d\n", idx++, current->data);
		current = current->next;
	}
}

int main()
{
	int i, n, tmp;

	printf("Input the number of nodes: ");
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
	{
		printf("Input data for node %d: ", i);
		scanf("%d", &tmp);
		insert_tail(tmp);
	}

	printf("\nData entered in the list are:\n");
	display();

	printf("\nInput data for the first node: ");
	scanf("%d", &tmp);
	insert_tail(tmp);

	printf("After insertion the new list are:\n");
	display();

	return 0;
}