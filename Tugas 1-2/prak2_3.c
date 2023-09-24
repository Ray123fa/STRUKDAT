// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>

void inputMatriks(int matriks[3][4])
{
	printf("Silakan input matriks dalam 3x4!\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("Baris %d, kolom %d: ", i + 1, j + 1);
			scanf("%d", &matriks[i][j]);
		}
	}
}

void cetak(int matriks[3][4])
{
	printf("\nMatriks yang terbentuk: \n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", matriks[i][j]);
		}
		printf("\n");
	}
}

void main()
{
	int matriks[3][4];

	inputMatriks(matriks);
	cetak(matriks);
}