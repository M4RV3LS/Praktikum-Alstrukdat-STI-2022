#include <stdio.h>

int main(){
    int bil , temp;
    int sum = 0;
    scanf("%d",&bil);
    temp = bil % 10;
    while(bil > 0){
        sum += temp;
        bil /= 10;
        temp = bil % 10;
    }
    printf("%d\n",sum);
    return 0;
}
