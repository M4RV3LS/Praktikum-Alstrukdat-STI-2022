#include "listdp.h"
#include <stdio.h>
#include <stdlib.h>

/*
#ifndef listdp_H
#define listdp_H

#include "boolean.h"

#define Nil NULL*/

/* Definisi Type Data 
typedef int infotype;
typedef struct tElmtlist *address;
typedef struct tElmtlist { 
	infotype info;
	address next;
	address prev;
} ElmtList;
typedef struct {
	address First;
	address Last;
} List;*/

/* Definisi list : */
/* List kosong : First(L) = Nil dan Last(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P), Prev(P) */
/* Elemen terakhir list: Last(L) */

/* Notasi Akses 
#define Info(P) (P)->info
#define Next(P) (P)->next
#define Prev(P) (P)->prev
#define First(L) ((L).First)
#define Last(L) ((L).Last)*/
/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean IsEmpty (List L)
{
/* Mengirim true jika list kosong. Lihat definisi di atas. */
    return ((First(L) == Nil) && (Last(L) == Nil));
}

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateEmpty (List *L)
{
/* I.S. L sembarang  */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */
    First(*L) = Nil;
    Last(*L) = Nil;
}

/****************** Manajemen Memori ******************/
address Alokasi (infotype X)
{
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil. */
/* Misalnya: menghasilkan P, maka Info(P)=X, Next(P)=Nil, Prev(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil. */
    address P;
    P = (address) malloc(1 * sizeof(ElmtList)); 
    if (P != NULL) {
        Info(P) = X;
        Next(P) = Nil;
        Prev(P) = Nil;
    }
    return P;
}

void Dealokasi (address P)
{
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */
    free(P);
}

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
address Search (List L, infotype X)
{
/* Mencari apakah ada elemen list dengan Info(P)=X */
/* Jika ada, mengirimkan address elemen tersebut. */
/* Jika tidak ada, mengirimkan Nil */
    address P;
    boolean Found = false;
    P = First(L);
    while(P != NULL && !Found) {
        if(Info(P) == X) {
            Found = true;
        }
        else{
            P = Next(P);
        }
    }
    return P;
}

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void InsVFirst (List *L, infotype X)
{
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai X jika alokasi berhasil */
    address P = Alokasi(X);
    InsertFirst(L,P);
}

void InsVLast (List *L, infotype X)
{
/* I.S. L mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai X jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
    address P = Alokasi(X);
    InsertLast(L,P);
}

/*** PENGHAPUSAN ELEMEN ***/
void DelVFirst (List *L, infotype *X)
{
/* I.S. List L tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen pertama di-dealokasi */
    address P;
    DelFirst(L,&P);
    *X = Info(P);
    Dealokasi(P);
}

void DelVLast (List *L, infotype *X)
{
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada X */
/*      dan alamat elemen terakhir di-dealokasi */
    address P;
    DelLast(L,&P);
    *X = Info(P);
    Dealokasi(P);
}
/****************** PRIMITIF BERDASARKAN ALAMAT ******************/
/*** PENAMBAHAN ELEMEN BERDASARKAN ALAMAT ***/
void InsertFirst (List *L, address P)
{
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. Menambahkan elemen ber-address P sebagai elemen pertama */
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(P) = First(*L);
        Prev(First(*L)) = P;
        First(*L) = P;
    }

}
void InsertLast (List *L, address P)
{
/* I.S. Sembarang, P sudah dialokasi  */
/* F.S. P ditambahkan sebagai elemen terakhir yang baru */
    if (IsEmpty(*L))
    {
        First(*L) = P;
        Last(*L) = P;
    }
    else
    {
        Next(Last(*L)) = P;
        Prev(P) = Last(*L);
        Last(*L) = P;
    }
}

void InsertAfter (List *L, address P, address Prec)
{
/* I.S. Prec pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sesudah elemen beralamat Prec */
    if (Next(Prec) != Nil)
    {
        Prev(Next(Prec)) = P;
    }
    else
    {
        Last(*L) = P;
    }
    Next(P) = Next(Prec);
    Prev(P) = Prec;
    Next(Prec) = P;
}

void InsertBefore (List *L, address P, address Succ)
{
/* I.S. Succ pastilah elemen list; P sudah dialokasi  */
/* F.S. Insert P sebagai elemen sebelum elemen beralamat Succ */
    if (Prev(Succ) != Nil)
    {
        Next(Prev(Succ)) = P;
    }
    else
    {
        First(*L) = P;
    }
    Prev(P) = Prev(Succ);
    Prev(Succ) = P;
    Next(P) = Succ;
    
}

/*** PENGHAPUSAN SEBUAH ELEMEN ***/
void DelFirst (List *L, address *P)
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen pertama list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* First element yg baru adalah suksesor elemen pertama yang lama */
{
    *P = First(*L);
    if (Next(First(*L)) == Nil)
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        First(*L) = Next(First(*L));
        Prev(First(*L)) = Nil;
        Next(*P) = Nil;
    }
}

void DelLast (List *L, address *P)
{
/* I.S. List tidak kosong */
/* F.S. P adalah alamat elemen terakhir list sebelum penghapusan  */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/* Last element baru adalah predesesor elemen pertama yg lama, jika ada */

    *P = Last(*L);
    if (Prev(Last(*L)) == Nil)
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    else
    {
        Last(*L) = Prev(Last(*L));
        Next(Last(*L)) = Nil;
        Prev(*P) = Nil;
    }
}


void DelP (List *L, infotype X)
{
/* I.S. Sembarang */
/* F.S. Jika ada elemen list beraddress P, dengan Info(P)=X  */
/* maka P dihapus dari list dan didealokasi */
/* Jika tidak ada elemen list dengan Info(P)=X, maka list tetap */
/* List mungkin menjadi kosong karena penghapusan */

    address P;
    P = First(*L);
    boolean found = false;
    /* One Element */
    if ((Info(P) == X) && (Next(P) == Nil))
    {
        First(*L) = Nil;
        Last(*L) = Nil;
    }
    /* > 1 element */
    else 
    {
        while ((P != Nil) && (!found))
        {
            if(Info(P) == X)
            {
                found = true;
            }
            else
            {
                P = Next(P);
            }
        }
        /* Ketemu dan bukan di akhir*/
        if ((found) && (P != Last(*L)))
        { 
            address loc = Next(P);
            DelBefore(L,&P,loc);
        }
        /* Ketemu di akhir*/
        else if ((found) && (P == Last(*L)))
        {
            Last(*L) = Prev(Last(*L));
            Next(Last(*L)) = Nil;
            Prev(P) = Nil;
        }
    }
    Dealokasi(P);
}



void DelAfter (List *L, address *Pdel, address Prec)
{
/* I.S. List tidak kosong. Prec adalah anggota list. */
/* F.S. Menghapus Next(Prec): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    
    *Pdel = Next(Prec);
    if (*Pdel != Nil)
    {
        if (Next(*Pdel) != Nil)
        {
            Prev(Next(*Pdel)) = Prec;
        }
        else
        {
            Last(*L) = Prec;
        }
        Next(Prec) = Next(Next(Prec));
        Prev(*Pdel) = Nil;
        Next(*Pdel) = Nil;
    }
}


void DelBefore (List *L, address *Pdel, address Succ)
{
/* I.S. List tidak kosong. Succ adalah anggota list. */
/* F.S. Menghapus Prev(Succ): */
/*      Pdel adalah alamat elemen list yang dihapus  */
    *Pdel = Prev(Succ);
    if (*Pdel != Nil)
    {
        if (Prev(*Pdel) != Nil)
        {
            Next(Prev(*Pdel)) = Succ;
        }
        else
        {
            First(*L) = Succ;
        }
        Prev(Succ) = Prev(Prev(Succ));
        Prev(*Pdel) = Nil;
        Next(*Pdel) = Nil;
    }
}

/****************** PROSES SEMUA ELEMEN LIST ******************/
void PrintForward (List L)
{
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen pertama */
/* ke elemen terakhir secara horizontal ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    address P = First(L);
    if (P != Nil)
    {
        printf("%d",Info(P));
        P = Next(P);
        while (P != Nil)
        {
            printf(",%d",Info(P));
            P = Next(P);
        }
    }
    printf("]");
}

void PrintBackward (List L)
{
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, isi list dicetak dari elemen terakhir */
/* ke elemen pertama secara horizontal ke kanan: [en,en-1,...,e2,e1] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [30,20,1] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
    printf("[");
    address P = Last(L);
    if (P != Nil)
    {
        printf("%d",Info(P));
        P = Prev(P);
        while(P != Nil)
        {
            printf(",%d",Info(P));
            P = Prev(P);
        }
    }
    printf("]");
}