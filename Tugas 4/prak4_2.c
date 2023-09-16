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

mynode reverseNode(mynode head, int sum)
{
	if (head == NULL || head->next == NULL)
		return head;

	int values[sum]; // array values digunakan untuk menyimpan nilai dari node
	mynode current = head;

	int index = 0;
	while (current != NULL)
	{
		values[index++] = current->data;
		current = current->next;
	}

	current = head; // set current menjadi head lagi

	// atur isi linked list menjadi reverse
	while (index > 0)
	{
		current->data = values[--index];
		current = current->next;
	}

	return head;
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

	int n = 5; // n adalah total node yang dibuat
	for (int i = 1; i <= n; i++)
	{
		createNode(&head, i);
	}

	// sebelum direversed
	printf("Linked list sebelum dibalikkan:\n");
	displayList(head);

	head = reverseNode(head, n); // panggil fungsi reverse

	// setelah direversed
	printf("\nLinked list setelah dibalikkan:\n");
	displayList(head);
}