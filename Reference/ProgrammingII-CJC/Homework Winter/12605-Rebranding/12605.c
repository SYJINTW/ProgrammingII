#include <stdlib.h>
#include <stdio.h>

void swap_int(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void swap_char(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    int alpha_idx[26]; // record where the chars are in the map
    char map[26]; //final char 
    for(int i=0 ; i<26 ; ++i){
        alpha_idx[i] = i;
        map[i] = (char)('a'+i);
    }    

    char* str;
    str = (char*) malloc(sizeof(char)*n);
    scanf("%s", str);
    
    for(int i=0 ; i<m ; ++i){
        char x, y;
        scanf(" %c %c", &x, &y);
        swap_char(&map[alpha_idx[x-'a']], &map[alpha_idx[y-'a']]);
        swap_int(&alpha_idx[x-'a'], &alpha_idx[y-'a']);
    }

    for(int i=0 ; i<n ; ++i){
        printf("%c", map[str[i]-'a']);
    }
    printf("\n");


    free(str);
    return 0;
}