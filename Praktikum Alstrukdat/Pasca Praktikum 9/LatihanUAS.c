#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listlinier.h"

void InsertX (List *L , infotype x){
address Prec ; 
address P ; 
address PCurrent;
infotype idx ; 
boolean Found ; 
boolean Target ;

P = Alokasi(x);		/*Alokasi Node*/
idx  = 0;
Found = false; 
Target = false; 

if ( IsEmpty(*L)){
    First(*L) = P;
} 
else{
    PCurrent = First(*L);
    //Prec = Nil;
/* Search apakah X udah ada di List */
    while(PCurrent != Nil && !Found){
        if (Info(PCurrent) == x){
            Found = true;
            
        } 
        else {
            PCurrent = Next(PCurrent);
        } 
       
    } 
	if (!Found){
        
        PCurrent = First(*L);
        Prec = Nil;
        if (Info(P) < Info(First(*L))){
            Next(P) = First(*L);
		    First(*L) = P;
            
        }
        else{
       
            /* Insert Node */
        boolean selesai = false;
        PrintInfo(*L);
		while (PCurrent != Nil && !selesai) {
            Prec = PCurrent;
			PCurrent = Next(PCurrent);
            if (PCurrent != Nil){
                if (Info(P) < Info(PCurrent) && PCurrent != Nil){
                selesai = true;
                } 
            }
            
            
        } 
        
    
		Next(P) = PCurrent;
		Next(Prec) = P;
        PrintInfo(*L);
        printf("\n");
     
			/* Search Index */
        PCurrent = First(*L);
        PrintInfo(*L);
		while (PCurrent != Nil && (!Target)){
            if (Info(PCurrent) == x){
                Target = true;
        
            } 
			else{
                PCurrent = Next(PCurrent);
                idx = idx + 1;

            } 
        } 
		  
		PrintInfo(*L);
        }  
    }
    else {
        idx = -1;
    }
		

} 
printf("index = %d\n", idx);

	
}



// int main(){
// List L;
// infotype x;
// CreateEmpty(&L);
// InsVLast(&L, 3);
// InsVLast(&L, 5);
// InsVLast(&L, 8);
// //InsVLast(&L, 4);
// PrintInfo(L);
// InsertX(&L, 5);
// PrintInfo(L);

// }