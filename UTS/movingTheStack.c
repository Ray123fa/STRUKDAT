#include <stdio.h>
#include <stdlib.h>

int a[10], b[10];
int topa, topb;
topa = 6;
topb = -1;

void pindah()
{
	int temp[10];
	int topt = -1;

	while (topa != -1)
	{
		temp[++topt] = a[topa--];
	}
	while (topt != -1)
	{
		b[++topb] = temp[topt--];
	}
}

void display(int tmp[], int top)
{
	for (int i = 0; i <= top; i++)
	{
		printf("%d ", tmp[i]);
	}
	printf("\n");
}

int main()
{
	for (int i = 0; i <= topa; i++)
	{
		scanf("%d", &a[i]);
	}

	display(a, topa);
	pindah();
	display(b, topb);

	return 0;
}