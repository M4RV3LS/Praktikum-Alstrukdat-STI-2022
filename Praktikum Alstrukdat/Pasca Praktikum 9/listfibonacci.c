#include <stdio.h>
#include "listlinier.h"

int main() {
    List fibonacci;
    CreateEmpty(&fibonacci);

    infotype el;
    infotype n1 , n2 , plus;
    scanf("%d", &el);

    // Masukkan kode program disini

    if (el == 0) {
        // Masukkan kode program disini
        
        PrintInfo(fibonacci);
        return 0;
    } else if (el == 1) {
        // Masukkan kode program disini
        scanf("%d", &el);
        InsVLast(&fibonacci,el);
        PrintInfo(fibonacci);
        return 0;
    } else {

        // Masukkan kode program disini
        scanf("%d",&n1);
        scanf("%d",&n2);
        InsVLast(&fibonacci , n1);
        InsVLast(&fibonacci , n2);
        for (int i = 0;i < el-2 ; i++){
            plus = n1;
            plus = plus + n2;
            InsVLast(&fibonacci , plus);
            n1 = n2;
            n2 = plus;
        }
        PrintInfo(fibonacci);
    }

    return 0;
}