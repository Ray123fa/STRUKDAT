// Muhammad Rayhan Faridh

#include <stdio.h>
#include <stdlib.h>

// Kamus
// koef untuk menyimpan nilai koefisien tiap suku polinomial
// exp untuk menyimpan nilai eksponen tiap suku polinomial

typedef struct node
{
	int koef;
	int exp;
	struct node *next;
} Tnode;
typedef Tnode *ptrnode;

// Create a node
ptrnode createnode(int koef, int exp)
{
	ptrnode newnode = (ptrnode)malloc(sizeof(Tnode));
	newnode->koef = koef;
	newnode->exp = exp;
	newnode->next = NULL;

	return newnode;
}

// Push polynomial to node
void pushPolynom(ptrnode *head, int koef, int exp)
{
	ptrnode newnode = createnode(koef, exp);
	ptrnode cursor = *head;

	if (*head == NULL || cursor->exp < exp)
	{
		newnode->next = *head;
		*head = newnode;
	}
	else
	{
		// Telusuri hingga cursor->next bernilai NULL atau cursor->next->exp >= exp
		while (cursor->next != NULL && cursor->next->exp >= exp)
		{
			cursor = cursor->next;
		}
		newnode->next = cursor->next;
		cursor->next = newnode;
	}
}

// Addition polynomial
ptrnode addPolynom(ptrnode head1, ptrnode head2)
{
	ptrnode result = NULL;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->exp > head2->exp)
		{
			pushPolynom(&result, head1->koef, head1->exp);
			head1 = head1->next;
		}
		else if (head1->exp < head2->exp)
		{
			pushPolynom(&result, head2->koef, head2->exp);
			head2 = head2->next;
		}
		else
		{
			if (head1->koef + head2->koef != 0)
				pushPolynom(&result, head1->koef + head2->koef, head1->exp);
			head1 = head1->next;
			head2 = head2->next;
		}
	}

	while (head1 != NULL)
	{
		pushPolynom(&result, head1->koef, head1->exp);
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		pushPolynom(&result, head2->koef, head2->exp);
		head2 = head2->next;
	}

	return result;
}

// Input the polynomial
void input(ptrnode *head)
{
	int jumsuku, koef, exp;

	printf("Masukkan banyak suku: ");
	scanf("%d", &jumsuku);
	for (int i = 1; i <= jumsuku; i++)
	{
		printf("Koefisien suku ke-%d: ", i);
		scanf("%d", &koef);
		printf("Eksponen suku ke-%d: ", i);
		scanf("%d", &exp);

		pushPolynom(head, koef, exp);
	}
	printf("\n");
}

void display(ptrnode head)
{
	while (head != NULL)
	{
		printf("%d   %d\n", head->koef, head->exp);
		head = head->next;
	}
}

int main()
{
	ptrnode poly1 = NULL;
	ptrnode poly2 = NULL;
	ptrnode result = NULL;

	system("cls");
	printf("Polinomial ke-1\n");
	input(&poly1);
	printf("Polinomial ke-2\n");
	input(&poly2);

	result = addPolynom(poly1, poly2);

	printf("Hasil penambahan polinomial:\n");
	display(result);

	return 0;
}