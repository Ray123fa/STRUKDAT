// Muhammad Rayhan Faridh

#include <stdio.h>

typedef struct Mahasiswa
{
	char name[20];
	char address[20];
	int *age;
} mhs_struct;

void input(mhs_struct *ptrmhs)
{
	printf("Masukkan nama: ");
	scanf("%[^\n]s", ptrmhs->name);
	getchar();
	printf("Masukkan alamat: ");
	scanf("%[^\n]s", ptrmhs->address);
	getchar();
	printf("Masukkan umur: ");
	scanf("%d", &ptrmhs->age);
}

void display(mhs_struct *ptrmhs)
{
	printf("Nama: %s\n", ptrmhs->name);
	printf("Alamat: %s\n", ptrmhs->address);
	printf("Umur: %d", ptrmhs->age);
}

int main()
{
	mhs_struct mhs;
	input(&mhs);
	display(&mhs);

	return 0;
}