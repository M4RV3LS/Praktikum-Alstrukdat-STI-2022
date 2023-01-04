#include <stdio.h>

int main (){
    unsigned int bil ;
    scanf("%u",&bil);
    if ((bil > 0) && (bil <= 100)) {
        if ((bil%2)==0) {
            if (((bil/2)%2)==0) {
                printf("Ya\n");
            }
            else {
                printf("Tidak\n");
            }
        }
        else {
            printf("Tidak\n");
        }
    }
    else {
            printf("Tidak\n");
        }
    
}