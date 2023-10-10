// Muhammad Rayhan Faridh
// 222212766
// 2KS1

// Versi Array
// Description
/*
	Program ini dibuat sesuai dengan modul 7, namun nomor 1-3 digabungkan
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node {
	char nama[25];
	int alp; // alpro
	int kal; // kalkulus
} Tnode;

// Set as global variable
#define MAX 5 // maksimal antrian
Tnode mhs[MAX];
int front = -1, rear = -1; // inisiasi awal menandakan antrian kosong
bool errFlag = false; // variabel untuk menandai apakah pesan error sudah ditampilkan, jika sudah tidak ditampilkan berulang kali

// Data dimasukkan ke dalam urutan dari nilai alpro terbesar, jika nilai alpro sama akan diurutkan berdasar nilai kalkulus
void enqueue(char nama[], int alp, int kal) {
	if (rear == MAX - 1) {
		if (!errFlag) {
			printf("Antrian penuh, maksimal 5!\n\n");
			errFlag = true;
		}
		return;
	}
	if (front == -1)
		front = 0;

	int cursor = rear;
	while (cursor >= front && (alp > mhs[cursor].alp || (alp == mhs[cursor].alp && kal > mhs[cursor].kal))) {
		mhs[cursor + 1] = mhs[cursor];
		cursor--;
	}

	strcpy(mhs[cursor + 1].nama, nama);
	mhs[cursor + 1].alp = alp;
	mhs[cursor + 1].kal = kal;
	rear++;
}

void display() {
	printf("Isi antrian:\n");
	for (int i = front; i <= rear; i++) {
		printf("Nama: %s, Nilai Alpro: %d, Nilai Kalkulus: %d\n", mhs[i].nama, mhs[i].alp, mhs[i].kal);
	}
}

void main() {
	enqueue("Eki", 55, 50);
	enqueue("Adni", 60, 30);
	enqueue("Eko", 60, 80);
	enqueue("Budi", 57, 27);
	enqueue("Danar", 90, 80);
	enqueue("Eka", 75, 85); // tidak akan tercetak, namun menampilkan pesan bahwa antrian sedang penuh

	display();
}