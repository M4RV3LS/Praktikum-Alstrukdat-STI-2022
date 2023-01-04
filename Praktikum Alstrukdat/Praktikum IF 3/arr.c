#include <stdio.h>

int main(){
    int *ptr;
    int n , i;
    printf("Masukan Nilai N : ");
    scanf("%d" , &n);
    ptr = (int *)malloc(n*sizeof(int));
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {
 
        // Memory has been successfully allocated
    
        printf("Memory successfully allocated using malloc.\n");}
    
    for (i = 0 ; i < n ; i++){
        printf("Masukkan nilai array ke - %d : " , (i + 1));
        scanf("%d",&ptr[i]);
    }
    printf("The elements of the array are: ");
    for (i = 0; i < n; ++i) {
            printf("%d ", ptr[i]);
        }
    return 0;
}