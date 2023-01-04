#include "tanpaBomb.h"

Queue tanpaBomb(Queue queue, ElType bomb){
    Queue temp;
    ElType val;
    CreateQueue(&temp);
    for(int i = 0;i <length(queue);i++){
        if(val != bomb){
            dequeue(&queue,&val);
            enqueue(&temp,val);
        }
        else{
            dequeue(&queue,&val);
        }
    IDX_HEAD(queue) = 0; 
    }
    for(int j = 0;j <length(temp);j++){
        dequeue(&temp,&val);
        enqueue(&queue,val);
    }
    return queue;
}
/* Mengembalikan sebuah queue yang sudah tidak memiliki nilai bomb */

/*
    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 3
    Contoh output: [2,4,5,6]

    Contoh input:
        queue : [2,3,4,5,6] // 2 adalah head, 6 adalah tail
        bomb : 7
    Contoh output: [2,3,4,5,6]

*/
