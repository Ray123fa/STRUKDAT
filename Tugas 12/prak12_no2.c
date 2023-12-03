// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>

#define MAX 100 // uk maksimal array

void fill_data(int data[], int *size) // isi data
{
	printf("\nInput Jumlah Data (max 100): ");
	scanf("%d", size);
	printf("Input data: \n");

	for (int i = 0; i < *size; i++)
	{
		printf("Data ke-%d: ", i + 1);
		scanf("%d", &data[i]);
	}
}

void tampil_data(int data[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", data[i]);
	printf("\n");
}

void insertionSortAsc(int arr[], int n)
{
	int i, key, j;

	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void insertionSortDesc(int arr[], int n)
{
	int i, key, j;

	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] < key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selectionSortAsc(int data[], int size)
{
	for (int step = 0; step < size - 1; step++)
	{
		int min_idx = step;

		for (int i = step + 1; i < size; i++)
			if (data[i] < data[min_idx])
				min_idx = i;

		swap(&data[min_idx], &data[step]);
	}
}

void selectionSortDesc(int data[], int size)
{
	for (int step = 0; step < size - 1; step++)
	{
		int max_idx = step;

		for (int i = step + 1; i < size; i++)
			if (data[i] > data[max_idx])
				max_idx = i;

		swap(&data[max_idx], &data[step]);
	}
}

void mergeAsc(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];

	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeDesc(int arr[], int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;
	int L[n1], R[n2];

	for (i = 0; i < n1; i++)
		L[i] = arr[l + i];

	for (j = 0; j < n2; j++)
		R[j] = arr[m + 1 + j];

	i = 0;
	j = 0;
	k = l;

	while (i < n1 && j < n2)
	{
		if (L[i] >= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		arr[k] = R[j];
		j++;
		k++;
	}
}

void mergeSortAsc(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSortAsc(arr, l, m);
		mergeSortAsc(arr, m + 1, r);
		mergeAsc(arr, l, m, r);
	}
}

void mergeSortDesc(int arr[], int l, int r)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;

		mergeSortDesc(arr, l, m);
		mergeSortDesc(arr, m + 1, r);
		mergeDesc(arr, l, m, r);
	}
}

void bubbleSortAsc(int arr[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void bubbleSortDesc(int arr[], int n)
{
	int i, j;

	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (arr[j] < arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
}

void menu1()
{
	printf("\nMetode Sorting yang tersedia ");
	printf("\n1. Insertion Sort");
	printf("\n2. Selection Sort");
	printf("\n3. Merge Sort");
	printf("\n4. Bubble Sort");
	printf("\n5. Keluar");
}

void menu2()
{
	printf("\nPilih pengurutan");
	printf("\n1. Naik");
	printf("\n2. Turun");
	printf("\n3. Keluar");
}

int main()
{
	int choose, size;
	int data[MAX];
	int choose2;

	fill_data(data, &size);
	do
	{
		printf("\n### PROGRAM SORTING DATA ###");
		menu1();

		printf("\nPilihan Metode Pengurutan: ");
		scanf("%d", &choose);

		switch (choose)
		{
		case 1:
			menu2();

			printf("\nPilihan pengurutan: ");
			scanf("%d", &choose2);
			if (choose2 == 1)
			{
				insertionSortAsc(data, size);
				printf("Data setelah diurutkan:\n");
				tampil_data(data, size);
			}
			else if (choose2 == 2)
			{
				insertionSortDesc(data, size);
				printf("Data setelah diurutkan:\n");
				tampil_data(data, size);
			}
			else
				printf("\nKeluar dari program.\n");
			break;
		case 2:
			menu2();

			printf("\nPilihan pengurutan: ");
			scanf("%d", &choose2);
			if (choose2 == 1)
			{
				selectionSortAsc(data, size);
				printf("Data setelah diurutkan:\n");
				tampil_data(data, size);
			}
			else if (choose2 == 2)
			{
				selectionSortDesc(data, size);
				printf("Data setelah diurutkan:\n");
				tampil_data(data, size);
			}
			else
				printf("\nKeluar dari program.\n");
			break;
		case 3:
			menu2();

			printf("\nPilihan pengurutan: ");
			scanf("%d", &choose2);
			if (choose2 == 1)
			{
				mergeSortAsc(data, 0, size - 1);
				printf("Data setelah diurutkan:\n");
				tampil_data(data, size);
			}
			else if (choose2 == 2)
			{
				mergeSortDesc(data, 0, size - 1);
				printf("Data setelah diurutkan:\n");
				tampil_data(data, size);
			}
			else
				printf("\nKeluar dari program.\n");
			break;
		case 4:
			menu2();

			printf("\nPilihan pengurutan: ");
			scanf("%d", &choose2);
			if (choose2 == 1)
			{
				bubbleSortAsc(data, size);
				printf("Data setelah diurutkan:\n");
				tampil_data(data, size);
			}
			else if (choose2 == 2)
			{
				bubbleSortDesc(data, size);
				printf("Data setelah diurutkan:\n");
				tampil_data(data, size);
			}
			else
				printf("\nKeluar dari program.\n");
			break;
		case 5:
			printf("\nAnda telah keluar dari program.");
			break;
		default:
			printf("Program tidak dapat menangani input.\n");
			break;
		}
	} while (choose != 5);

	return 0;
}