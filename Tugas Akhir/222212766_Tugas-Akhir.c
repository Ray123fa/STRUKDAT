// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// I. Deklarasi Primary Key
static int pkey = 1;

// II. Deklarasi Awal Sub-Program
// 1. Definisi Node & Linked List

// A. Contact Book
// A1. Node Contact Book
struct node_CB
{
	int pkey;
	char name[30];
	int age;
	char sex;
	char telpNo[15];
	char email[40];
	struct node_CB *next;
};
typedef struct node_CB *ptrCB;

// A2. SLL Contact Book
struct SLL_CB
{
	ptrCB head;
	unsigned int size;
};
typedef struct SLL_CB *ptrSLL_CB;

// B. Koneksi
// B1. Node Koneksi
struct node_Conn
{
	int pkey;
	struct node_Conn *next;
};
typedef struct node_Conn *ptrConnect;

// B2. SLL Koneksi
struct SLL_Conn
{
	ptrConnect head;
	unsigned int size;
};
typedef struct SLL_Conn *ptrSLL_Conn;

// C. Adjaceny List
// C1. Node Adjacency List
struct node_AdjList
{
	ptrSLL_Conn datalist;
	struct node_AdjList *next;
};
typedef struct node_AdjList *ptrAdjList;

// C2. SLL Adjacency List
struct SLL_AdjList
{
	ptrAdjList head;
	unsigned int size;
};
typedef struct SLL_AdjList *ptrSLL_AdjList;

// D. Hash Table
// D1. Node Hash Table
struct node_Hash
{
	int pkey;
	ptrCB data;
	struct node_Hash *next;
};
typedef struct node_Hash *ptrHash;

// D2. SLL Hash Table
struct SLL_Hash
{
	ptrHash head;
	unsigned int size;
};
typedef struct SLL_Hash *ptrSLL_Hash;

// 2. Manipulate Node & Linked List

// A. Contact Book
// A1. Node Contact Book

/**
 * Membuat node baru untuk Contact Book.
 *
 * @param nama Nama
 * @param umur Umur
 * @param jk Jenis kelamin
 * @param noTelp Nomor telepon
 * @param email Email
 * @return Pointer ke node baru yang telah dibuat.
 */
ptrCB createNode_CB(char nama[], unsigned umur, char jk, char noTelp[], char email[])
{
	ptrCB tempNode = (ptrCB)malloc(sizeof(struct node_CB));

	tempNode->pkey = pkey++;
	strcpy(tempNode->name, nama);
	tempNode->age = umur;
	tempNode->sex = jk;
	strcpy(tempNode->telpNo, noTelp);
	strcpy(tempNode->email, email);
	tempNode->next = NULL;

	return tempNode;
}

/**
 * Mencetak data dari node Contact Book.
 *
 * @param currNode Pointer ke node yang akan dicetak.
 */
void printNode_CB(ptrCB currNode)
{
	printf("= Nama            : %-26s=\n", currNode->name);
	printf("= Umur            : %-26u=\n", currNode->age);
	printf("= Jenis Kelamin   : %-26c=\n", currNode->sex);
	printf("= Nomor Telepon   : %-26s=\n", currNode->telpNo);
	printf("= Alamat Email    : %-26s=\n", currNode->email);
}

// A2. SLL Contact Book

/**
 * Inisialisasi linked list contact book.
 *
 * Fungsi ini digunakan untuk menginisialisasi linked list contact book.
 *
 * @param tmpList Pointer ke linked list contact book yang akan diinisialisasi.
 */
void init_SLL_CB(ptrSLL_CB tmpList)
{
	tmpList->head = NULL;
	tmpList->size = 0;
}

/**
 * Fungsi ini digunakan untuk menyisipkan node currNode ke dalam linked list currList.
 * Selain itu, fungsi ini juga mengupdate adjacency list currAdjList dan hash table currHashTable.
 *
 * @param currList Pointer ke linked list yang akan dimodifikasi.
 * @param currNode Pointer ke node yang akan disisipkan.
 * @param currAdjList Pointer ke adjacency list yang akan diupdate.
 * @param currHashTable Pointer ke hash table yang akan diupdate.
 */
void SLL_CB_insert(ptrSLL_CB currList, ptrCB currNode, ptrSLL_AdjList currAdjList, ptrSLL_Hash currHashTable)
{
	if (currList->head == NULL)
	{
		currList->head = currNode;
		currList->size++;
	}
	else
	{
		ptrCB cursor = currList->head;

		while (cursor->next != NULL)
			cursor = cursor->next;

		cursor->next = currNode;
		currNode->next = NULL;
		currList->size++;
	}

	SLL_AdjList_insertTail(currAdjList, currNode->pkey);
	SLL_Hash_insertTail(currHashTable, currNode->pkey, currNode);
}

/**
 * Menghapus elemen pertama (head) dari linked list contact book.
 *
 * @param currList Pointer ke linked list contact book yang akan diubah.
 */
void SLL_CB_delHead(ptrSLL_CB currList)
{
	if (currList->size == 0)
		printf("Daftar Kontak Kosong!\n");
	else if (currList->size == 1)
	{
		ptrCB tempNode = currList->head;

		currList->head = NULL;
		currList->size = 0;

		free(tempNode);
	}
	else
	{
		ptrCB tempNode = currList->head;

		currList->head = tempNode->next;
		tempNode->next = NULL;
		currList->size--;

		free(tempNode);
	}
}

/**
 * Menghapus elemen terakhir (tail) dari linked list contact book.
 *
 * @param currList Pointer ke linked list contact book yang akan diubah.
 */
void SLL_CB_delTail(ptrSLL_CB currList)
{
	if (currList->size == 0)
		printf("Daftar Kontak Kosong!\n");

	if (currList->size == 1)
	{
		ptrCB tempNode = currList->head;

		currList->head = NULL;
		currList->size = 0;

		free(tempNode);
	}
	else
	{
		ptrCB tempNode = currList->head;
		ptrCB prev = NULL;

		while (tempNode->next != NULL)
		{
			prev = tempNode;
			tempNode = tempNode->next;
		}

		prev->next = NULL;
		currList->size--;

		free(tempNode);
	}
}

/**
 * Menghapus node dalam linked list berdasarkan nama pada contact book.
 *
 * @param currList Pointer ke linked list contact book.
 * @param nama Nama yang ingin dihapus dari contact book.
 */
void SLL_CB_delName(ptrSLL_CB currList, char nama[])
{
	if (strcmp(currList->head->name, nama) == 0)
		SLL_CB_delHead(currList);
	else
	{
		ptrCB cursor = currList->head;
		ptrCB tempNode = NULL;
		int count = 0;

		while (cursor != NULL && strcmp(cursor->name, nama) != 0)
		{
			tempNode = cursor;
			cursor = cursor->next;
			count++;
		}

		if (count == currList->size)
		{
			if (strcmp(tempNode->name, nama) != 0)
				printf("Data tidak ditemukan sehingga tidak ada yang dihapus.\n");
			else
				SLL_CB_delTail(currList);
		}
		else
		{
			tempNode->next = cursor->next;
			cursor->next = NULL;
			currList->size--;
			free(cursor);
		}
	}
}

// B. Koneksi
// B1. Node Koneksi

/**
 * Membuat dan menginisialisasi node baru untuk contact book.
 *
 * @param pkey Kunci utama untuk node contact book.
 * @return Pointer ke node contact book yang baru dibuat.
 */
ptrConnect createNode_Conn(int pkey)
{
	ptrConnect tempNode = (ptrConnect)malloc(sizeof(struct node_Conn));

	tempNode->pkey = pkey;
	tempNode->next = NULL;

	return tempNode;
}

// B2. SLL Koneksi

/**
 * Inisialisasi linked list koneksi.
 *
 * Fungsi ini digunakan untuk menginisialisasi linked list koneksi.
 *
 * @param tmpList Pointer ke linked list koneksi yang akan diinisialisasi.
 */
void init_SLL_Connect(ptrSLL_Conn tmpList)
{
	tmpList->head = NULL;
	tmpList->size = 0;
}

/**
 * Menambahkan elemen baru ke akhir daftar linked list.
 *
 * @param currList Pointer ke daftar linked list yang akan dimodifikasi.
 * @param pkey Nilai kunci untuk elemen baru yang akan ditambahkan.
 */
void SLL_Conn_insertTail(ptrSLL_Conn currList, int pkey)
{
	ptrConnect tempNode = createNode_Conn(pkey);

	if (currList->head == NULL)
	{
		currList->head = tempNode;
		currList->size++;
	}
	else
	{
		ptrConnect cursor = currList->head;

		while (cursor->next != NULL)
			cursor = cursor->next;

		cursor->next = tempNode;
		currList->size++;
	}
}

/**
 * Menghapus elemen pertama (head) dari linked list koneksi.
 *
 * @param currList Pointer ke linked list koneksi yang akan diubah.
 */
void SLL_Conn_delHead(ptrSLL_Conn currList)
{
	if (currList->size == 0)
		printf("Koneksi kosong.\n");
	else if (currList->size == 1)
	{
		ptrConnect tempNode = currList->head;

		currList->head = NULL;
		currList->size = 0;

		free(tempNode);
	}
	else
	{
		ptrConnect tempNode = currList->head;

		currList->head = tempNode->next;
		tempNode->next = NULL;
		currList->size--;

		free(tempNode);
	}
}

/**
 * Menghapus elemen terakhir (tail) dari linked list koneksi.
 *
 * @param currList Pointer ke linked list koneksi yang akan diubah.
 */
void SLL_Conn_delTail(ptrSLL_Conn currList)
{
	if (currList->size == 0)
		printf("Koneksi kosong.\n");
	else if (currList->size == 1)
	{
		ptrConnect tempNode = currList->head;

		currList->head = NULL;
		currList->size = 0;

		free(tempNode);
	}
	else
	{
		ptrConnect tempNode = currList->head;
		ptrConnect prev = NULL;

		while (tempNode->next != NULL)
		{
			prev = tempNode;
			tempNode = tempNode->next;
		}

		prev->next = NULL;
		currList->size--;

		free(tempNode);
	}
}

/**
 * Menghapus elemen dalam linked list koneksi berdasarkan nilai kunci.
 *
 * @param currList Pointer ke linked list koneksi yang akan diubah.
 * @param pkey Nilai kunci yang ingin dihapus dari linked list koneksi.
 */
void SLL_Conn_delPkey(ptrSLL_Conn currList, int pkey)
{
	ptrConnect cursor = currList->head;

	if (cursor->pkey == pkey)
		SLL_Conn_delHead(currList);
	else
	{
		ptrConnect tempNode = NULL;
		int count = 0;

		while (cursor != NULL && cursor->pkey != pkey)
		{
			tempNode = cursor;
			cursor = cursor->next;
			count++;
		}

		if (count == currList->size)
		{
			if (tempNode->pkey != pkey)
				printf("Data tidak ditemukan sehingga tidak ada yang dihapus.\n");
			else
				SLL_Conn_delTail(currList);
		}
		else
		{
			tempNode->next = cursor->next;
			cursor->next = NULL;
			currList->size--;
			free(cursor);
		}
	}
}

// C. Adjacency List
// C1. Node Adjacency List

/**
 * Inisialisasi node dalam adjacency list.
 *
 * @param currAdjListNode Pointer ke node adjacency list yang akan diinisialisasi.
 */
void init_nodeAdjList(ptrAdjList currAdjListNode)
{
	currAdjListNode->datalist = NULL;
	currAdjListNode->next = NULL;
}

/**
 * Membuat node baru untuk adjacency list.
 *
 * @param src Sumber node yang akan ditambahkan ke adjacency list.
 * @return Pointer ke node adjacency list yang baru dibuat.
 */
ptrAdjList createNode_Adjlist(int src)
{
	ptrSLL_Conn tempSLL = (ptrSLL_Conn)malloc(sizeof(struct SLL_Conn));
	init_SLL_Connect(tempSLL);
	SLL_Conn_insertTail(tempSLL, src);

	ptrAdjList tempAdjlist = (ptrAdjList)malloc(sizeof(struct node_AdjList));
	init_nodeAdjList(tempAdjlist);
	tempAdjlist->datalist = tempSLL;

	return tempAdjlist;
}

// C2. SLL Adjacency List

/**
 * Fungsi ini digunakan untuk menginisialisasi linked list adjacency list.
 *
 * @param currAdjList Pointer ke linked list adjacency list yang akan diinisialisasi.
 */
void init_SLL_AdjList(ptrSLL_AdjList currAdjList)
{
	currAdjList->head = NULL;
	currAdjList->size = 0;
}

/**
 * Menyisipkan node baru pada bagian akhir (tail) dari SLL adjacency list.
 *
 * @param currAdjList Pointer ke SLL adjacency list.
 * @param src Nilai simpul yang akan disisipkan.
 */
void SLL_AdjList_insertTail(ptrSLL_AdjList currAdjList, int src)
{
	ptrAdjList tempNode = createNode_Adjlist(src);

	if (currAdjList->head == NULL)
	{
		currAdjList->head = tempNode;
		currAdjList->size++;
	}
	else
	{
		ptrAdjList cursor = currAdjList->head;

		while (cursor->next != NULL)
			cursor = cursor->next;

		cursor->next = tempNode;
		currAdjList->size++;
	}
}

/**
 * Menyisipkan koneksi baru antara dua node pada SLL adjacency list.
 *
 * @param currAdjList Pointer ke SLL adjacency list.
 * @param src Indeks node sumber.
 * @param dest Indeks node tujuan.
 */
void SLL_AdjList_insertConnect(ptrSLL_AdjList currAdjList, int src, int dest)
{
	ptrAdjList cursor = currAdjList->head;

	while (cursor != NULL && cursor->datalist->head->pkey != src)
		cursor = cursor->next;

	SLL_Conn_insertTail(cursor->datalist, dest);
}

/**
 * Menghapus koneksi antara dua node pada SLL adjacency list.
 *
 * @param currAdjList Pointer ke SLL adjacency list.
 * @param src Indeks node sumber.
 * @param dest Indeks node tujuan.
 */
void SLL_AdjList_delConnect(ptrSLL_AdjList currAdjList, int src, int dest)
{
	ptrAdjList cursor = currAdjList->head;

	while (cursor != NULL && cursor->datalist->head->pkey != src)
		cursor = cursor->next;

	SLL_Conn_delPkey(cursor->datalist, dest);
}

// D. Hash Table
// D1. Node Hash Table

/**
 * Membuat node baru untuk hash table.
 *
 * @param pkey Nilai kunci untuk node hash table.
 * @param currNode Pointer ke node contact book.
 * @return Pointer ke node hash table yang baru dibuat.
 */
ptrHash createNode_Hash(int pkey, ptrCB currNode)
{
	ptrHash temp = (ptrHash)malloc(sizeof(struct node_Hash));
	ptrCB copiedNode = (ptrCB)malloc(sizeof(struct node_CB));

	copiedNode->pkey = currNode->pkey;
	strcpy(copiedNode->name, currNode->name);
	copiedNode->age = currNode->age;
	copiedNode->sex = currNode->sex;
	strcpy(copiedNode->telpNo, currNode->telpNo);
	strcpy(copiedNode->email, currNode->email);
	copiedNode->next = NULL;

	temp->pkey = pkey;
	temp->data = copiedNode;
	temp->next = NULL;

	return temp;
}

// D2. SLL Hash Table

/**
 * Fungsi ini digunakan untuk menginisialisasi linked list hash table.
 *
 * @param currHashTable Pointer ke linked list hash table yang akan diinisialisasi.
 */
void init_SLL_Hash(ptrSLL_Hash currHashTable)
{
	currHashTable->head = NULL;
	currHashTable->size = 0;
}

/**
 * Menyisipkan node baru ke dalam linked list yang terhubung dengan hash table.
 *
 * @param currHashTable Pointer ke hash table yang ingin dimodifikasi.
 * @param pkey Kunci untuk menentukan posisi linked list yang akan dimasukkan node baru.
 * @param currNode Pointer ke node yang akan disisipkan.
 */
void SLL_Hash_insertTail(ptrSLL_Hash currHashTable, int pkey, ptrCB currNode)
{
	ptrHash newHashNode = createNode_Hash(pkey, currNode);

	if (currHashTable->head == NULL)
	{
		currHashTable->head = newHashNode;
		currHashTable->size++;
	}
	else
	{
		ptrHash cursor = currHashTable->head;

		while (cursor->next != NULL)
			cursor = cursor->next;

		cursor->next = newHashNode;
		newHashNode->next = NULL;
		currHashTable->size++;
	}
}

ptrCB SLL_Hash_getNodeCB(ptrSLL_Hash currHashTable, int pkey)
{
	ptrHash cursor = currHashTable->head;

	while (cursor != NULL)
	{
		if (cursor->pkey == pkey)
			return cursor->data;

		cursor = cursor->next;
	}

	return NULL;
}

// 3. Menu

/**
 * Fungsi ini digunakan untuk memasukkan data kontak ke dalam daftar kontak.
 *
 * @param contactList Pointer ke head dari linked list daftar kontak.
 * @param connectionList Pointer ke head dari linked list daftar koneksi antar kontak.
 * @param idxKey Pointer ke head dari linked list daftar indeks kunci.
 */
void insertContact(ptrSLL_CB contactList, ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey)
{
	char nama[30];
	unsigned umur;
	char sex;
	char noTelp[13];
	char email[40];

	printf("==================================================\n");
	printf("%-19sTambah Kontak%18s\n", "=", "=");
	printf("==================================================\n");
	printf("= Nama                : ");
	scanf(" %30[^\n]", nama);
	printf("= Umur                : ");
	scanf("%u", &umur);
	printf("= Jenis Kelamin [L/P] : ");
	scanf(" %c", &sex);
	printf("= Nomor Telepon       : ");
	scanf(" %13s", noTelp);
	printf("= Alamat Email        : ");
	scanf(" %40s", email);
	printf("==================================================\n");

	SLL_CB_insert(contactList, createNode_CB(nama, umur, sex, noTelp, email), connectionList, idxKey);
	contactList->head = mergeSortName(contactList->head, true);

	sleep(1);
	system("cls");
	printf("Data berhasil ditambahkan!\n\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

/**
 * Fungsi untuk menghapus kontak dari daftar kontak.
 *
 * @param contactList Pointer ke head dari linked list kontak.
 * @param connectionList Pointer ke head dari linked list koneksi antar kontak.
 * @param idxKey Pointer ke head dari linked list indeks kunci.
 */
void delContact(ptrSLL_CB contactList, ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey)
{
	char nama[30];

	printf("==================================================\n");
	printf("%-19sHapus Kontak%19s\n", "=", "=");
	printf("==================================================\n");
	printf("= Masukkan nama: ");
	scanf(" %30[^\n]", nama);
	printf("==================================================\n\n");

	contactList->head = mergeSortName(contactList->head, true);
	ptrCB temp = binarySearchName(contactList, nama);

	sleep(1);
	if (temp == NULL)
		printf("Data tidak ditemukan, tidak ada yang dihapus!\n");
	else
	{
		SLL_CB_deleteName(contactList, temp->name);
		printf("Data Berhasil dihapus!\n");
	}

	printf("\nTekan untuk melanjutkan...");
	getchar();
	system("cls");
}

/**
 * Menampilkan daftar kontak.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 */
void displayContacts(ptrSLL_CB contactList)
{
	ptrCB cursor = contactList->head;

	printf("==================================================\n");
	printf("%-18sDaftar Kontak%18s\n", "=", "=");
	printf("==================================================\n");
	printf("= Jumlah kontak: %-32d=\n", contactList->size);

	while (cursor != NULL)
	{
		printf("==================================================\n");
		printNode_CB(cursor);
		cursor = cursor->next;
	}

	printf("==================================================\n\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

/**
 * Mengurutkan daftar kontak berdasarkan nama.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 */
void sortContactByName(ptrSLL_CB contactList)
{
	int choose;

	printf("==================================================\n");
	printf("%-18sUrutkan Kontak%18s\n", "=", "=");
	printf("==================================================\n");
	printf("= 1. Ascending  (A to Z) %-24s=\n", " ");
	printf("= 2. Descending (Z to A) %-24s=\n", " ");
	printf("==================================================\n");
	printf("= Pilihan :                                      =\n");
	printf("==================================================\n");

	getchar();
	gotoxy(12, 6);
	scanf("%d", &choose);

	getchar();
	while (choose != 1 && choose != 2)
	{
		gotoxy(12, 6);
		printf(" ");
		gotoxy(12, 6);
		scanf("%d", &choose);
		getchar();
	}
	contactList->head = mergeSortName(contactList->head, (bool)(2 - choose));

	printf("==================================================\n\n");
	if (choose == 1)
		printf("Kontak berhasil diurutkan secara ascending berdasarkan nama.\n");
	else
		printf("Kontak berhasil diurutkan secara descending berdasarkan nama.\n");

	printf("\nTekan untuk melanjutkan...");
	getchar();
	system("cls");
}

/**
 * Fungsi ini digunakan untuk mencari kontak berdasarkan nama pada linked list.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 */
void searchByName(ptrSLL_CB contactList)
{
	char nama[30];

	printf("==================================================\n");
	printf("%-20sCari Kontak%19s\n", "=", "=");
	printf("==================================================\n");
	printf("= Masukkan nama:                                 =\n");
	printf("==================================================\n");

	getchar();
	gotoxy(17, 3);
	scanf(" %30[^\n]", nama);

	contactList->head = mergeSortName(contactList->head, true);
	ptrCB temp = binarySearchName(contactList, nama);

	sleep(1);
	system("cls");

	printf("==================================================\n");
	printf("%-20s H A S I L %19s\n", "=", "=");
	printf("==================================================\n");

	if (temp != NULL)
		printNode_CB(temp);
	else
		printf("Data tidak ditemukan!\n");

	printf("==================================================\n\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

/**
 * Dipanggil ketika fungsi editContact dieksekusi.
 * Dalam fungsi ini diperlukan input dari user untuk mengubah data kontak berdasar choice yang telah user berikan pada fungsi editContact.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 * @param choice Pilihan yang telah user berikan pada fungsi editContact.
 * @param pkey Kunci utama dari node yang akan diubah.
 * @param idxKey Pointer ke linked list yang berisi indeks kunci.
 */
void handlingEditContact(ptrSLL_CB contactList, int choice, int pkey, ptrSLL_Hash idxKey)
{
	char input[40]; // Nama/Email/No. Telp
	int age;
	char sex; // L/P

	ptrCB cursor = contactList->head;
	while (cursor->next != NULL && cursor->pkey != pkey)
		cursor = cursor->next;

	printf("Masukkan data baru: ");
	switch (choice)
	{
	case 1:
		scanf(" %30[^\n]", input);

		strcpy(cursor->name, input);
		strcpy(SLL_Hash_getNodeCB(idxKey, pkey)->name, input);
		break;
	case 2:
		scanf("%d", &age);

		cursor->age = age;
		SLL_Hash_getNodeCB(idxKey, pkey)->age = age;
		break;
	case 3:
		scanf("%c", &sex);

		cursor->sex = sex;
		SLL_Hash_getNodeCB(idxKey, pkey)->sex = sex;
		break;
	case 4:
		scanf(" %13s", input);

		strcpy(cursor->telpNo, input);
		strcpy(SLL_Hash_getNodeCB(idxKey, pkey)->telpNo, input);
		break;
	case 5:
		scanf(" %40s", input);

		strcpy(cursor->email, input);
		strcpy(SLL_Hash_getNodeCB(idxKey, pkey)->email, input);
	}
}

/**
 * Fungsi ini merupakan interface untuk mengedit kontak.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 * @param idxKey Pointer ke linked list yang berisi indeks kunci.
 */
void editContact(ptrSLL_CB contactList, ptrSLL_Hash idxKey)
{
	char nama[30];
	int choice;

	printf("==================================================\n");
	printf("%-20sEdit Kontak%19s\n", "=", "=");
	printf("==================================================\n");
	printf("= Masukkan nama: %33s", "=");
	printf("==================================================\n\n");

	getchar();
	gotoxy(17, 3);
	scanf(" %30[^\n]", nama);

	ptrCB temp = binarySearchName(contactList, nama);

	if (temp != NULL)
	{
		printf("= Pilih data yang ingin diubah: %17s=\n", " ");
		printf("= 1. Nama %39s=\n", " ");
		printf("= 2. Umur %39s=\n", " ");
		printf("= 3. Jenis Kelamin %30s=\n", " ");
		printf("= 4. Nomor Telepon %30s=\n", " ");
		printf("= 5. Alamat Email %31s=\n", " ");
		printf("==================================================\n");
		printf("= Pilihan: %38s=\n", " ");
		printf("==================================================\n");

		gotoxy(12, 12);
		scanf("%d", &choice);
		getchar();
		while (choice < 1 || choice > 5)
		{
			gotoxy(12, 12);
			printf(" ");
			gotoxy(12, 12);
			scanf("%d", &choice);
			getchar();
		}

		printf("\n");
		handlingEditContact(contactList, choice, temp->pkey, idxKey);
	}
	else
		printf("Data tidak ditemukan!\n");

	printf("==================================================\n\n");
	printf("Tekan untuk melanjutkan...");
	getchar();
	system("cls");
}

// 4. Sort and Search

// Merge Sort by Name
/**
 * Fungsi untuk menggabungkan dua linked list yang sudah diurutkan secara terurut.
 *
 * @param _1node Pointer ke node pertama dari linked list pertama.
 * @param _2node Pointer ke node pertama dari linked list kedua.
 * @param isAsc Boolean yang menentukan apakah pengurutan dilakukan secara ascending (true) atau descending (false).
 * @return Pointer ke node pertama dari linked list hasil penggabungan.
 */
ptrCB handlingMergeSort(ptrCB _1node, ptrCB _2node, bool isAsc)
{
	ptrCB merged = (ptrCB)malloc(sizeof(struct node_CB));
	ptrCB cursor = (ptrCB)malloc(sizeof(struct node_CB));

	merged = cursor;
	if (isAsc)
	{
		while (_1node != NULL && _2node != NULL)
		{
			if (strcmp(_1node->name, _2node->name) < 0)
			{
				cursor->next = _1node;
				_1node = _1node->next;
			}
			else
			{
				cursor->next = _2node;
				_2node = _2node->next;
			}
			cursor = cursor->next;
		}
	}
	else
	{
		while (_1node != NULL && _2node != NULL)
		{
			if (strcmp(_1node->name, _2node->name) > 0)
			{
				cursor->next = _1node;
				_1node = _1node->next;
			}
			else
			{
				cursor->next = _2node;
				_2node = _2node->next;
			}
			cursor = cursor->next;
		}
	}

	while (_1node != NULL)
	{
		cursor->next = _1node;
		_1node = _1node->next;
		cursor = cursor->next;
	}

	while (_2node != NULL)
	{
		cursor->next = _2node;
		_2node = _2node->next;
		cursor = cursor->next;
	}

	return merged->next;
}

/**
 * Fungsi ini digunakan untuk mencari dan mengembalikan pointer ke tengah dari linked list contact book.
 *
 * @param head Pointer ke head dari linked list contact book.
 * @return Pointer ke tengah dari linked list contact book.
 */
ptrCB mid_SLL_CB(ptrCB head)
{
	if (head == NULL)
		return head;

	ptrCB slow = head;
	ptrCB fast = head->next;

	while (slow->next != NULL && (fast->next != NULL && fast->next->next != NULL))
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

/**
 * Mengurutkan daftar kontak dalam buku kontak berdasarkan nama menggunakan algoritma Merge Sort.
 *
 * @param head Pointer ke kepala (head) dari buku kontak yang akan diurutkan.
 * @param isAsc Menentukan apakah pengurutan dilakukan secara ascending (true) atau descending (false).
 * @return Pointer ke kepala (head) dari buku kontak yang sudah diurutkan.
 */
ptrCB mergeSortName(ptrCB head, bool isAsc)
{
	if (head == NULL || head->next == NULL)
		return head;

	ptrCB mid = mid_SLL_CB(head);
	ptrCB head2 = mid->next;
	mid->next = NULL;

	ptrCB left = mergeSortName(head, isAsc);
	ptrCB right = mergeSortName(head2, isAsc);

	return handlingMergeSort(left, right, isAsc);
}

// Binary Search by Name
/**
 * Fungsi middle digunakan untuk mencari pointer ke tengah dari dua pointer contact book.
 *
 * @param start Pointer ke awal contact book.
 * @param last Pointer ke akhir contact book.
 * @return Pointer ke tengah dari dua pointer contact book.
 */
ptrCB middle(ptrCB start, ptrCB last)
{
	if (start == NULL)
		return NULL;

	ptrCB slow = start;
	ptrCB fast = start->next;

	while (fast != last)
	{
		fast = fast->next;
		if (fast != last)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	return slow;
}

/**
 * Fungsi untuk melakukan pencarian biner berdasarkan nama pada buku kontak.
 *
 * @param contactList Pointer ke linked list buku kontak.
 * @param nama Nama yang akan dicari.
 * @return Pointer ke node dengan nama yang sesuai, atau NULL jika tidak ditemukan.
 */
ptrCB binarySearchName(ptrSLL_CB contactList, char nama[])
{
	ptrCB start = contactList->head;
	ptrCB last = NULL;

	do
	{
		ptrCB mid = middle(start, last);

		if (mid == NULL)
			return NULL;

		if (strcmp(mid->name, nama) == 0)
			return mid;
		else if (strcmp(mid->name, nama) < 0)
			start = mid->next;
		else
			last = mid;
	} while (last == NULL || last != start);

	return NULL;
}
