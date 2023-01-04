
#include "aritmatika.h"

boolean isOperator(char input){
    return ((input == '+') || (input == '-') || (input == '*') || (input == '/'));
}
/* Proses: Mengecek apakah input merupakan operator */
/*         input adalah operator jika input merupakan salah
           satu dari berikut:
                - +
                - -
                - *
                - /
*/

int hitung(int angka1, int angka2, char op){
    int hasil ;
    if (op == '+'){
        hasil = angka1 + angka2;
    }
    else if (op == '-'){
        hasil = angka1 - angka2;
    }
    else if (op == '*'){
        hasil = angka1 * angka2;
    }
    else if (op == '/'){
        hasil = angka1 / angka2;
    }
    return hasil;
}
/* Proses: Menghitung ekspresi */
/*
    Contoh input / output:
    angka1 : 2
    angka2 : 10
    op     : -

    return : -8 (penjelasan: 2 - 10 = 8)
*/

int eval(char *input, int length){
    Stack value ;
    CreateEmpty(&value);
    int angka1 , angka2 , hasil;
    for(int i=0 ; i < length ; i++){
        if(!isOperator(*(input+i))){
           Push(&value , *(input + i)-'0');
        }
        else {
            Pop(&value, &angka2);
            Pop(&value, &angka1);
            hasil = hitung(angka1,angka2,*(input+i));
            Push(&value , hasil);
        }
    }
    return InfoTop(value);
}
/* Proses: Menghitung keseluruhan ekspresi */
/* I.S. input adalah string. setiap operand dipastikan < 10 */
/*
    Contoh input / output:
    input   : 23+
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 2 + 3)

    input   : 9423+*5/-
    output  : 5 (penjelasan: ekspresi ekuivalen dengan 9-(4*(2+3))/5)

*/
