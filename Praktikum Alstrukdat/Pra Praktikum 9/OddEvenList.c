#include "OddEvenList.h"
#include <stdio.h>
#include <stdlib.h>



void OddEvenList(List L, List *Odd, List *Even){
    /*
    CreateEmpty(Odd);
    CreateEmpty(Even);
    address p = First(L);
    while(p != Nil){
        address node = Alokasi(Info(p))
        if((Info(p) % 2) = 1) //ganjil
        {   boolean found = false;
            address pOdd = First(*Odd);
            if(IsEmpty(*Odd)){
                InsertFirst ( *Odd, address P);
            }
            else{
                while (!found && (pOdd != Nil)){
                    if(Next(pOdd) == Nil){
                        InsertLast (*Odd,node);
                    }
                    else if(Info(p)<=Next(Info(Odd))){
                        found = true;
                        InsertAfter (*Odd, node, pOdd);
                    }
                }
            }
        }
        else //genap
        {
            address pEven = First(Even);
        }
        p = Next(p);
    }
    */
    List temp;
    CreateEmpty(&temp);
    CreateEmpty(Even);
    CreateEmpty(Odd);

    /*Copy*/
    address P = First(L);
    while (P != Nil){
        InsVLast (&temp, Info(P));
        P = Next(P);
    }

    int min;
    while(!IsEmpty(temp)){
        min = Min(temp);
        if((min%2) == 1){
            InsVLast(Odd,min);
        }
        else
            {
                InsVLast(Even,min);
            }
        DelP(&temp,min);
    }
}
    /* Memisahkan elemen ganjil dan genap dari list L kedalam dua list baru secara mengurut membesar*/
    /* I.S: List L TIDAK mungkin kosong dan memiliki nilai lebih dari sama dengan 0(value>=0), List Odd dan Even kosong*/
    /* F.S: List Odd memiliki elemen bernilai ganjil mengurut membesar, List Even memiliki elemen bernilai genap mengurut membesar
            List L TIDAK PERLU DIDEALOKASI*/
    /*Contoh:
        Input:
            L: [0,3,1,4,5]
            Odd: []
            Even: []
        Output:
            L: [0,3,1,4,5]
            Odd: [1,3,5]
            Even: [0,4] */
    /*Note: 
        1. Bilangan 0 merupakan bilangan genap
        2. Buatlah List Odd dan Even terlebih dahulu*/
 
