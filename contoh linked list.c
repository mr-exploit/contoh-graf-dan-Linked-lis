#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	int No;
	char judul[50];
	char Isi [999];
}slide;
typedef struct Node{
	slide data;
	struct Node *next;
	struct Node *prev;
}Node;
typedef struct Node Simpul;
Simpul *P, *HEAD, *TAIL;

void inisialisasi(){
	HEAD = NULL;
}

void buatSimpul(slide x){
	P = (Simpul *) malloc(sizeof(Simpul));
	if (P!=NULL){
 		P->data.No = x.No;
   		strcpy(P->data.judul,x.judul);
		strcpy(P->data.Isi,x.Isi);
	}
	else
	printf ("Pembuatan Simpul Gagal. \n");
}

void awal(){
	if (HEAD == NULL){
		HEAD = P;
		TAIL = P;
		P->next = NULL;
		P->prev = NULL;
	}
	else
	printf("Linked List sudah ada. \n");
}

void insertBelakang(){
	TAIL->next = P;
	P->prev = TAIL;
	TAIL = P;
	P->next = NULL;

}

void insertDepan (){
	if (HEAD != NULL)
	{
                                  
		P->next = HEAD;
		HEAD ->prev = P;
		HEAD = P;
		P->prev = NULL;  
	}
	else
	printf("Linked list belum ada. \n");	
}

void insertSetelah (slide x){
	Simpul *Q;
	Q = HEAD;
	while (Q->data.No !=x.No){
	Q=Q->next;}
	P->next = Q->next;
	Q->next = P;
	P->prev = Q;
	
}

insertSebelum (slide x)
{
	Simpul *Q, *sebelumQ;
	if (HEAD->data.No == x.No)
	insertDepan();
	else
	{
		Q=HEAD;
		do{
			sebelumQ = Q;
			Q=Q->next;
		}
		while (Q->data.No !=x.No);
		P->next = Q;
		sebelumQ->next = P;
		P->prev = sebelumQ;
	}
}

void deleteDepan(){
	Simpul *Q;
	Q=HEAD;
	HEAD=Q->next;
	free(Q);
	HEAD->prev = NULL;
}

void deleteBelakang()
{
	Simpul *Q;
	Q=HEAD;
	while(Q->next != TAIL)
		Q=Q->next;
	free(TAIL);
	TAIL=Q;
	Q->next = NULL;
	TAIL->prev = Q->prev;
}

void deleteSimpul(slide x)
{
     Simpul *Q, *sebelumQ;
     if (HEAD == NULL)
        printf("Linked list kosong\n");
     else if (HEAD->data.judul == x.judul){
          deleteDepan();
     } else
     {
        Q = HEAD;
        do { 
           sebelumQ = Q;
           Q = Q->next;
        } while (Q->data.judul != x.judul);
        sebelumQ->next = Q->next;
        Q->prev = sebelumQ;
        free(Q);
     }
}

void printlist(){
	Simpul *Q, *R;
	int pilih;
	Q=HEAD;
	top:
	system("cls");
	R=HEAD;
	printf("=================Daftar Linked List=================\n");
	while (R->next != NULL){
		printf("\nSlide %d:\n", R->data.No);
		printf("%s\n", R->data.judul);
		printf("%s\n", R->data.Isi);
		R = R->next;
	};
	printf("\nSlide %d:\n", R->data.No);
	printf("%s\n", R->data.judul);
	printf("%s\n", R->data.Isi);
	printf("\nSekarang slide \n");
	printf("Slide : %d\n", Q->data.No);
	printf("%s\n", Q->data.judul);
	printf("%s\n", Q->data.Isi);
	printf("\n1.Next\n2.Prev\n3.Kembali ke menu\n\nMasukkan Pilihan: ");
	scanf("%d", &pilih);

	switch (pilih) {
	case 1 :
		if (Q->next != NULL){
		Q = Q->next;
		printf("%d, ", Q->data);
		goto top;
		break;
		}
		else
		printf("Simpul Tidak ada\n");
		getch();
		goto top;
		break;
	case 2 :
		if (Q->prev != NULL){
		Q = Q->prev;
		printf("%d, ", Q->data);
		goto top;
		break;
		}else
		printf("Simpul Tidak ada\n");
		getch();
		goto top;
		break;
	case 3 :
		break;
	default:
		printf("pilihan tidak ada\n");
		break;
		}
}

int main (){
	int pilih;
	slide x, y;
	inisialisasi();
	x.No = 1;
	printf("Doubly Linked List \n");
	printf("------------------- \n");
	printf("Slide %d \n", x.No);
	printf("Masukkan Judul: ");
	scanf ("%s", &x.judul);
	printf("Masukkan Isi: ");
	scanf ("%s", &x.Isi); 
	buatSimpul(x);
	awal();
	mulai:
	system("cls");
	printf ("=========================\n");
	printf("Menu Program Linked List\n");
	printf("-------------------------\n");
	printf("1. Tambah Slide\n");
	printf("2. Hapus Slide \n");
	printf("3. Tampil Slide\n");
	printf("4. Keluar\n");
	printf("Masukkan Pilihan [1-4]: ");
	scanf("%d", &pilih);
	switch (pilih) {
	case 1 :
		printf("\nTambah Slide\n\n");
		x.No++;
		printf("Slide %d \n", x.No);
		printf("Masukkan Judul: ");
		scanf ("%s", &x.judul);
		printf("Masukkan Isi: ");
		scanf ("%s", &x.Isi); 
		buatSimpul(x);
		insertDepan();
		goto mulai;
		break;
	case 2 :
		printf("\nHapus Slide\n");
		deleteDepan();
		goto mulai;
		break;
	case 3 :
		printlist();
		goto mulai;
		break;
	case 4 :
		break;
	default:
		printf("pilihan tidak ada\n");
		goto mulai;
	}
}
