#include "MinMax.h"

List MinMax(List L){
    List nL;
    nL = MakeList();
    for (int j = FirstIdx(L) ; j<=LastIdx(L) ; j++ ){
        nL.A[j] = L.A[j];
    }

    int max , min;
    max = FirstIdx(L);
	min = FirstIdx(L);
    IdxType i;
    for(i = FirstIdx(L) ; i<=LastIdx(L) ; i++){
        if (L.A[i] > L.A[max]){
            max = i;
        }
        else if (L.A[i] < L.A[min]){
            min = i;
        }
    }
    int tempMax = L.A[max];
    int tempMin = L.A[min];

    if (max < min){
        DeleteAt(&nL , min);
        DeleteAt(&nL , max);
    } 
    else {
        DeleteAt(&nL , max);
        DeleteAt(&nL , min);
    }

    InsertLast(&nL , tempMin);
    InsertLast(&nL , tempMax);

    return nL;

}


