// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>

struct Person
{
	char *nama;
	int usia;
};

int main()
{
	struct Person person;

	// alokasi memori
	person.nama = (char *)malloc(50 * sizeof(char));
	if (person.nama == NULL)
	{
		printf("Alokasi memori tidak berhasil.");
		return 1;
	}

	// input data
	printf("Masukkan nama: ");
	scanf("%[^\n]s", person.nama);
	printf("Masukkan usia: ");
	scanf("%d", &person.usia);

	// display data
	printf("\nData Person\n");
	printf("Nama: %s\n", person.nama);
	printf("Usia: %d\n", person.usia);

	// bebaskan memori pointer nama
	free(person.nama);

	return 0;
}