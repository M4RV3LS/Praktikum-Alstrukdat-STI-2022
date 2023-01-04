/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I 

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

#include "boolean.h"
#include "mesinkarakterv2.h"

#define NMax 50
#define BLANK ' '

typedef struct
{
   char TabWord[NMax];*/ /* container penyimpan kata, indeks yang dipakai [0..NMax-1] 
   int Length;
} Word;
*/
/* State Mesin Kata 
extern boolean EndWord;
extern Word currentWord;
*/
#include <stdio.h>
#include "mesinkata.h"

boolean EndWord;
Word currentWord;

void IgnoreBlanks(){
    while(currentChar == BLANK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }
    else {
    EndWord = false;
    CopyWord();
    }
    
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    IgnoreBlanks();
    if(currentChar == MARK){
        EndWord = true;
    }
    else {
    CopyWord();
    IgnoreBlanks();
    }
    
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;
    while((currentChar != MARK) && (currentChar != BLANK)){
        if (i < NMax){
            currentWord.TabWord[i] = currentChar;
            i++ ;
        }
        ADV();
    } 
    currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */

/*
int main (){
    int i = 0;
    int max = 0;
    STARTWORD();
    while (!EndWord){
        if (currentWord.Length > max){
            max = currentWord.Length;
        }
        else {
            max = max;
        }
        ADVWORD();
    }
    return max;

    /*while (!EndWord){
        if (max = currentWord.Length){
            max = currentWord.Length;
        }
        else {
            max = max;
        }
        ADVWORD();
    }
}
*/
Word kalimatAngka (Word *kalimat){
    kalimat = (Word *)malloc(sizeof(Word));
    STARTKATA();
    
}