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

// fungsi reverse double link list
void reverseNode()
{
	mynode prev = NULL;
	mynode current = head;
	mynode temp = NULL;

	while (current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}

	if (temp != NULL)
		head = temp->prev;
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

int main()
{
	// Insert node
	insert_tail(1);
	insert_tail(2);
	insert_tail(3);

	printf("Sebelum direverse:\n");
	display();

	// panggil fungsi reverse
	reverseNode();

	printf("Setelah direverse:\n");
	display();

	return 0;
}