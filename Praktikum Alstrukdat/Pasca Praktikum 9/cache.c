
#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

void deleteAt(List *l, int idx, infotype *val){
    int angka;
    address alamat, lokasi ;
    if (idx == 0) {
        DelVFirst(l,val);
    }
    else {
        angka = 0;
        lokasi = First(*l);
        while (angka < idx - 1) {
            angka ++ ;
            lokasi = Next(lokasi) ;
        }
        alamat = Next(lokasi);
        *val= Info(alamat);
        Next(lokasi) = Next(alamat);
        Dealokasi(&alamat);
    }
}

int main() {
    List L ;
    infotype val;
    address sekarang;
    CreateEmpty(&L);
    boolean found;
    int N, Q,x, i,j,indeks;
    scanf("%d", &N);
    scanf("%d", &Q);
    for (i=1 ; i <= N ; i++) {
        InsVLast(&L, i) ;
    }
    for (j=0;j<Q;j++) {
        scanf("%d", &x);
        found = false ; //proses pencarian x dalam list
        sekarang = First(L);
        indeks = 0;
        while (sekarang != NULL && !found) {
            if(Info(sekarang) == x) {
                found = true;
            }
            else{
                sekarang = Next(sekarang);
                indeks++ ;
            }
        }
        if (found == true) {
            deleteAt(&L, indeks, &val);
            InsVFirst(&L, x) ;
            printf("hit ");
            PrintInfo (L);
            printf("\n");
        }
        else {
            DelVLast(&L, &val) ;
            InsVFirst(&L, x) ;
            printf("miss ");
            PrintInfo (L);
            printf("\n");
        }
    }
    return 0;
}