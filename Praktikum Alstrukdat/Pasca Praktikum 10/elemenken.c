/* Tuliskan header di sini berisi nama, dll */

#include <stdio.h>
#include "listsirkuler.h"

int ElemenKeN(List L, int r) {
  /* Tuliskan implementasi di sini */
  address P = First(L);
  int i;
  for (i = 0;i < r;i++){
    P = Next(P);
  }
  return Info(P);
}

int main () {
  List L;
  int r;
  int input;
  /* Tuliskan implementasi di sini */
    CreateEmpty(&L);
    scanf("%d",&input);
    while(input!=0){
        InsVLast(&L,input);
        scanf("%d",&input);
    }
    scanf("%d",&r);
    if(!IsEmpty(L)){
        printf("%d\n", ElemenKeN(L, r));
    }
    else{
        printf("List Kosong\n");
    }
  return 0;
}