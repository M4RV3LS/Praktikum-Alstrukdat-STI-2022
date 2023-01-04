#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "boolean.h"


int main(){
    Stack S1;
    int temp;
    CreateEmpty(&S1);
    scanf("%d",&temp);
    if(temp==0){
        printf("Stack kosong\n");
    }
    else {
        boolean palindrom = true;
        while(temp!=0 && Top(S1) < MaxEl){
            Push(&S1,temp);
            scanf("%d",&temp);
        }
        for (int i = 0 ; i <= Top(S1) ; i++)
        {
            if (S1.T[i] != S1.T[Top(S1) - i])
            {
                palindrom = false;
            }
        }

        if (palindrom)
        {
            printf("Palindrom\n");
        }

        else
        {
            printf("Bukan Palindrom\n");
        }
    }
    return 0;
    
}