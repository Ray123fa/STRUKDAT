// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <windows.h> // to call COORD
#include <stdio.h>
#include <stdlib.h>	 // to call malloc()
#include <stdbool.h> // to call bool
#include <string.h>	 // to call strcpy()
#include <unistd.h>	 // to call sleep()

// Deklarasi Primary Key
static int pkey = 1;

// Struct

// Contact Book
// Node Contact Book
struct node_CB
{
	int pkey;
	char name[26];
	int age;
	char sex;
	char telpNo[14];
	char email[21];
	struct node_CB *next;
};
typedef struct node_CB *ptrCB;

// SLL Contact Book
struct SLL_CB
{
	ptrCB head;
	unsigned int size;
};
typedef struct SLL_CB *ptrSLL_CB;

// Koneksi
// Node Koneksi
struct node_Conn
{
	int pkey;
	struct node_Conn *next;
};
typedef struct node_Conn *ptrConnect;

// SLL Koneksi
struct SLL_Conn
{
	ptrConnect head;
	unsigned int size;
};
typedef struct SLL_Conn *ptrSLL_Conn;

// Adjaceny List
// Node Adjacency List
struct node_AdjList
{
	ptrSLL_Conn datalist;
	struct node_AdjList *next;
};
typedef struct node_AdjList *ptrAdjList;

// SLL Adjacency List
struct SLL_AdjList
{
	ptrAdjList head;
	unsigned int size;
};
typedef struct SLL_AdjList *ptrSLL_AdjList;

// Hash Table
// Node Hash Table
struct node_Hash
{
	int pkey;
	ptrCB data;
	struct node_Hash *next;
};
typedef struct node_Hash *ptrHash;

// SLL Hash Table
struct SLL_Hash
{
	ptrHash head;
	unsigned int size;
};
typedef struct SLL_Hash *ptrSLL_Hash;

// Struct End

// Function List
ptrCB createNode_CB(char nama[], unsigned umur, char jk, char noTelp[], char email[]);
void printNode_CB(ptrCB currNode);
void init_SLL_CB(ptrSLL_CB tmpList);
void SLL_CB_insert(ptrSLL_CB currList, ptrCB currNode, ptrSLL_AdjList currAdjList, ptrSLL_Hash currHashTable);
void SLL_CB_delHead(ptrSLL_CB currList);
void SLL_CB_delTail(ptrSLL_CB currList);
void SLL_CB_delName(ptrSLL_CB currList, char nama[]);

void init_SLL_Connect(ptrSLL_Conn tmpList);
ptrConnect createNode_Conn(int pkey);
void SLL_Conn_insertTail(ptrSLL_Conn currList, int pkey);
void SLL_Conn_delHead(ptrSLL_Conn currList);
void SLL_Conn_delTail(ptrSLL_Conn currList);
void SLL_Conn_delPkey(ptrSLL_Conn currList, int pkey);

void init_nodeAdjList(ptrAdjList currAdjListNode);
ptrAdjList createNode_Adjlist(int src);
void init_SLL_AdjList(ptrSLL_AdjList currAdjList);
void SLL_AdjList_insertTail(ptrSLL_AdjList currAdjList, int src);
bool SLL_AdjList_checkConnection(ptrSLL_AdjList currAdjList, int src, int dest);
void SLL_AdjList_insertConnect(ptrSLL_AdjList currAdjList, int src, int dest);
void SLL_AdjList_delConnect(ptrSLL_AdjList currAdjList, int src, int dest);

ptrHash createNode_Hash(int pkey, ptrCB currNode);
void init_SLL_Hash(ptrSLL_Hash currHashTable);
void SLL_Hash_insertTail(ptrSLL_Hash currHashTable, int pkey, ptrCB currNode);
ptrCB SLL_Hash_getData(ptrSLL_Hash currHashTable, int pkey);

void insertContact(ptrSLL_CB contactList, ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey);
void delContact(ptrSLL_CB contactList, ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey);
void displayContacts(ptrSLL_CB contactList);
void sortContactByName(ptrSLL_CB contactList);
void searchByName(ptrSLL_CB contactList);
void handlingEditContact(ptrSLL_CB contactList, int choice, int pkey, ptrSLL_Hash idxKey);
void editContact(ptrSLL_CB contactList, ptrSLL_Hash idxKey);

ptrCB handlingMergeSort(ptrCB _1node, ptrCB _2node, bool isAsc);
ptrCB mid_SLL_CB(ptrCB head);
ptrCB mergeSortName(ptrCB head, bool isAsc);

ptrCB middle(ptrCB start, ptrCB last);
ptrCB binarySearchName(ptrSLL_CB contactList, char nama[]);

void insertConnection(ptrSLL_CB contactList, ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey);
void delConnection(ptrSLL_CB contactList, ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey);
void displayConnection(ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey);

bool isMatch(const char *pattern, const char *nama);
int countMatch(ptrSLL_CB contactList, char nama[]);
void wildcardSearch(ptrSLL_CB contactList);

int searchPkey(ptrSLL_CB contactList, char nama[]);

unsigned minAge(ptrSLL_CB contactList);
unsigned maxAge(ptrSLL_CB contactList);
float avgAge(ptrSLL_CB contactList);
void ageStatistics(ptrSLL_CB contactList);

void gotoxy(short x, short y);
char toUpperCase(char *str);
void pagesInfo(int size, int divisor, int currentPage);
// End Function List

// Main Program
void main()
{
	// Init Contact Book
	ptrSLL_CB contactList = (ptrSLL_CB)malloc(sizeof(struct SLL_CB));
	init_SLL_CB(contactList);

	// Init Adjlist Connection List
	ptrSLL_AdjList connectionList = (ptrSLL_AdjList)malloc(sizeof(struct SLL_AdjList));
	init_SLL_AdjList(connectionList);

	// Init Hash Table
	ptrSLL_Hash idxKey = (ptrSLL_Hash)malloc(sizeof(struct SLL_Hash));
	init_SLL_Hash(idxKey);

	// Kontak Tersimpan
	ptrCB _1 = createNode_CB("M RAYHAN F", 19, 'L', "08225562****", "222212766@stis.ac.id");
	ptrCB _2 = createNode_CB("M NABIL FAWWAZ", 19, 'L', "08237727****", " ");
	ptrCB _3 = createNode_CB("MUH NUR AFRIZAL", 20, 'L', "08232704****", " ");
	ptrCB _4 = createNode_CB("MUHAMMAD", 18, 'L', "08524877****", " ");
	ptrCB _5 = createNode_CB("AHMAD", 17, 'L', "08235729****", " ");

	// Insert Kontak Tersimpan
	SLL_CB_insert(contactList, _1, connectionList, idxKey);
	SLL_CB_insert(contactList, _2, connectionList, idxKey);
	SLL_CB_insert(contactList, _3, connectionList, idxKey);
	SLL_CB_insert(contactList, _4, connectionList, idxKey);
	SLL_CB_insert(contactList, _5, connectionList, idxKey);

	// Cari pkey
	int k1 = searchPkey(contactList, "M RAYHAN F");
	int k2 = searchPkey(contactList, "M NABIL FAWWAZ");
	int k3 = searchPkey(contactList, "MUH NUR AFRIZAL");
	int k4 = searchPkey(contactList, "MUHAMMAD");
	int k5 = searchPkey(contactList, "AHMAD");

	// Insert koneksi
	SLL_AdjList_insertConnect(connectionList, k1, k3);
	SLL_AdjList_insertConnect(connectionList, k1, k2);
	SLL_AdjList_insertConnect(connectionList, k3, k1);
	SLL_AdjList_insertConnect(connectionList, k2, k3);
	SLL_AdjList_insertConnect(connectionList, k2, k4);
	SLL_AdjList_insertConnect(connectionList, k4, k2);
	SLL_AdjList_insertConnect(connectionList, k4, k5);
	SLL_AdjList_insertConnect(connectionList, k5, k4);

	bool isRunning = true;
	int choice;

	system("cls");
	contactList->head = mergeSortName(contactList->head, true);
	while (isRunning)
	{
		printf("==================================================\n");
		printf("%-14sContact Book by Rayhan%14s\n", "=", "=");
		printf("==================================================\n");
		printf("= 1. Tambah Kontak %31s\n", "=");
		printf("= 2. Hapus Kontak %32s\n", "=");
		printf("= 3. Tampilkan Kontak %28s\n", "=");
		printf("= 4. Urutkan Kontak %30s\n", "=");
		printf("= 5. Cari Kontak %33s\n", "=");
		printf("= 6. Edit Kontak %33s\n", "=");
		printf("= 7. Pencarian Wildcard %26s\n", "=");
		printf("= 8. Statistik Umur %30s\n", "=");
		printf("= 9. Tambah Koneksi %30s\n", "=");
		printf("= 10. Hapus Koneksi %30s\n", "=");
		printf("= 11. Tampilkan Koneksi %26s\n", "=");
		printf("= 12. Keluar %37s\n", "=");
		printf("==================================================\n");
		printf("= Pilihan: %39s\n", "=");
		printf("==================================================\n");

		gotoxy(11, 16);
		scanf("%d", &choice);
		getchar();
		while (choice < 1 || choice > 12)
		{
			gotoxy(11, 16);
			printf("%39s", "=");
			gotoxy(11, 16);
			scanf("%d", &choice);
			getchar();
		}

		system("cls");
		if (choice == 12)
		{
			isRunning = false;
			printf("Terima kasih telah menggunakan program ini!\n");
			break;
		}

		switch (choice)
		{
		case 1:
			insertContact(contactList, connectionList, idxKey);
			break;
		case 2:
			delContact(contactList, connectionList, idxKey);
			break;
		case 3:
			displayContacts(contactList);
			break;
		case 4:
			sortContactByName(contactList);
			break;
		case 5:
			searchByName(contactList);
			break;
		case 6:
			editContact(contactList, idxKey);
			break;
		case 7:
			wildcardSearch(contactList);
			break;
		case 8:
			ageStatistics(contactList);
			break;
		case 9:
			insertConnection(contactList, connectionList, idxKey);
			break;
		case 10:
			delConnection(contactList, connectionList, idxKey);
			break;
		case 11:
			displayConnection(connectionList, idxKey);
			break;
		default:
			printf("Pilihan tidak tersedia!\n");
		}
	}
}

// Contact Book
// Node Contact Book
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
	toUpperCase(nama);
	strcpy(tempNode->name, nama);
	tempNode->age = umur;
	tempNode->sex = toUpperCase(&jk);
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
	printf("= Nama            : %-29s=\n", currNode->name);
	printf("= Umur            : %-29u=\n", currNode->age);
	printf("= Jenis Kelamin   : %-29c=\n", currNode->sex);
	printf("= Nomor Telepon   : %-29s=\n", currNode->telpNo);
	printf("= Alamat Email    : %-29s=\n", currNode->email);
}

// SLL Contact Book
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
		printf("Kontak kosong!\n");
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
		printf("Kontak kosong!\n");

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

// Koneksi
// Node Koneksi
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

// SLL Koneksi
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

// Adjacency List
// Node Adjacency List
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

// SLL Adjacency List
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
 * Memeriksa apakah terdapat koneksi antara dua simpul dalam daftar adjacency list.
 *
 * @param currAdjList Pointer ke daftar adjacency list.
 * @param src Indeks simpul sumber.
 * @param dest Indeks simpul tujuan.
 * @return true jika terdapat koneksi antara src dan dest, false jika tidak.
 */
bool SLL_AdjList_checkConnection(ptrSLL_AdjList currAdjList, int src, int dest)
{
	ptrAdjList cursor = currAdjList->head;

	while (cursor != NULL)
	{
		if (cursor->datalist->head->pkey == src)
		{
			ptrConnect cursor2 = cursor->datalist->head;

			while (cursor2 != NULL)
			{
				if (cursor2->pkey == dest)
					return true;
				cursor2 = cursor2->next;
			}
		}
		cursor = cursor->next;
	}

	return false;
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

	while (cursor->datalist->head != NULL && cursor->datalist->head->pkey != src)
	{
		cursor = cursor->next;
	}

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

// Hash Table
// Node Hash Table
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

// SLL Hash Table
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

ptrCB SLL_Hash_getData(ptrSLL_Hash currHashTable, int pkey)
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

// Insert Contact
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
	scanf(" %25[^\n]", nama);
	printf("= Umur                : ");
	scanf("%u", &umur);
	printf("= Jenis Kelamin [L/P] : ");
	scanf(" %c", &sex);
	printf("= Nomor Telepon       : ");
	scanf(" %13s", noTelp);
	printf("= Alamat Email        : ");
	scanf(" %20s", email);
	printf("==================================================\n");

	SLL_CB_insert(contactList, createNode_CB(nama, umur, sex, noTelp, email), connectionList, idxKey);
	contactList->head = mergeSortName(contactList->head, true);

	sleep(1);
	system("cls");
	printf("Data berhasil ditambahkan!\n\n");
	printf("Enter untuk kembali ke menu...");
	getchar();
	getchar();
	system("cls");
}

// Delete Contact
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
	scanf(" %25[^\n]", nama);
	toUpperCase(nama);
	printf("==================================================\n\n");

	contactList->head = mergeSortName(contactList->head, true);
	ptrCB temp = binarySearchName(contactList, nama);

	sleep(1);
	if (temp == NULL)
		printf("Data tidak ditemukan, tidak ada yang dihapus!\n");
	else
	{
		SLL_CB_delName(contactList, temp->name);
		printf("Data berhasil dihapus!\n");
	}

	printf("\nEnter untuk kembali ke menu...");
	getchar();
	getchar();
	system("cls");
}

// Display Contact
/**
 * Menampilkan daftar kontak.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 */
void displayContacts(ptrSLL_CB contactList)
{
	ptrCB cursor = contactList->head;
	int counter = 0;

	printf("==================================================\n");
	printf("%-18sDaftar Kontak%18s\n", "=", "=");
	printf("==================================================\n");
	printf("= Jumlah kontak: %-32d=\n", contactList->size);

	int divisor = 5;
	int currentPage = 1;
	pagesInfo(contactList->size, divisor, currentPage);

	while (cursor != NULL)
	{
		printf("==================================================\n");
		printNode_CB(cursor);
		counter++;
		cursor = cursor->next;

		if (counter == divisor && cursor != NULL)
		{
			printf("==================================================\n\n");
			printf("Enter untuk melanjutkan...");
			getchar();
			system("cls");

			printf("==================================================\n");
			printf("%-18sDaftar Kontak%18s\n", "=", "=");
			printf("==================================================\n");
			printf("= Jumlah kontak: %-32d=\n", contactList->size);
			counter = 0;

			pagesInfo(contactList->size, divisor, ++currentPage);
		}
	}

	printf("==================================================\n\n");
	printf("Enter untuk kembali ke menu...");
	getchar();
	system("cls");
}

// Sort Contact by Name
/**
 * Mengurutkan daftar kontak berdasarkan nama.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 */
void sortContactByName(ptrSLL_CB contactList)
{
	int choice;

	printf("==================================================\n");
	printf("%-18sUrutkan Kontak%18s\n", "=", "=");
	printf("==================================================\n");
	printf("= 1. Ascending  (A to Z) %-24s=\n", " ");
	printf("= 2. Descending (Z to A) %-24s=\n", " ");
	printf("==================================================\n");
	printf("= Pilihan: %39s\n", "=");
	printf("==================================================\n");

	gotoxy(11, 6);
	scanf("%d", &choice);
	getchar();

	while (choice != 1 && choice != 2)
	{
		gotoxy(11, 6);
		printf("%39s", "=");
		gotoxy(11, 6);
		scanf("%d", &choice);
		getchar();
	}
	contactList->head = mergeSortName(contactList->head, (bool)(2 - choice));

	printf("==================================================\n\n");
	sleep(1);
	if (choice == 1)
		printf("Kontak berhasil diurutkan secara ascending berdasarkan nama.\n");
	else
		printf("Kontak berhasil diurutkan secara descending berdasarkan nama.\n");

	printf("\nEnter untuk kembali ke menu...");
	getchar();
	system("cls");
}

// Search Contact by Name
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
	printf("= Masukkan nama: %33s\n", "=");
	printf("==================================================\n");

	gotoxy(17, 3);
	scanf(" %25[^\n]", nama);
	toUpperCase(nama);
	printf("==================================================\n");
	getchar();

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
	printf("Enter untuk kembali ke menu...");
	getchar();
	system("cls");
}

// Edit Contact
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
		scanf(" %25[^\n]", input);
		toUpperCase(input);
		strcpy(cursor->name, input);
		strcpy(SLL_Hash_getData(idxKey, pkey)->name, input);
		break;
	case 2:
		scanf("%d", &age);

		cursor->age = age;
		SLL_Hash_getData(idxKey, pkey)->age = age;
		break;
	case 3:
		scanf("%c", &sex);

		cursor->sex = toUpperCase(&sex);
		SLL_Hash_getData(idxKey, pkey)->sex = sex;
		break;
	case 4:
		scanf(" %13s", input);

		strcpy(cursor->telpNo, input);
		strcpy(SLL_Hash_getData(idxKey, pkey)->telpNo, input);
		break;
	case 5:
		scanf(" %20s", input);

		strcpy(cursor->email, input);
		strcpy(SLL_Hash_getData(idxKey, pkey)->email, input);
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
	printf("= Masukkan nama: %33s\n", "=");
	printf("==================================================\n\n");

	gotoxy(17, 3);
	scanf(" %25[^\n]", nama);
	toUpperCase(nama);

	printf("==================================================\n");
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
		printf("= Pilihan: %39s\n", "=");
		printf("==================================================\n");

		gotoxy(11, 12);
		scanf("%d", &choice);
		getchar();

		while (choice < 1 || choice > 5)
		{
			gotoxy(11, 12);
			printf("%39s", "=");
			gotoxy(11, 12);
			scanf("%d", &choice);
			getchar();
		}

		printf("\n");
		handlingEditContact(contactList, choice, temp->pkey, idxKey);
		contactList->head = mergeSortName(contactList->head, true);

		printf("==================================================\n\n");
		printf("Data berhasil diubah!\n\n");
	}
	else
		printf("Data tidak ditemukan!\n\n");

	printf("Enter untuk kembali ke menu...");
	getchar();
	getchar();
	system("cls");
}

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

// Wildcard Search
/**
 * Fungsi ini digunakan untuk memeriksa apakah string 'nama' cocok dengan pola 'pattern'.
 *
 * @param pattern Pola yang akan dibandingkan dengan string 'nama'.
 * @param nama String yang akan dibandingkan dengan pola 'pattern'.
 * @return true jika string 'nama' cocok dengan pola 'pattern', false jika tidak cocok.
 */
bool isMatch(const char *pattern, const char *nama)
{
	if (*pattern == '\0')
		return *nama == '\0';

	if (*pattern == '?' || *pattern == *nama)
		return *nama != '\0' && isMatch(pattern + 1, nama + 1);

	if (*pattern == '*')
		return isMatch(pattern + 1, nama) || (*nama != '\0' && isMatch(pattern, nama + 1));

	return false;
}

/**
 * Menghitung jumlah kemunculan pola pada linked list.
 *
 * @param contactList Pointer ke linked list yang berisi data kontak.
 * @param pattern Pola yang ingin dicari pada data kontak.
 * @return Jumlah kemunculan pola pada linked list.
 */
int countMatch(ptrSLL_CB contactList, char pattern[])
{
	ptrCB cursor = contactList->head;
	int counter = 0;

	while (cursor != NULL)
	{
		if (isMatch(pattern, cursor->name))
			counter++;

		cursor = cursor->next;
	}

	return counter;
}

/**
 * Fungsi untuk melakukan pencarian dengan menggunakan wildcard pada daftar kontak.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 */
void wildcardSearch(ptrSLL_CB contactList)
{
	char pattern[30];

	printf("==================================================\n");
	printf("%-18sWildcard Search%17s\n", "=", "=");
	printf("==================================================\n");
	printf("= Petunjuk: %38s\n", "=");
	printf("= '*' merepresentasikan 0 atau lebih karakter.   =\n");
	printf("= '?' merepresentasikan 1 karakter.              =\n");
	printf("= Contoh: %40s\n", "=");
	printf("= > Pola: M*F %36s\n", "=");
	printf("= > Kontak yang mungkin: %25s\n", "=");
	printf("=   > M Rayhan F %33s\n", "=");
	printf("==================================================\n");
	printf("= Masukkan pola: %33s\n", "=");
	printf("==================================================\n");

	gotoxy(17, 11);
	scanf(" %25[^\n]", pattern);
	getchar();
	toUpperCase(pattern);
	printf("==================================================\n");

	sleep(1);
	system("cls");
	printf("==================================================\n");
	printf("%-20s H A S I L %19s\n", "=", "=");
	printf("==================================================\n");

	ptrCB cursor = contactList->head;
	if (cursor == NULL)
		printf("Kontak kosong!\n");
	else
	{
		int size = countMatch(contactList, pattern);
		int divisor = 5;
		int currentPage = 1;
		pagesInfo(size, divisor, currentPage);
		printf("==================================================\n");

		int counter = 0;
		while (cursor != NULL)
		{
			if (isMatch(pattern, cursor->name))
			{
				printNode_CB(cursor);
				printf("==================================================\n");
				counter++;

				if (counter == divisor && cursor->next != NULL)
				{
					printf("\nEnter untuk melanjutkan...");
					getchar();
					system("cls");

					printf("==================================================\n");
					printf("%-20s H A S I L %19s\n", "=", "=");
					printf("==================================================\n");
					counter = 0;

					pagesInfo(size, divisor, ++currentPage);
					printf("==================================================\n");
				}
			}
			cursor = cursor->next;
		}
	}

	printf("\nEnter untuk kembali ke menu...");
	getchar();
	system("cls");
}

// Cari Primary Key
/**
 * Fungsi ini digunakan untuk mencari primary key (pkey) berdasarkan nama pada linked list.
 *
 * @param contactList Pointer ke linked list yang berisi data kontak.
 * @param nama Nama yang akan dicari dalam linked list.
 * @return Nilai pkey dari kontak yang memiliki nama yang sesuai, atau -1 jika tidak ditemukan.
 */
int searchPkey(ptrSLL_CB contactList, char nama[])
{
	contactList->head = mergeSortName(contactList->head, true);
	ptrCB temp = binarySearchName(contactList, nama);

	if (temp != NULL)
		return temp->pkey;
	else
		return -1;
}

// Insert Connection
/**
 * Fungsi ini digunakan untuk memasukkan koneksi antara dua simpul pada daftar koneksi.
 *
 * @param contactList Pointer ke daftar simpul kontak.
 * @param connectionList Pointer ke daftar koneksi antara simpul-simpul.
 * @param idxKey Pointer ke daftar hash indeks kunci.
 */
void insertConnection(ptrSLL_CB contactList, ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey)
{
	char src[20];
	char dest[20];
	int i = 0, n = 0;

	printf("==================================================\n");
	printf("%-18sTambah Koneksi%18s\n", "=", "=");
	printf("==================================================\n");

	printf("Banyak koneksi yang ingin dimasukkan: ");
	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		printf("Koneksi ke-%d\n", i + 1);
		printf("- Nama kontak sumber: ");
		scanf(" %20[^\n]", src);
		toUpperCase(src);
		printf("- Nama kontak tujuan: ");
		scanf(" %20[^\n]", dest);
		toUpperCase(dest);

		ptrCB srcKey = SLL_Hash_getData(idxKey, searchPkey(contactList, src));
		ptrCB destKey = SLL_Hash_getData(idxKey, searchPkey(contactList, dest));

		if (srcKey == NULL || destKey == NULL)
		{
			printf("Koneksi gagal ditambahkan, pastikan data yang dimasukkan sudah tersedia!\n\n");
			i--;
		}
		else
		{
			if (!SLL_AdjList_checkConnection(connectionList, srcKey->pkey, destKey->pkey))
				SLL_AdjList_insertConnect(connectionList, srcKey->pkey, destKey->pkey);
			else
			{
				printf("Koneksi sudah ada!\n\n");
				i--;
			}
		}
	}

	sleep(1);
	system("cls");
	printf("Data berhasil ditambahkan!\n\n");
	printf("Enter untuk kembali ke main menu...");
	getchar();
	system("cls");
}

// Delete Connection
/**
 * Fungsi ini digunakan untuk menghapus koneksi antara dua simpul pada daftar koneksi.
 *
 * @param contactList Pointer ke daftar simpul kontak.
 * @param connectionList Pointer ke daftar koneksi antara simpul-simpul.
 * @param idxKey Pointer ke daftar hash indeks kunci.
 */
void delConnection(ptrSLL_CB contactList, ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey)
{
	char src[20];
	char dest[20];
	int i = 0, n = 0;

	printf("==================================================\n");
	printf("%-19sHapus Koneksi%18s\n", "=", "=");
	printf("==================================================\n");
	printf("= Nama kontak sumber: %28s\n", "=");
	printf("==================================================\n");
	printf("= Nama kontak tujuan: %28s\n", "=");
	printf("==================================================\n");

	gotoxy(22, 3);
	scanf(" %20[^\n]", src);
	toUpperCase(src);

	gotoxy(22, 5);
	scanf(" %20[^\n]", dest);
	toUpperCase(dest);
	printf("\n");

	contactList->head = mergeSortName(contactList->head, true);
	ptrCB nodeSrc = binarySearchName(contactList, src);
	ptrCB nodeDest = binarySearchName(contactList, dest);

	sleep(1);
	if (nodeSrc == NULL || nodeDest == NULL)
		printf("Data tidak ditemukan, tidak ada yang dihapus!\n");
	else
	{
		SLL_AdjList_delConnect(connectionList, nodeSrc->pkey, nodeDest->pkey);
		printf("Koneksi berhasil dihapus!\n");
	}

	printf("==================================================\n\n");
	printf("Enter untuk kembali ke menu...");
	getchar();
	getchar();
	system("cls");
}

// Display Connection
/**
 * Menampilkan daftar koneksi dalam buku kontak.
 *
 * @param connectionList Pointer ke daftar koneksi.
 * @param idxKey Pointer ke indeks kunci.
 */
void displayConnection(ptrSLL_AdjList connectionList, ptrSLL_Hash idxKey)
{
	printf("==================================================\n");
	printf("%-18sDaftar Koneksi%18s\n", "=", "=");
	printf("==================================================\n");

	if (connectionList->size == 0)
		printf("Koneksi kosong!\n");
	else
	{
		ptrAdjList cursor = connectionList->head;
		ptrConnect cursor2 = cursor->datalist->head;
		int counter = 0;

		int divisor = 10;
		int currentPage = 1;
		pagesInfo(connectionList->size, divisor, currentPage);
		printf("==================================================\n");

		while (cursor != NULL)
		{
			printf("%-25s: ", SLL_Hash_getData(idxKey, cursor2->pkey)->name);
			cursor2 = cursor2->next;

			while (cursor2 != NULL)
			{
				printf("(%s) ", SLL_Hash_getData(idxKey, cursor2->pkey)->name);
				cursor2 = cursor2->next;
			}
			printf("\n");

			counter++;
			cursor = cursor->next;
			if (cursor != NULL)
			{
				cursor2 = cursor->datalist->head;

				if (counter == divisor)
				{
					printf("==================================================\n\n");
					printf("Enter untuk melanjutkan...");
					getchar();
					system("cls");

					printf("==================================================\n");
					printf("%-18sDaftar Koneksi%18s\n", "=", "=");
					printf("==================================================\n");
					counter = 0;

					pagesInfo(connectionList->size, divisor, ++currentPage);
					printf("==================================================\n");
				}
			}
		}

		printf("==================================================\n\n");
		printf("Enter untuk kembali ke menu...");
		getchar();
		system("cls");
	}
}

// Umur Minimum
/**
 * Fungsi ini digunakan untuk mencari umur minimum dari daftar kontak.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 * @return Umur minimum dari daftar kontak.
 */
unsigned minAge(ptrSLL_CB contactList)
{
	ptrCB cursor = contactList->head;
	unsigned min = 0;

	if (cursor == NULL)
		return -1;
	else
	{
		int min = cursor->age;
		while (cursor != NULL)
		{
			if (cursor->age < min)
				min = cursor->age;

			cursor = cursor->next;
		}

		return min;
	}
}

// Umur Maksimum
/**
 * Fungsi ini digunakan untuk mencari umur maksimum dari daftar kontak.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 * @return Umur maksimum dari daftar kontak.
 */
unsigned maxAge(ptrSLL_CB contactList)
{
	ptrCB cursor = contactList->head;
	unsigned max = 0;

	if (cursor == NULL)
		return -1;
	else
	{
		int max = cursor->age;
		while (cursor != NULL)
		{
			if (cursor->age > max)
				max = cursor->age;

			cursor = cursor->next;
		}

		return max;
	}
}

// Rerata Umur
/**
 * Fungsi ini digunakan untuk mencari rerata umur dari daftar kontak.
 *
 * @param contactList Pointer ke linked list yang berisi daftar kontak.
 * @return Rerata umur dari daftar kontak.
 */
float avgAge(ptrSLL_CB contactList)
{
	ptrCB cursor = contactList->head;

	if (cursor == NULL)
		return -1;
	else
	{
		float sum = 0;
		while (cursor != NULL)
		{
			sum += cursor->age;
			cursor = cursor->next;
		}

		return sum / contactList->size;
	}
}

// Statistik Umur
/**
 * Menghitung statistik usia dari daftar kontak.
 *
 * @param contactList Pointer ke head dari linked list kontak.
 */
void ageStatistics(ptrSLL_CB contactList)
{
	printf("==================================================\n");
	printf("%-18sStatistik Umur%18s\n", "=", "=");
	printf("==================================================\n");

	if (contactList->size == 0)
		printf("= Kontak kosong! %33s\n", "=");
	else
	{
		printf("= Umur minimum: %-33u=\n", minAge(contactList));
		printf("= Umur maksimum: %-32u=\n", maxAge(contactList));
		printf("= Rerata umur: %-34.2f=\n", avgAge(contactList));
	}

	printf("==================================================\n\n");
	printf("Enter untuk kembali ke menu...");
	getchar();
	system("cls");
}

// GotoXY Function
/**
 * Fungsi ini digunakan untuk memindahkan kursor ke posisi yang ditentukan
 * berdasarkan koordinat x dan y.
 *
 * @param x Koordinat horizontal untuk memindahkan kursor.
 * @param y Koordinat vertikal untuk memindahkan kursor.
 */
void gotoxy(short x, short y)
{
	COORD pos = {x, y};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// Convert to Uppercase
/**
 * Mengubah semua karakter dalam string menjadi huruf kapital.
 *
 * @param str Pointer ke string yang akan diubah.
 * @return String yang telah diubah menjadi huruf kapital.
 */
char toUpperCase(char *str)
{
	int i = 0;

	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}

	return *str;
}

// Pages Info
/**
 * Mengambil informasi halaman.
 * 
 * @param size Ukuran halaman.
 * @param divisor Pembagi halaman.
 * @param currentPage Halaman saat ini.
 */
void pagesInfo(int size, int divisor, int currentPage)
{
	int bykPages;

	if (size > 0 && size < divisor)
		printf("= Menampilkan halaman 1 dari 1 %19s\n", "=");
	else if (size % divisor != 0 || size % divisor == 0)
	{
		if (size % divisor != 0)
			bykPages = size / divisor + 1;
		else
			bykPages = size / divisor;
		printf("= Menampilkan halaman %d dari %d %19s\n", currentPage, bykPages, "=");
	}
}