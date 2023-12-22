// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
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