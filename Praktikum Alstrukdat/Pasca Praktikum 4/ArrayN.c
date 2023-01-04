#include <stdio.h>
int main(){
    int N , q , l , r , sum = 0;
    scanf("%d",&N);
    int array[N];
    for (int i = 0 ; i < N ; i++){
            scanf("%d" , &array[i]);
    }
    scanf("%d",&q);
    int arrayoutput[q]; 
	for (int z = 0 ; z < q ; z++){
		    arrayoutput[z] = 0;
	    }
    
    
    for(int j = 0 ; j < q ; j++ ){
        scanf("%d %d" , &l , &r);
        for (int k = l ; k <= r ; k++){
            arrayoutput[j] += array[(k-1)%N]; 
        }
    }

    for (int idx = 0 ; idx < q ; idx++)
	{
		printf("%d\n",arrayoutput[idx]);
	}
	return 0;
}