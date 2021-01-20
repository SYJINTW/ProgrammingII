#include <stdlib.h>
#include <stdio.h>

int main(){
    int N;
    while(scanf("%d", &N) != EOF){
        int *array = (int*)malloc(N * sizeof(int));
        for(int i=0 ; i<N ; ++i){
            int num;
            scanf("%d", &num);
            array[i] = num;
        }
        // for(int i=0 ; i<N ; ++i){
        //     printf("%d ", array[i]);
        // }
        for(int i=1 ; i<N ; ++i){
            for(int j=i ; j>0 ; --j){
                if(array[j-1] > array[j]){
                    int temp = array[j-1];
                    array[j-1] = array[j];
                    array[j] = temp;
                }
            }
        }
        for(int i=0 ; i<N-1 ; ++i){
            printf("%d ", array[i]);
        }
        printf("%d\n", array[N-1]);
    }
    return 0;
}