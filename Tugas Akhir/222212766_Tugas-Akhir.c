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
	char telNo[15];
	char email[40];
	struct node_CB *next;
};
typedef struct node_CB *ptrCB;

// A2. Single Linked List Contact Book
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

// B2. Single Linked List Koneksi
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

// C2. Single Linked List Adjacency List
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

// D2. Single Linked List Hash Table
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
	strcpy(tempNode->telNo, noTelp);
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
	printf("= Nomor Telepon   : %-26s=\n", currNode->telNo);
	printf("= Alamat Email    : %-26s=\n", currNode->email);
}

// A2. Single Linked List Contact Book

/**
 * Inisialisasi linked list contact book.
 *
 * Fungsi ini digunakan untuk menginisialisasi linked list contact book.
 *
 * @param tmpList Pointer ke linked list contact book yang akan diinisialisasi.
 */
void SLL_CB_init(ptrSLL_CB tmpList)
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
		currList->size++;
		currList->head = currNode;
	}
	else
	{
		ptrCB tmp = currList->head;

		while (tmp->next != NULL)
			tmp = tmp->next;

		tmp->next = currNode;
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
void SLL_CB_deleteHead(ptrSLL_CB currList)
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

		currList->head = currList->head->next;
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
void SLL_CB_deleteTail(ptrSLL_CB currList)
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
void SLL_CB_deleteName(ptrSLL_CB currList, char nama[])
{
	if (strcmp(currList->head->name, nama) == 0)
		SLL_CB_deleteHead(currList);
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
				SLL_CB_deleteTail(currList);
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