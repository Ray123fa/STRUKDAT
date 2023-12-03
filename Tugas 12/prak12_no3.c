// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // uk maksimal array

typedef struct Student
{
	int nim;
	char nama[50];
	int nilai;
} mhs;

void fill_data(mhs data[], int *size)
{
	printf("Input ukuran array (max 100): ");
	scanf("%d", size);

	if (*size <= 0)
	{
		printf("Jumlah mahasiswa harus lebih dari 0!\n");
		return;
	}

	for (int i = 0; i < *size; i++)
	{
		printf("\nMasukkan data mahasiswa ke-%d:\n", i + 1);
		printf("NIM: ");
		scanf("%d", &data[i].nim);
		printf("Nama: ");
		scanf(" %[^\n]s", data[i].nama);
		printf("Nilai: ");
		scanf("%d", &data[i].nilai);
	}
	printf("\n");
}

void swap(mhs *a, mhs *b)
{
	mhs temp = *a;
	*a = *b;
	*b = temp;
}

void displayStudents(mhs data[], int n)
{
	printf("Datar mahasiswa:\n");
	printf("NIM\tNama\t\tNilai\n");
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t%s\t\t%d\n", data[i].nim, data[i].nama, data[i].nilai);
	}
	printf("\n");
}

void selectionSortAsc(mhs data[], int n, int option)
{
	for (int i = 0; i < n - 1; i++)
	{
		int minIdx = i;

		for (int j = i + 1; j < n; j++)
		{
			switch (option)
			{
			case 1:
				if (data[j].nim < data[minIdx].nim)
				{
					minIdx = j;
				}
				break;
			case 2:
				if (strcmp(data[j].nama, data[minIdx].nama) < 0)
				{
					minIdx = j;
				}
				break;
			case 3:
				if (data[j].nilai < data[minIdx].nilai)
				{
					minIdx = j;
				}
				break;
			default:
				printf("Pilihan tidak valid.\n");
				return;
			}
		}

		if (minIdx != i)
		{
			swap(&data[i], &data[minIdx]);
		}
	}
}

void selectionSortDesc(mhs data[], int n, int option)
{
	for (int i = 0; i < n - 1; i++)
	{
		int maxIndex = i;

		for (int j = i + 1; j < n; j++)
		{
			switch (option)
			{
			case 1:
				if (data[j].nim > data[maxIndex].nim)
				{
					maxIndex = j;
				}
				break;
			case 2:
				if (strcmp(data[j].nama, data[maxIndex].nama) > 0)
				{
					maxIndex = j;
				}
				break;
			case 3:
				if (data[j].nilai > data[maxIndex].nilai)
				{
					maxIndex = j;
				}
				break;
			default:
				printf("Pilihan tidak valid.\n");
				return;
			}
		}

		if (maxIndex != i)
		{
			swap(&data[i], &data[maxIndex]);
		}
	}
}

int main()
{
	system("cls"); // clrscr

	int size;
	mhs data[MAX];
	int choice, choice2;

	fill_data(data, &size);

	do
	{
		printf("Urutkan berdasar:\n");
		printf("1. NIM\n");
		printf("2. Nama\n");
		printf("3. Nilai\n");
		printf("4. Keluar\n");
		printf("Pilihan: ");
		scanf("%d", &choice);

		if (choice == 4)
		{
			printf("\nKeluar dari program...");
			exit(1);
		}
		else
		{
			printf("\nPilih pengurutan:\n");
			printf("1. Menaik\n");
			printf("2. Menurun\n");
			printf("Pilihan: ");
			scanf("%d", &choice2);

			switch (choice2)
			{
			case 1:
				selectionSortAsc(data, size, choice);
				break;
			case 2:
				selectionSortDesc(data, size, choice);
				break;
			default:
				printf("Pilihan tidak valid.\n");
				break;
			}

			printf("\nData mahasiswa setelah diurutkan:\n");
			displayStudents(data, size);
		}
	} while (choice != 4);

	return 0;
}