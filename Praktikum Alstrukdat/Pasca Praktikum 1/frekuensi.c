#include <stdio.h>
#include <string.h>

int main(){
    char alfanumerik[10];
    
    int jlh0 , jlh1 , jlh2 , jlh3 , jlh4 , 
    jlh5 , jlh6 , jlh7 , jlh8 , jlh9 , i;
    scanf("%s", &alfanumerik);
    
    jlh0 = 0;
    jlh1 = 0;
    jlh2 = 0;
    jlh3 = 0;
    jlh4 = 0;
    jlh5 = 0;
    jlh6 = 0;
    jlh7 = 0;
    jlh8 = 0;
    jlh9 = 0;

     for(i = 0; i < 10;i++)
    {
        if (alfanumerik[i] == '0')
        {
            jlh0 += 1;
        }
        else if (alfanumerik[i] == '1')
        {
            jlh1 += 1;
        }
        else if (alfanumerik[i] == '2')
        {
            jlh2 += 1;
        }
        else if (alfanumerik[i] == '3')
        {
            jlh3 += 1;
        }
        else if (alfanumerik[i] == '4')
        {
            jlh4 += 1;
        }
        else if (alfanumerik[i] == '5')
        {
            jlh5 += 1;
        }
        else if (alfanumerik[i] == '6')
        {
            jlh6 += 1;
        }
        else if (alfanumerik[i] == '7')
        {
            jlh7 += 1;
        }
        else if (alfanumerik[i] == '8')
        {
            jlh8 += 1;
        }
        else if (alfanumerik[i] == '9')
        {
            jlh9 += 1;
        }
    }
    printf("%d%d%d%d%d%d%d%d%d%d\n",jlh0,jlh1,jlh2,jlh3,jlh4,jlh5,jlh6,jlh7,jlh8,jlh9);
    return 0;
}