// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>	 // biar bisa pake system("cls")
#include <stdbool.h> // agar tipe data boolean dapat digunakan

#define MAX 100 // ukuran maksimum array

void fill_data(int data[], int *size)
{ // mengisi data
	printf("Input ukuran array (max 100): ");
	scanf("%d", size);
	
	printf("Input data (secara urut menaik/menurun)!\n");
	for (int i = 0; i < *size; i++)
	{
		printf("Indeks ke-%d: ", i);
		scanf("%d", &data[i]);
	}
}

bool isAscending(int data[], int size)
{
	if (size <= 1)
		return true;

	for (int i = 1; i < size; i++)
	{
		if (data[i - 1] > data[i])
			return false;
	}
	return true;
}

bool isDescending(int data[], int size)
{
	if (size <= 1)
		return true;

	for (int i = 1; i < size; i++)
	{
		if (data[i - 1] > data[i])
			return false;
	}
	return true;
}

int seq_search(int data[], int size, int x)
{
	if (isAscending(data, size))
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] > x)
				return -1;
			if (data[i] == x)
				return i;
		}
	}

	if (isDescending(data, size))
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] < x)
				return -1;
			if (data[i] == x)
				return i;
		}
	}

	for (int i = 0; i < size; i++)
	{
		if (data[i] == x)
			return i;
	}

	return -1;
}

void main()
{
	int data[MAX];
	int size; // ukuran array
	int x;

	system("cls");
	fill_data(data, &size);
	printf("\nNilai yang mau dicari: ");
	scanf("%d", &x);

	if (seq_search(data, size, x) == -1)
		printf("\nTidak ditemukan");
	else
		printf("\nDitemukan pada indeks ke-%d", seq_search(data, size, x));
}