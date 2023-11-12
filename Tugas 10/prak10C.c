// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct item
{
	int key;
	int value;
};

struct hashtable_item
{
	/*
		flag = 0 -> Tidak ada data
		flag = 1 -> Ada data
		flag = 2 -> Sebelumnya ada datanya
	*/
	int flag;
	struct item *data;
};
struct hashtable_item *array;

// global var and default value
int size = 0;
int max = 10;

// Init hashtable array
void init_array()
{
	for (int i = 0; i < max; i++)
	{
		array[i].flag = 0;
		array[i].data = NULL;
	}
}

int hashcode(int key)
{
	return (key % max);
}

int sizeOf_hashtable()
{
	return size;
}

// Create new item
struct item *createItem(int key, int value)
{
	struct item *newItem = (struct item *)malloc(sizeof(struct item));
	newItem->key = key;
	newItem->value = value;

	return newItem;
}

// Insert function
void insert(int key, int value)
{
	int index = hashcode(key);
	int i = index;

	struct item *newItem = createItem(key, value);

	// Telusuri array sampai menemukan ruang kosong
	// Jika flag == 2, indeks tidak diisi lagi
	while (array[i].flag == 1 || array[i].flag == 2)
	{
		while (array[i].flag == 1)
		{
			if (array[i].data->key == key)
			{
				// Case where already existing key matches the given key
				printf("\n Key already exists, hence updating its value\n");
				array[i].data->value = value;
				return;
			}

			i = (i + 1) % max; // maju satu langkah
			// jika sudah mengecek satu-satu index sampai balik lagi ke index penuh
			if (i == index)
			{
				printf("\n Hash table is full, cannot insert any more item \n");
				return;
			}
		}

		while (array[i].flag == 2)
		{
			i = (i + 1) % max;
		}
	}

	size++;
	array[i].flag = 1;
	array[i].data = newItem;
	printf("\n Key (%d) has been inserted\n", key);
}

// Remove function
void remove_element(int key)
{
	int index = hashcode(key);
	int i = index;
	int k = i;
	int x = 1;

	// Telusuri array hingga mencapai ruang kosong di mana tidak ada satu pun elemen yang ada
	while (array[i].flag != 0)
	{
		if (array[i].flag == 1 && array[i].data->key == key)
		{
			// Ketika data key sesuai dengan key yang diberikan
			size--;
			array[i].flag = 2;
			array[i].data = NULL;

			printf("\n Key (%d) has been removed\n", key);
			return;
		}

		i = (i + 1) % max;
		if (i == index)
		{
			break;
		}
		x++;
	}

	printf("\n This key does not exist\n");
}

// Display function
void display()
{
	int i;
	for (i = 0; i < max; i++)
	{
		struct item *current = (struct item *)array[i].data;
		if (current == NULL)
		{
			printf("Array[%d] has no elements\n", i);
		}
		else
		{
			printf("Array[%d] has elements:\n %d(key) and %d(value)\n", i, current->key, current->value);
		}
	}
}

int main()
{
	int choice, key, value, n, c;

	printf("Enter the memory size that you want to use: ");
	scanf("%d", &max);

	array = (struct hashtable_item *)malloc(max * sizeof(struct hashtable_item));
	init_array();

	do
	{
		printf("\nImplementation of Hash Table in C\n\n");
		printf("MENU:\n");
		printf("1. Inserting item in the Hashtable\n");
		printf("2. Removing item from Hashtable\n");
		printf("3. Check the size of Hashtable\n");
		printf("4. Display Hashtable\n");
		printf("Please enter your choice: ");
		scanf("%d", &choice);

		printf("\n");
		switch (choice)
		{
		case 1:
			printf("Inserting element in Hashtable\n");
			printf(" Enter key:\t");
			scanf("%d", &key);
			printf(" Enter value:\t");
			scanf("%d", &value);

			insert(key, value);
			break;
		case 2:
			printf("Deleting in Hashtable\n Enter the key to delete: ");
			scanf("%d", &key);

			remove_element(key);
			break;
		case 3:
			n = sizeOf_hashtable();
			printf("Size of Hashtable is: %d\n", n);

			break;
		case 4:
			display();
			break;
		default:
			printf("Wrong Input\n");
		}

		printf("\nDo you want to continue:(press 1 for yes): ");
		scanf("%d", &c);
	} while (c == 1);

	getchar();
	return 0;
}