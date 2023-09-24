// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
	int nim;
	char nama[50];
	struct Student *next;
};
typedef struct Student *studentPtr;

// fungsi berikut akan menambahkan data yang terbaru di belakang
// contoh node1 = [222212766, "Rayhan"] dan node2 = [222212765, "Faridh"]
// maka urutan dalam linked list menjadi [222212766, "Rayhan"] -> [222212765, "Faridh"]
studentPtr addStudent(studentPtr *head, const int nim, const char *nama)
{
	studentPtr newStudent;
	newStudent = (studentPtr)malloc(sizeof(struct Student));
	newStudent->nim = nim;
	strcpy(newStudent->nama, nama);

	if (*head == NULL)
	{
		*head = newStudent;
	}
	else
	{
		studentPtr current = *head;
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = newStudent;
	}

	return newStudent;
}

// hapus student berdasar NIM
void removeStudent(studentPtr *head, int targetNIM)
{
	studentPtr prev = NULL;
	studentPtr current = *head;

	// cari NIM yang sesuai
	while (current != NULL && current->nim != targetNIM)
	{
		prev = current;
		current = current->next;
	}

	if (current != NULL)
	{
		// jika yang dihapus di node awal
		if (prev == NULL)
		{
			*head = current->next;
		}
		else
		{
			prev->next = current->next;
		}

		free(current); // bebaskan memori
		printf("Data dengan NIM %d telah dihapus.\n\n", targetNIM);
	}
	else
	{
		printf("NIM %d tidak ditemukan.\n\n", targetNIM);
	}
}

void displayStudents(studentPtr head)
{
	studentPtr current = head;
	printf("\nDaftar Mahasiswa:\n");

	int idx = 1; // indeks
	while (current != NULL)
	{
		printf("%d. %s (NIM: %d)\n", idx++, current->nama, current->nim);
		current = current->next;
	}
	printf("Data telah ditampilkan.\n\n");
}

void menu(studentPtr *head)
{
	int pil;

	printf("Selamat Datang di Siforma (Sistem Informasi Mahasiswa)\n");
	printf("1. Buat/Tambah Data\n");
	printf("2. Tampilkan Data\n");
	printf("3. Hapus Data\n");
	printf("Input selain 1 - 3 untuk keluar.\n");
	printf("Pilihan Anda: ");
	scanf("%d", &pil);

	switch (pil)
	{
	case 1:
		int i, n, nim;
		char nama[50];

		printf("\nBanyak data yang ingin ditambahkan: ");
		scanf("%d", &n);
		for (i = 1; i <= n; i++)
		{
			printf("Data ke-%d:\n", i);
			printf("NIM : ");
			scanf("%d", &nim);
			printf("Nama: ");
			scanf(" %[^\n]s", nama);

			addStudent(head, nim, nama); // panggil fungsi
			printf("\n");
		}
		printf("Data berhasil ditambahkan.\n\n");
		break;

	case 2:
		if (*head == NULL)
		{
			printf("Tidak ada data yang dapat ditampilkan.\n\n");
		}
		else
		{
			displayStudents(*head);
		}
		break;

	case 3:
		if (*head == NULL)
		{
			printf("Tidak ada data yang dapat dihapus.\n\n");
		}
		else
		{
			int targetNIM;
			printf("\nMasukkan NIM yang ingin dihapus: ");
			scanf("%d", &targetNIM);
			removeStudent(head, targetNIM); // panggil fungsi
		}
		break;

	default:
		printf("\nTerima kasih!");
		exit(0);
	}
}

void main()
{
	studentPtr head = NULL;

	// perulangan terus berjalan hingga pengguna memilih keluar
	while (1)
	{
		menu(&head);
	}
}