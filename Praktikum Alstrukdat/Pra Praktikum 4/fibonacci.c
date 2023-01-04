
// Deret bilangan fibonacci adalah deret angka yang susunan angkanya
// merupakan penjumlahan dari dua angka sebelumnya.
// Contoh:
// Fib 0: 1
// Fib 1: 1
// Fib 2: 1 + 1 = 2
// Fib 3: 2 + 1 = 3
// Fib 4: 3 + 2 = 5
// Fib 5: 5 + 3 = 8

#include "fibonacci.h"

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci ke argumen result
// Contoh:
// n = 5
// Nilai argumen result = 8
void fibonacci1(int n, int *result){
    int i,j,hasil , loop;
    i = 1;
    j = 1;
    loop = 0;
    hasil = i + j;
    if (n == 0 || n == 1){
        *result = 1;
    }
    else if (n == 2){
        *result = 2;
        }
    else{
        while (loop < (n - 2)){
            i = j ;
            j = hasil ; 
            hasil = i + j ;
            loop += 1 ;
        }
        *result = hasil;
    }

} 
        
    

// Menerima argument sebuah integer n dan mengembalikan
// nilai suku ke-n dari deret fibonacci
int fibonacci2(int n){
    int i,j,hasil , loop;
    i = 1;
    j = 1;
    loop = 0;
    hasil = i + j;
    if (n == 0 || n == 1){
        hasil = 1;
    }
    else if (n == 2){
        hasil = 2;
        }
    else {
        while (loop < (n - 2)){
            i = j ;
            j = hasil ; 
            hasil = i + j ;
            loop += 1 ;
        } 
    }
    return hasil;
        
}

// Menerima argument sebuah integer n
// Output adalah argumen result yang bertipe pointer int digunakan sebagai array
// Tuliskan semua nilai deret fibonacci dari 0 - n ke argumen result
// n = 5
// result = [1, 1, 2, 3, 5, 8]
void fibonacci3(int n, int *result){
    int i = 0;
    while (i<=n){
       *result = fibonacci2(i);
       result++;
        i++;
    }

}

