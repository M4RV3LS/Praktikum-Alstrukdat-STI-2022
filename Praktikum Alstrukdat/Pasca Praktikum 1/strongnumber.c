#include <stdio.h>
#include <stdlib.h>

int factorial(int i) {

   if(i <= 1) {
      return 1;
   }
   return i * factorial(i - 1);
}

int main(){
    int masukan , bil , sum , temp;
    sum = 0;
    scanf("%d",&masukan);
    bil = masukan;
    temp = bil % 10;
    while(bil>0){
        sum += factorial(temp);
        printf("ini sum : %d\n",sum);
        bil /= 10;
        printf("ini bil : %d\n",bil);
        temp = bil % 10; 
        printf("ini temp : %d\n",temp);
    }
    if (masukan != sum){
        printf("N\n");
    }
    else {
        printf("Y\n");
    }
    return 0;
}