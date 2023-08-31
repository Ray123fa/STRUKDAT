// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <unistd.h> // agar bisa menggunakan fungsi sleep

void main()
{
	char nim[11], nama[20];
	int kuis, uts, uas;

	printf("Selamat Datang!\nProgram Menghitung Nilai Akhir\n\n");

	printf("NIM: ");
	scanf("%s", nim);
	printf("Nama: ");
	getchar();
	scanf("%[^\n]s", nama);
	printf("Nilai Kuis: ");
	scanf("%d", &kuis);
	printf("Nilai UTS: ");
	scanf("%d", &uts);
	printf("Nilai UAS: ");
	scanf("%d", &uas);

	float n_akhir = 0.2 * kuis + 0.3 * uts + 0.5 * uas;

	sleep(1);
	printf("\nNIM: %s\n", nim);
	printf("Nama: %s\n", nama);
	printf("Nilai Kuis: %d\n", kuis);
	printf("Nilai UTS: %d\n", uts);
	printf("Nilai UAS: %d\n", uas);
	printf("Nilai Akhir: %.2f\n\n", n_akhir);

	printf("Terima kasih sudah menggunakan program ini!\n");
	printf("Program akan ditutup dalam 3 detik!");
	sleep(3); // jeda selama 3 detik sebelum program ditutup
}