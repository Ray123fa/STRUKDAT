// Muhammad Rayhan Faridh
// 222212766
// 2KS1

// Versi Linklist
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
	struct node* next;
} Tnode;
typedef Tnode* ptrnode;

typedef struct queue {
	int count;
	ptrnode front;
	ptrnode rear;
	bool errFlag; // variabel untuk menandai apakah pesan error sudah ditampilkan, jika sudah tidak ditampilkan berulang kali
} Tqueue;
typedef Tqueue* ptrqueue;

void init(ptrqueue q) {
	q->front = q->rear = NULL;
	q->count = 0;
}

ptrnode createnode(char nama[], int alp, int kal) {
	ptrnode newmhs = (ptrnode)malloc(sizeof(Tnode));
	strcpy(newmhs->nama, nama);
	newmhs->alp = alp;
	newmhs->kal = kal;
	newmhs->next = NULL;

	return newmhs;
}

bool isempty(ptrqueue q) {
	return (q->count == 0);
}

bool isfull(ptrqueue q) {
	return (q->count == 5); // 5 adalah batas maksimum antrian
}

// Data dimasukkan ke dalam urutan dari nilai alpro terbesar, jika nilai alpro sama akan diurutkan berdasar nilai kalkulus
void enqueue(ptrqueue q, char nama[], int alp, int kal) {
	ptrnode newmhs = createnode(nama, alp, kal);

	if (isempty(q)) {
		q->front = q->rear = newmhs;
		q->count = 1;
	}
	else if (!isfull(q)) {
		if (alp > q->front->alp || (alp == q->front->alp && kal >= q->front->kal)) {
			newmhs->next = q->front;
			q->front = newmhs;
		}
		else {
			ptrnode cursor = q->front;
			ptrnode previous = NULL;

			// Cari posisi cursor agar sesuai dengan kriteria
			while (cursor != NULL && (alp < cursor->alp || (alp == cursor->alp && kal <= cursor->kal))) {
				previous = cursor;
				cursor = cursor->next;
			}

			newmhs->next = cursor;
			if (cursor == NULL) {
				q->rear = newmhs;
			}
			if (previous != NULL) {
				previous->next = newmhs;
			}
		}
		q->count++;
	}
	else if (!q->errFlag) {
		printf("Antrian penuh, maksimal 5!\n\n");
		q->errFlag = true;
	}
}

void display(ptrqueue q) {
	if (q->front == NULL) {
		printf("Antrian kosong\n");
		return;
	}
	else {
		printf("Isi Queue:\n");
		ptrnode cursor = q->front;
		while (cursor != NULL) {
			printf("Nama: %s, Nilai Alpro: %d, Nilai Kalkulus: %d\n", cursor->nama, cursor->alp, cursor->kal);
			cursor = cursor->next;
		}
	}
}

void main() {
	ptrqueue antrian = (ptrqueue)malloc(sizeof(Tqueue));
	init(antrian);

	enqueue(antrian, "Eki", 55, 50);
	enqueue(antrian, "Adni", 60, 30);
	enqueue(antrian, "Eko", 60, 80);
	enqueue(antrian, "Budi", 57, 27);
	enqueue(antrian, "Danar", 90, 80);
	enqueue(antrian, "Eka", 75, 85); // tidak akan tercetak, namun menampilkan pesan bahwa antrian sedang penuh

	display(antrian); // untuk menampilkan antrian
}