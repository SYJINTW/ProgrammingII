#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

int main(){
    // read input
    int N, K;
    scanf("%d %d\n", &N, &K);
    char *str = (char*) malloc(N * sizeof(char));
    scanf("%s", str);
    // printf("%s", str);

    int *lengths = (int *) malloc(N * sizeof(int));
    
    // calculate lengths (12231) <- (abbccddde)
    int j=0;
    int len = strlen(str);
    int tempLen = 0;
    for(int i=0 ; i<len ; ++i){
        if(i == len-1){
            lengths[j] = tempLen+1;
            j++;
            tempLen = 0;
            break;
        }
        if(str[i+1] == str[i]){
            tempLen++;
        }else{
            lengths[j] = tempLen+1;
            j++;
            tempLen = 0;
        }
    }

    // declare variables
    int beginPos = 0;
    int ansMIN = INT_MAX, ansMAX = 0;
    int tempMax = 0;
    for(int i=beginPos ; i<beginPos+K ; ++i){
        tempMax += lengths[i];
    }

    int tempMin = 0;
    for(int i=beginPos ; i<beginPos+K ; ++i){
        if(i == beginPos || i == beginPos+K-1)
            tempMin += 1;
        else
            tempMin += lengths[i];
    }

    // printf("tempMax = %d\ttempMin = %d\n", tempMax, tempMin);
    // start to find max & min
    while((beginPos+K-1) < j){
        if(beginPos == 0){
            beginPos++;
            continue;
        }
            
        tempMax = tempMax + lengths[beginPos+K-1] - lengths[beginPos-1];
        if(K >= 3)
            tempMin = tempMin - lengths[beginPos] + lengths[beginPos+K-2];
        else
            tempMin = K;
        
        if(tempMax > ansMAX)
            ansMAX = tempMax;
        if(tempMin < ansMIN)
            ansMIN = tempMin;
        beginPos++;
    }
    printf("%d %d\n", ansMAX, ansMIN);

    return 0;
}