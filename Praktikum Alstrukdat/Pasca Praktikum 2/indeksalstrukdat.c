#include <stdio.h>

int main(){
    int input , n = 0 , lulus = 0 ;
    float rate , sum = 0 ;
    char index;
    scanf("%d",&input);

    if (input == -999){
        printf("Tidak ada data\n");
    } 

    else{
        while (input != -999){
            if (input >= 0 && input <= 4){
                sum += input;
                n += 1;
                if (input >= 3){
                    lulus += 1;
                }
                else {
                    lulus += 0;
                }
                scanf("%d" , &input);
            }
            else {
                scanf("%d" , &input);
            }
        }
        rate = sum / n;

        if (n!= 0){
            if (rate == 4.00){
                index = 'A';
            }
            else if (rate >= 3.00 && rate < 4.00){
                index = 'B';
            }
            else if (rate >= 2.00 && rate < 3.00){
                index = 'C';
            }
            else if (rate >= 1.00 && rate < 2.00){
                index = 'D';
            }
            else if (rate >= 0.00 && rate < 1.00){
                index = 'E';
            }

            printf("Jumlah mahasiswa yang lulus = %d\n" , lulus);
            printf("Nilai rata-rata = %.2f\n" , rate);
            printf("Indeks akhir kelas = %c\n" , index);
        }

        else {
            printf("Tidak ada data\n");
        }
    }
    return 0;
}