// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>

int main()
{
	int x = 10, y = 20;
	{
		printf("x = %d, y = %d\n", x, y); // nilai x dan y tetap
		{
			int y = 40;												// inisiasi ulang y menjadi 40 (var lokal)
			x++;															// nilai x menjadi 11 (karena tidak diinisiasi ulang maka berlaku pada/setelah blok ini)
			y++;															// nilai y menjadi 41 (var lokal karena ada inisiasi ulang)
			printf("x = %d, y = %d\n", x, y); // nilai x dan y yang tercetak adalah 11 dan 41
		}
		printf("x = %d, y = %d\n", x, y); // nilai x dan y yang tercetak adalah 11 dan 20
	}
	return 0;
}