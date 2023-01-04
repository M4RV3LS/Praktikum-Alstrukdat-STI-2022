/* File: linkdummy.h */

#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>
#include "linkdummy.h"

//#define Nil NULL

/* Selektor 
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
#define Last(L) ((L).Last)
*/

/* Definisi Type Data 
typedef int ElType;
typedef struct tNode *address;
typedef struct tNode {
    ElType info;
    address next;
} Node;
typedef struct {
    address First;
    address Last;
} List;
*/

/* Definisi list: */
/* List kosong: First(L) = Last(L) = dummy@ */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen dummy terletak pada last */

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty(List L)
/* Mengirim true jika list kosong: First(L) = dummy@
dan Last(L) = dummy@ */
{
    //return (Info(First(L)) == 0 && Info(Last(L)) == 0);
    return (First(L) == Last(L));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void MakeEmpty(List *L)
/* I.S. sembarang */
/* F.S. Terbentuk list L kosong, dengan satu elemen dummy */
/* Jika gagal maka First = Last = Nil dan list gagal terbentuk */
{
    address P = Alokasi(0);
    if(P != Nil){
       First(*L) = P;
        Last(*L) = P; 
    }
    else {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
}

/****************** MANAJEMEN MEMORI ******************/
address Alokasi (ElType X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
{
    address P = (address) malloc(sizeof(Node));
    if(P!=Nil){
        Info(P) = X;
        Next(P) = Nil;
    }
    return P;
}
void Dealokasi (address P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
{
    free(P);
}
/****************** SEARCHING ******************/
address Search(List L, ElType X)
/* Mencari apakah ada node list dengan info(P) = X */
/* Jika ada, mengirimkan address node tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
address P;
/* Algoritma */
Info(Last(L)) = X; 
P = First(L);
while (Info(P) != X) {
    P = Next(P);
} 
if (P != Last(L)) { 
    return P;
} else  {
    return Nil;
}
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsertFirst(List *L, ElType X)
/* I.S. List L terdefinisi */
/* F.S. Menambahkan elemen X sebagai elemen pertama List L */
{
address P;
P = Alokasi(X);
if (P != Nil) {
Next(P) = First(*L);
First(*L) = P;
}
}

void InsertLast(List *L, ElType X)
/* I.S. List L terdefinisi */
/* F.S. X ditambahkan sebagai elemen terakhir yang baru, */
/* yaitu menjadi elemen sebelum elemen dummy */
/* Alamat elemen dummy tidak berubah */
{
address P, Last;
/* Algoritma */
if(IsEmpty(*L)) {
InsertFirst(L,X);
} 
else
{
    P = Alokasi(X);
    if (P != Nil) {
        Last = First(*L);
        while(Next(Last) != Last(*L)) {
            Last = Next(Last);
        } 
        Next(Last) = P;
        Next(P) = Last(*L);
        }
    }
}
/*** PENGHAPUSAN ELEMEN ***/
void DeleteFirst(List *L, ElType *X)
/* I.S. List tidak kosong */
/* F.S. X adalah elemen pertama list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
address P;
/* Algoritma */
P = First(*L);
*X = Info(P);
First(*L) = Next(First(*L));
free(P);
}
void DeleteLast(List *L, ElType *X)
/* I.S. List tidak kosong */
/* F.S. X adalah terakhir sebelum dummy pada list sebelum penghapusan */
/* Elemen list berkurang satu (mungkin menjadi kosong) */
{
address Last, PrecLast;
/* Algoritma */
Last = First(*L); 
PrecLast = Nil;
while (Next(Last) != Last(*L)) {
    PrecLast = Last; 
    Last = Next(Last);
}
*X = Info(Last);
if (PrecLast == Nil) { /* kasus satu elemen */
    First(*L) = Last(*L);
} else {
    Next(PrecLast) = Last(*L);
}
free(Last);
}

