/* File: vector.h */
/* Tanggal: 29 Agustus 2019 
#include "point.h"

#ifndef VECTOR_H
#define VECTOR_H
*/
/* *** Definisi ABSTRACT DATA TYPE VECTOR *** 
#define VECTOR POINT*/
/* *** Notasi Akses: Selektor VECTOR *** 
#define AbsisComponent(V) Absis(V)
#define OrdinatComponent(V) Ordinat(V)*/
#include <stdio.h>
#include "vector.h"
#include <math.h>
/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk VECTOR *** */
VECTOR MakeVector(float x, float y){
    VECTOR v;
    AbsisComponent(v) = x ;
    OrdinatComponent(v) = y;
    return v;
}

/* Membentuk sebuah VECTOR dengan komponen absis x dan
   komponen ordinat y */

/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisVector(VECTOR v){
    printf("<%.2f,%.2f>", AbsisComponent(v), OrdinatComponent(v) );
}
/* Nilai v ditulis ke layar dengan format "<X,Y>"
   tanpa spasi, enter, atau karakter lain di depan, belakang, atau di antaranya
   Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
*/
/* I.S. v terdefinisi */
/* F.S. v tertulis di layar dengan format "<X,Y>" */

/* *** KELOMPOK OPERASI LAIN TERHADAP TYPE *** */
float Magnitude(VECTOR v){
    return sqrt((AbsisComponent(v)*AbsisComponent(v))+(OrdinatComponent(v)*OrdinatComponent(v)));
}
/* Menghasilkan magnitudo dari vector, yakni sqrt(v.x^2+v.y^2) */
VECTOR Add(VECTOR a, VECTOR b){
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
    return v;
}
/* Menghasilkan sebuah vector yang merupakan hasil a + b.
   Komponen absis vector hasil adalah vector pertama
   ditambah vector kedua, begitu pula dengan ordinatnya */
VECTOR Substract(VECTOR a, VECTOR b){
    VECTOR v;
    AbsisComponent(v) = AbsisComponent(a) + AbsisComponent(b);
    OrdinatComponent(v) = OrdinatComponent(a) + OrdinatComponent(b);
    return v;
}
/* Menghasilkan sebuah vector yang merupakan hasil a - b.
   Komponen absis vector hasil adalah vector pertama
   dikurangi vector kedua, begitu pula dengan ordinatnya */
float Dot(VECTOR a, VECTOR b){
    return (AbsisComponent(a)*AbsisComponent(b) + OrdinatComponent(a)*OrdinatComponent(b)) ;
}
/* Menghasilkan perkalian dot vector, yakni a.x * b.x + a.y * b.y */
VECTOR Multiply(VECTOR v, float s){
    AbsisComponent(v) = AbsisComponent(v) * s ; 
    OrdinatComponent(v) = OrdinatComponent(v)* s ;
    return v;
}
/* Menghasilkan perkalian skalar vector dengan s, yakni
   (s * a.x, s * a.y) */

