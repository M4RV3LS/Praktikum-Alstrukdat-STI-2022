#include <stdio.h>

int main(){
    int n , reverseN = 0 , temp;
    scanf("%d", &n);

    while (n != 0){
        temp = n % 10;
        printf("ini nilai Temp: %d\n",temp);
        reverseN = reverseN * 10 + temp;
        printf("ini nilai reverseN: %d\n", reverseN);
        n /= 10;
        printf("ini nilai n: %d\n", n);
    }
    printf("%d\n",reverseN);

    return 0;
}