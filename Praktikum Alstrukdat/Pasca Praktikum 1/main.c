#include <stdio.h>

int main(){
    /*Kamus Lokal*/
    int detik , HH , MM , SS , sisa;
    
    /*Algoritma*/
    scanf("%d" , &detik);
    HH = detik / 3600 ;
    sisa = detik % 3600;
    MM = sisa / 60 ;
    SS = sisa % 60 ;
    printf("%d detik = %d jam %d menit %d detik\n" ,detik , HH , MM , SS);
    return 0; 
}