// Muhammad Rayhan Faridh
// 222212766
// 2KS1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
  int data;
  struct node* next;
} Tnode;
typedef Tnode* ptrnode;

typedef struct stack
{
  ptrnode head;
  int size; // untuk menyimpan berapa banyak stack terbentuk
} Tstack;
typedef Tstack* ptrstack;

ptrnode createnode(int nilai) {
  ptrnode newnode = (ptrnode)malloc(sizeof(Tnode));
  newnode->data = nilai;
  newnode->next = NULL;

  return newnode;
}

void init(ptrstack s) {
  s->head = NULL;
  s->size = 0;
}

// cek stack kosong atau tidak
bool stack_isEmpty(ptrstack s) {
  return (s->size == 0);
}

// cek apakah stack sudah full
bool stack_isFull(ptrstack s) {
  return (s->size == 16); // dapat menampung hingga 16 digit biner
}

// push head
void push(ptrstack s, int nilai) {
  ptrnode newnode = createnode(nilai);

  if (stack_isEmpty(s))
  {
    s->head = newnode;
    s->size = 1;
  }
  else
  {
    if (!stack_isFull(s)) {
      newnode->next = s->head;
      s->head = newnode;
      ++s->size;
    }
    else printf("Stack melebihi batas!");
  }
}

// delete head
void pop(ptrstack s) {
  if (!stack_isEmpty(s))
  {
    ptrnode tmp = s->head;

    if (tmp->next != NULL)
    {
      s->head = tmp->next;
      tmp->next = NULL;
    }
    else s->head = NULL;

    free(tmp);
    --s->size;
  }
}

// mengembalikan nilai teratas stack
int top_stack(ptrstack s) {
  return s->head->data;
}

void convert_bin(int num, ptrstack s)
{
  if (num > 0) {
    push(s, num % 2);
    convert_bin(num / 2, s);
  }
  else if (num < 0) {
    // >> adalah operator shift right
    // & adalah operator bitwise and

    // perulangan dibuat agar hanya bisa sebanyak 8 digit
    for (int i = 0; i <= 7; i++) {
      int bit = (num >> i) & 1;
      push(s, bit);
    }
  }
}

void convert_octal(int num, ptrstack s)
{
  if (num > 0) {
    push(s, num % 8);
    convert_octal(num / 8, s);
  }
}

int main()
{
  int bil, menu;

  ptrstack myStack = malloc(sizeof(Tstack));
  init(myStack);

  system("cls"); // clearscreen
  printf("Program Konversi Desimal ke Biner dan Oktal\n\n");
  printf("Masukkan bilangan desimal: ");
  scanf("%d", &bil);

  printf("\nMenu:\n");
  printf("1. Ubah menjadi biner\n");
  printf("2. Ubah menjadi oktal\n");
  printf("Pilihan Anda: ");
  scanf("%d", &menu);

  switch (menu) {
  case 1:
    if (bil == 0)
      printf("\nHasil konversi %d ke biner: 0", bil);
    else {
      convert_bin(bil, myStack);

      printf("\nHasil konversi %d ke biner: ", bil);
      while (!stack_isEmpty(myStack)) {
        printf("%d", top_stack(myStack));

        // setelah mencetak 1 digit, digit tersebut akan dihapus
        pop(myStack);
      }
    }
    printf("\n");
    break;
  case 2:
    if (bil < 0)
      printf("\nTidak dapat mengonversi ke oktal!");
    else if (bil > 0) {
      convert_octal(bil, myStack);

      printf("\nHasil konversi %d ke oktal: ", bil);
      while (!stack_isEmpty(myStack)) {
        printf("%d", top_stack(myStack));

        // setelah mencetak 1 digit, digit tersebut akan dihapus
        pop(myStack);
      }
    }
    else printf("\nHasil konversi %d ke oktal: 0", bil);
    printf("\n");
    break;
  default:
    printf("\nPerintah tidak diketahui! Program ditutup...\n");
    exit(1);
  }

  int repeat;
  printf("\nCoba lagi?\n(0=Ya; 1=Tidak): ");
  scanf("%d", &repeat);
  if (repeat == 0) main();
  else printf("\nProgram ditutup.");

  return 0;
}