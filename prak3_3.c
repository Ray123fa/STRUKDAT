// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>

struct Koordinat
{
	int x;
	int y;
};

void main()
{
	struct Koordinat *tKoord, Koord;
	// input titik koordinat sesuai kehendak pengguna
	printf("Masukkan titik koordinat X: ");
	scanf("%d", &Koord.x);
	printf("Masukkan titik koordinat Y: ");
	scanf("%d", &Koord.y);

	tKoord = &Koord; // pointer tKoord menunjuk struct Koord

	// tanda -> berguna untuk mengakses elemen dari struct melalui pointer
	printf("\nKoordinat X: %d\n", tKoord->x);
	printf("Koordinat Y: %d\n", tKoord->y);

	// jika tanpa tanda ->, untuk mengakses elemen dari struct seperti berikut
	// printf("\nKoordinat X: %d\n", (*tKoord).x);
	// printf("Koordinat Y: %d\n", (*tKoord).y);
}