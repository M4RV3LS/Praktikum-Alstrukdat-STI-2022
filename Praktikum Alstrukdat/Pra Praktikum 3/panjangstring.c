#include "panjangstring.h"

// menerima argumen pointer kepada karakter pertama dari sebuah string yang panjangnya tidak diketahui
// dan memberikan output berupa panjang string tersebut, dengan batasan string input memiliki karakter
// '\0' pada akhir string
int panjangString(char*str){
    int length = 0;
    while (*(str + length) != '\0'){
        length += 1;
    }    
    return length;
}