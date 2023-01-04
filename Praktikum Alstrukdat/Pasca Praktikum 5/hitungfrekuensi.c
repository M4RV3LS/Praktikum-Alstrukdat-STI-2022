#include <stdio.h>
#include <stdlib.h>
#include "hitungfrekuensi.h"

int hitungfrekuensi(){
    char t ='0' ; 
    char i ='0' ;
    char g ='0' ;
    char a ='0' ;
    int count = 0;
    START();
    while(!IsEOP()){
        t = i ;
        i = g ; 
        g = a ; 
        a = GetCC();
        if ((t == 't' || t == 'T') && (i == 'i' || i == 'I') && (g == 'g' || g == 'G') && (a == 'a' || a == 'A')){
            count = count + 1;
        }
        ADV();
    }
return count;
}