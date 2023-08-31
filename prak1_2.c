// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <unistd.h> // agar bisa menggunakan fungsi sleep

int luas(int p, int l)
{
	return p * l;
}

int keliling(int p, int l)
{
	return 2 * (p + l);
}

void main()
{
	int p, l;

	printf("Program Hitung Luas dan Keliling Persegi Panjang\n\n");

	printf("Masukkan panjang: ");
	scanf("%d", &p);
	printf("Masukkan lebar: ");
	scanf("%d", &l);
	printf("Luas persegi panjang = %d satuan\n", luas(p, l));
	printf("Keliling persegi panjang = %d satuan\n\n", keliling(p, l));

	printf("Terima kasih sudah menggunakan program ini!\n");
	printf("Program akan ditutup dalam 3 detik!");
	sleep(3); // jeda selama 3 detik sebelum program ditutup
}