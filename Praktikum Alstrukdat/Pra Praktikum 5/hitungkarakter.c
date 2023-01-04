#include "mesinkarakter.h"
#include <stdio.h>

int hitungkarakter(char karakter){
    int jumlahcc = 0;
    START();
    while (!IsEOP()) {
        if(GetCC() == karakter ){
            jumlahcc += 1;
        }
        ADV();
    }
    return jumlahcc ;
}