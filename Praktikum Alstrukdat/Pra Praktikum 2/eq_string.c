#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(){
    char str1[100];
    char str2[100];
    int flag=0,i=0;
    scanf("%s",str1);    
    scanf("%s",str2);
    if (strlen(str1) == strlen(str2)){
        while(str1[i]!='\0' && str2[i]!='\0')  // while loop  
        {  
            if(tolower(str1[i])!= tolower(str2[i]))  
            {  
                flag=1;  
                break;  
            }  
            i++;  
            } 
        if (flag == 0){
            printf("Ya\n");
        }
        else {
            printf("Tidak\n");
        }
    }
    else {
        printf("Tidak\n");
    }
    return 0;
}