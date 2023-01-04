#include <stdio.h>
#include "reverse.h"

void transferReverse(Queue* q1, Queue* q2){
    ElType val;
    int nElemen = Length(*q1);
    for(int i = 0 ; i < nElemen - 1 ; i++){
        val = (*q1).Tab[(*q1).TAIL];
        Push(q2,val);
        (*q1).TAIL = ((*q1).TAIL - 1 + MaxLength(*q1)) % MaxLength(*q1);
    }
    val = Pop(q1);
    Push(q2,val);


}
// Proses: Memindahkan tiap elemen q1 ke q2 dengan urutan yang terbalik
// I.S.: q1 tidak kosong, q2 kosong. q1 dan q2 memiliki panjang yang sama
// F.S.: q1 kosong, q2 berisi elemen-elemen yang tadinya milik q1 dengan urutan yang terbalik

