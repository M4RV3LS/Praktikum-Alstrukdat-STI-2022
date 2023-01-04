#ifndef TIME_H
#define TIME_H

typedef struct{
    int HH;
    int MM;
    int SS;
}jam;

/*Prototype*/
void TulisJam (jam J);
/*Menulis Sebuah jam*/
jam DetikToJam(int d);
/*Konversi detik to jam*/
#endif TIME_H