#include <stdio.h>

void main()
{
	int num[5];
	int count = 5;
	long sum = 0;
	float avg = 0.0;

	printf("Masukkan 5 angka!\n");
	for (int i = 0; i < count; i++)
	{
		printf("%d> ", i + 1);
		scanf("%d", &num[i]);
		sum += num[i];
	}
	avg = (float)sum / count; // use casting operator

	printf("Jumlah adalah %d\n", sum);
	printf("Rata-rata adalah %.2f", avg);
}