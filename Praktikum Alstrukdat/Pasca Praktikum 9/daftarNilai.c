#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

int main(){
    List L;
    CreateEmpty(&L);
    int temp ;
    scanf("%d",&temp);
    while(temp >= 0 && temp <= 100)
    {
        InsVLast(&L,temp);
        scanf("%d",&temp);
    }
    if(IsEmpty(L))
    {
        printf("Daftar nilai kosong\n");
    }
    else
    {
        printf("%d\n",NbElmt(L));
        printf("%d\n",Max(L));
        printf("%d\n",Min(L));
        printf("%.2f\n",Average(L));
        PrintInfo(L);
        printf("\n");
        InversList(&L);
        PrintInfo(L);
        printf("\n");
    }
    


    return 0;
}