#include <stdio.h>
#include <string.h>

int main() {

    char Password[30];
    char User[5][30];
    int i;

    for(i = 0; i < 5; i++) {
        printf("Enter Password");
        scanf("%s", Password);
        strcpy(User[i],Password);
    }

    for(i = 0; i < 5; i++)
        printf("Password %d: %s\n", i+1, User[i]);

    return 0;

}