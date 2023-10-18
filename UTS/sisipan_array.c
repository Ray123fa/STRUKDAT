#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 5
struct kalinfo
{
	char kalimat[100];
	int jumkata;
};
struct kalinfo par[max];
int last = -1;

void display()
{
	printf("Paragraf:\n");
	for (int i = 0; i <= last; i++)
	{
		printf("%s (%d kata)\n", par[i].kalimat, par[i].jumkata);
	}
}

void insert(char kal[], int jum)
{
	if (last < max - 1)
	{
		last++;
		strcpy(par[last].kalimat, kal);
		par[last].jumkata = jum;
	}
	else
	{
		printf("Penuh!\n");
	}
}

void insertke(char kal[], int jum, int n)
{
	if (last < max - 1 && n >= 0 && n < last + 1)
	{
		for (int i = last; i >= n; i--)
		{
			strcpy(par[i + 1].kalimat, par[i].kalimat);
			par[i + 1].jumkata = par[i].jumkata;
		}
		strcpy(par[n].kalimat, kal);
		par[n].jumkata = jum;
		last++;
	}
	else
	{
		printf("Sisipan diluar jangkauan!\n");
	}
}

int hitkal_n(int n)
{
	int count = 0;
	for (int i = 0; i <= last; i++)
	{
		if (par[i].jumkata == n)
		{
			count++;
		}
	}

	return count;
}

int main()
{
	insert("Kal 1", 2);
	insert("Kal ke 2", 3);
	insert("Kal ke 3", 3);
	insertke("Kal sisip", 2, 0);
	display();
	printf("\nJumlah kalimat dengan 3 kata adalah %d\n", hitkal_n(3));

	return 0;
}