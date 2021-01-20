//
//  main.c
//  Homework
//
//  Created by Sun Yuan Jun on 2019/10/24.
//  Copyright © 2019 KentSun. All rights reserved.
//

#include <stdio.h>

int main() {
    const int N = 7;
    int i, j, k, l, a[N], change, keep = 1;
    int x, y, z;
    
    //reset the array
    for(x = 0; x<N; x++){
        a[x] = N - x;
    }
    
    j = k = N-1;

    while(keep){
        
        //exchange a[k] and a[j]
        change = a[j];
        a[j] = a[k];
        a[k] = change;
        
        //exchange first and last
        for(y = 1; y<(N-j+1)/2; y++){
                change = a[j+y];
                a[j+y] = a[N-y];
                a[N-y] = change;
        }
        
        //print all the answer
        for(z = 0; z<N; z++){
            printf("%d", a[z]);
        }
        printf("\n");
        
        //reset j
        keep = 0;
            
        //find j
        for(i = 0; i<N-1; i++){
            //check if a[i]>a[i+1]
            if(a[i]>a[i+1]){
                keep = 1;
				j = i;
            }
            else {
                //did not get j
            }
    	}
        
        //find k
    
         for(l = j+1; l<N; l++){
            //check if a[j]>a[l]
            if(a[j]>a[l]){
                //got k
                k = l;
            }
            else{
                //no use
            }
        }
    }
    return 0;
}
