#include <stdio.h>
#include <stdlib.h>

int main(){
    int n , i , j;
    scanf("%d",&n);
    n = (2 * n) - 1;
    for(i=1 ; i<=n ;i++){
        for(j=1 ; j<=n ; j++){
            if (((i%2)== 1) && ((j%2)== 1)){
                printf(("O"));
            }
            else if (((i%2)== 1) && ((j%2)== 0)){
                printf(("X"));
            }
            else if (((i%2)== 0) && ((j%2) == 1)){
                printf(("X"));
            }
            else {
                printf(("O"));
            }
        }
        printf("\n");
    }
    return 0;
}