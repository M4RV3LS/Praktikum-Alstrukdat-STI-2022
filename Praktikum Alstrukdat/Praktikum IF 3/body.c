#include "time.h"

void TulisJam (jam J)
/*Menulis Sebuah jam*/
{
    /*Kamus*/
    /*Algoritma*/
    printf("%d jam %d menit %d detik", J.HH , J.MM , J.SS);

}
jam DetikToJam(int d);
/*Konversi detik to jam*/
{
    /*Kamus Lokal*/
    jam J;
    int sisa;
    /*Algoritma*/
    J.HH = d / 3600;
    sisa = d % 3600;
    J.MM = sisa / 60;
    J.SS = sisa % 60;
    return J;
}