// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>

struct Students
{
	char nim[11], nama[25], kls[4];
	int nilai[3];
};

void input(struct Students student[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("Data mahasiswa ke-%d\n", i + 1);
		printf("Masukkan NIM: ");
		scanf("%s", student[i].nim);
		printf("Masukkan nama: ");
		getchar();
		scanf("%[^\n]s", student[i].nama);
		printf("Masukkan kelas: ");
		getchar();
		scanf("%s", student[i].kls);

		printf("Masukkan nilai Tugas, UTS, dan UAS secara berurutan\n");
		// nilai[0] -> Tugas
		// nilai[1] -> UTS
		// nilai[2] -> UAS
		for (int j = 0; j < 3; j++)
		{
			printf("[%d] -> ", j);
			scanf("%d", &student[i].nilai[j]);
		}
		printf("\n");
	}
}

void display(struct Students student[], int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("Data mahasiswa ke-%d\n", i + 1);
		printf("NIM: %s\n", student[i].nim);
		printf("Nama: %s\n", student[i].nama);
		printf("Kelas: %s\n", student[i].kls);
		printf("Nilai Tugas=%d, UTS=%d, dan UAS=%d\n\n", student[i].nilai[0], student[i].nilai[1], student[i].nilai[2]);
	}
}

void main()
{
	struct Students student[5];

	input(student, 5);
	display(student, 5);
}