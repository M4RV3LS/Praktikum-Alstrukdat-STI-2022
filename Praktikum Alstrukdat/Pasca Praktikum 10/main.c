#include "listsirkuler.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    List L;
    CreateEmpty(&L);
    //printf("%d\n", IsEmpty(L));

    /*Test Case Insert First param value*/
    //InsVFirst (&L, 1);
    //InsVLast(&L , 2);
    //InsVLast(&L , 3);
    //PrintInfo(L);
    //printf("\n");

    /*Search*/
    //address P = Search(L , 2);
    //printf("%d\n",Info(P));
    
    /*Delete*/
    //infotype X;
    //DelVFirst (&L, &X);
    //printf("%d\n",X);
    //PrintInfo(L);
    //printf("\n");
    //DelVLast (&L, &X);
    //printf("%d\n",X);
    //PrintInfo(L);
    //address P = Alokasi(5);
    //InsertLast(&L , P);

    /*Insert dengan address*/
    address Q = Alokasi(2);
    InsertFirst(&L , Q);
    PrintInfo(L);
    printf("\n");
    address P = Alokasi(1);
    InsertFirst(&L,P);
    PrintInfo(L);
    printf("\n");
    address R= Alokasi(3);
    InsertLast(&L , R);
    PrintInfo(L);
    printf("\n");
    address S = Alokasi(4);
    InsertAfter(&L,S,R);
    PrintInfo(L);
    printf("\n");
    //DelFirst(&L,&P);
    //printf("%d\n",Info(First(L)));
    //PrintInfo(L);
    //printf("\n");
    //DelLast(&L,&S);
    //PrintInfo(L);
    //printf("\n");
    address del;
    DelAfter(&L,&del,R);
    printf("%d\n",Info(del));
    PrintInfo(L);
    printf("\n");
    DelP(&L , 5);
    PrintInfo(L);
    printf("\n");
    return 0;
}