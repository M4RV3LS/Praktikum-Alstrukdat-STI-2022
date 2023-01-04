#include <stdio.h>

int main(){
    int N , M , temp, i , j , k , check;
    int sum[100];
    k = 0;
    check = 0;

    scanf("%d" , &N);

    for (i=0; i<N; i++){
        sum[i] = 0;
    }

    for (i = 0 ; i<N ; i++){
        scanf("%d", &M);
        for (j=1; j<=M; j++){
            if(j%7 == 0){
                sum[k] += j;
            }
            else {
                temp = j;
                while (temp !=0){
                    if (temp%10 ==7){
                        check = 1;
                    }
                    temp /= 10;
                }
                if (check == 1){
                    sum[k] += j;
                    check = 0;
                }
            }

        }
        k += 1;

    }
    for (i=0 ; i<N; i++){
            printf("%d\n",sum[i]);
        }
    
    return 0;
}