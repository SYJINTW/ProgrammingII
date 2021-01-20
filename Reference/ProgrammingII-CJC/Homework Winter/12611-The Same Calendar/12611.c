#include <stdio.h>
#include <stdlib.h>

int isLeap(int year){
    if(year % 400 == 0 || ((year % 4 == 0)&&(year % 100 != 0)) )
        return 1;
    return 0;
}

int main(){
    int T;
    scanf("%d", &T);

    for(int i=0 ; i<T ; ++i){
        int year;
        scanf("%d", &year);
        int thisYearisLeap = isLeap(year);
        int displacement = 0;
        displacement += isLeap(++year) ? 366%7 : 365%7;
        while(displacement != 0 || thisYearisLeap ^ isLeap(year)){
            displacement += isLeap(++year) ? 366%7 : 365%7;
            displacement %= 7;
        }
        printf("%d\n", year);
    }
    return 0;
}