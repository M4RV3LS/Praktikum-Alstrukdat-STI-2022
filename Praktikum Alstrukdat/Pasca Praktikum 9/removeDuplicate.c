#include "removeDuplicate.h"
#include <stdio.h>
#include <stdlib.h>

List removeDuplicate(List l){
    /*
    address p = First(l);
    address b = Next(Next(p));
    if(!IsEmpty(l)){
        int a = Info(p) // inisiasi nilai yang ingin dihapus
        while(p!= Nil){
            address temp = Next(p);
            while(int a == Info(temp)){
                DelAfter (l, &Ptemp, p);
        }

    }
    }
    */
    // list temp;
    address p = First(l);
     if(!IsEmpty(l)){
        int a = Info(p); // inisiasi nilai yang ingin dihapus 
        p = Next(p);
        while (p!= Nil){
            if(Info(p) == a){
                DelP(&l , a);
            }
            else if(Info(p) != a){
                a = Info(p);
            }
            p = Next(p);
        }
     }
     return l;
}
     

/*
    Diberikan sebuah list linier yang sudah terurut membesar,
    kembalikan list baru yang elementnya unik
    Contoh input/output:
    input:  [1,1,2,2,3,4,5,6,6,7]
    output: [1,2,3,4,5,6,7]

    input:  [1,1,1,1,1,1]
    output: [1]
*/
/*Test case
int main(){
    List L ;
    CreateEmpty(&L);
    int N;
    scanf("%d",&N);
    for (int i=1 ; i <= N ; i++) {
        int input;
        scanf("%d",&input);
        InsVLast(&L, input) ;
    }
    printf("List sebelum : ");
    PrintInfo (L);
    printf("\n");
    removeDuplicate(L);
    printf("List sesudah : ");
    PrintInfo (L);
    printf("\n");
}
*/