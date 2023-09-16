#include <stdio.h>
#include <stdlib.h>

struct mynode
{
	int data;
	struct mynode *next;
};

int main()
{
	struct mynode *head = NULL;
	struct mynode *dua = NULL;
	struct mynode *tiga = NULL;

	head = (struct mynode *)malloc(sizeof(struct mynode));
	dua = (struct mynode *)malloc(sizeof(struct mynode));
	tiga = (struct mynode *)malloc(sizeof(struct mynode));

	head->data = 10;
	head->next = dua;

	dua->data = 20;
	dua->next = tiga;

	tiga->data = 30;
	tiga->next = NULL;

	printf("Ukuran:\n");
	printf("%d\n", sizeof(struct mynode));
	printf("%d\n", sizeof(head));
	printf("%d\n", sizeof(dua));
	printf("%d\n", sizeof(tiga));

	printf("\nIsi dari linked list:\n");
	struct mynode *n = head;
	while (n != NULL)
	{
		printf("%d\n", n->data);
		n = n->next;
	}

	return 0;
}