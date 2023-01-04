/* File : listsirkuler.h */
/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan address adalah pointer */
/* infotype adalah integer */

/*
#ifndef listsirkuler_H
#define listsirkuler_H

#include "boolean.h"

#define Nil NULL

typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
} ElmtList;
typedef struct {
	address First;
} List;
*/
/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

/* Notasi Akses 
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)
*/
#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
# include "listsirkuler.h"
# include <stdio.h>
# include <stdlib.h>



// typedef int infotype;
// typedef struct tElmtlist *address;
// typedef struct tElmtlist { 
// 	infotype info;
// 	address next;
// } ElmtList;
// typedef struct {
// 	address First;
// } List;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list: jika addressnya Last, maka Next(Last)=First(L) */

// /* Notasi Akses */
// #define Info(P) (P)->info
// #define Next(P) (P)->next
// #define First(L) ((L).First)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
/* Mengirim true jika list kosong. Lihat definisi di atas. */
{
    return (First(L) == Nil);
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
/* I.S. L sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
{
    First(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka Info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
    address P = (address) malloc (sizeof(ElmtList));
    if (P != Nil) 
    {
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

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
/* Mencari apakah ada elemen list dengan Info(P)= X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
{
    address P = First(L);
    while (Next(P) != First(L))
    {
        if (Info(P) == X)
        {
            return P;
        }
        P = Next(P);
    }
    if (Info(P) == X)
    {
        return P;
    }
    else
    {
        return Nil;
    }
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
{
    address P = Alokasi(X);
    InsertFirst(L, P);
}
void InsVLast (List *L, infotype X)
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
{
    address P = Alokasi(X);
    InsertLast(L, P);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype * X)
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
{
    address P = First(*L);
    *X = Info(P);
    DelFirst(L, &P);
    Dealokasi(P);
}
void DelVLast (List *L, infotype * X)
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
{
    address P = First(*L);
    while (Next(P) != First(*L))
    {
        P = Next(P);
    }
    *X = Info(P);
    DelLast(L, &P);
    Dealokasi(P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Next(P) = P;
    }
    else
    {
        address Last = First(*L);
        while (Next(Last) != First(*L))
        {
            Last = Next(Last);
        }
        Next(P) = First(*L);
        First(*L) = P;
        Next(Last) = P;
    }
}
void InsertLast (List *L, address P)
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
{
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Next(P) = P;
    }
    else
    {
        address Last = First(*L);
        while (Next(Last) != First(*L))
        {
            Last = Next(Last);
        }
        Next(Last) = P;
        Next(P) = First(*L);
    }
}
void InsertAfter (List *L, address P, address Prec)
/* I.S. Prec pastilah elemen list dan bukan elemen terakhir, */
/*      P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
{
    Next(P) = Next(Prec);
    Next(Prec) = P;
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if (Next(First(*L)) == First(*L))
    {
        First(*L) = Nil;
    }
    else
    {
        address Last = First(*L);
        while (Next(Last) != First(*L))
        {
            Last = Next(Last);
        }
        First(*L) = Next(First(*L));
        Next(Last) = First(*L);
    }
}
void DelLast (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, */
/* jika ada */
{
    *P = First(*L);
    if (Next(First(*L)) == First(*L))
    {
        First(*L) = Nil;
    }
    else
    {
        address Last = First(*L);
        while (Next(Next(Last)) != First(*L))
        {
            Last = Next(Last);
        }
        *P = Next(Last);
        Next(Last) = First(*L);
    }
}
void DelAfter (List *L, address *Pdel, address Prec)
/* I.S. List tidak kosong. Prec adalah anggota list  */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
{
    *Pdel = Next(Prec);
    Next(Prec) = Next(Next(Prec));
}

void DelP (List *L, infotype X)
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* Maka P dihapus dari list dan di-dealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */
{
    address P = First(*L);
    if (Info(P) == X)
    {
        DelFirst(L, &P);
        Dealokasi(P);
    }
    else
    {
        while (Next(P) != First(*L) && Info(Next(P)) != X)
        {
            P = Next(P);
        }
        if (Next(P) != First(*L))
        {
            Next(P) = Next(Next(P));
        }
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintInfo (List L)
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
{
    address P = First(L);
    printf("[");
    if (!IsEmpty(L))
    {
        while (Next(P) != First(L))
        {
            printf("%d,", Info(P));
            P = Next(P);
        }
        printf("%d", Info(P));
    }
    printf("]");
}
