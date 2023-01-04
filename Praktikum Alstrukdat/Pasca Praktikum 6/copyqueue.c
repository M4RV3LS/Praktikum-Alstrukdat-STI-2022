#include "copyqueue.h"
#include<stdio.h>
#include <stdio.h>

// Menyalin queue.
/*
void copyQueue(Queue *queueInput, Queue *queueOutput){
  Queue temp;
  ElType val;
  CreateQueue(&temp);
  for (int i = 0 ; i<length(*queueInput);i++){
    dequeue(queueInput,&val);
    enqueue(queueOutput,val);
    enqueue(&temp,val);
  }
  for (int j = 0 ; j<length(*queueOutput);j++){
    dequeue(&temp,&val);
    enqueue(queueInput,val);
  }
  displayQueue(*queueInput);
  displayQueue(*queueOutput);
}*/
/*
void copyQueue(Queue *queueInput, Queue *queueOutput){
  ElType val;
  for(int i = 0;i<length;i++){
    dequeue(&queueInput,&val);
    enqueue(&queueInput,val);
    enqueue(&queueOutput,val);
  }
}*/
void copyQueue(Queue *queueInput, Queue *queueOutput){
  *queueOutput = *queueInput;}
/* Proses: Menyalin isi dari queueInput ke queueOutput */
/* I.S. queueInput mungkin kosong, tabel penampung elemen queueInput TIDAK penuh */
/* F.S. queueOutput memiliki isi queue yang sama */
/*
    Contoh input:
    queueInput : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
    queueOutput: queue kosong

    Contoh output:
    queueInput:  [2,3,4,5,6]
    queueOutput: [2,3,4,5,6]
*/

/*
    Catatan
    - Hati-hati jangan sampai algoritma Anda mengubah hasil akhir dari queueInput juga.
      Elemen di queueInput harus tetap sama setelah algoritma dijalankan.
    Hint
    - Buat queue baru selain queueInput dan queueOutput untuk tempat penyimpanan
      queueInput sementara.
*/