#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _cat{
    char name[50];
    int occu;
    int age;
}cat;

int cmp(const void *a, const void *b){
    cat A = *(cat *)a;
    cat B = *(cat *)b;
    if(A.occu==B.occu){
        if(A.age>B.age) return A.occu==5?1:-1;
        else if(A.age<B.age) return A.occu==5?-1:1;
        else if(A.age==B.age) return strcmp(A.name,B.name);
    }
    else if(A.occu<B.occu) return -1;
    else if(A.occu>B.occu) return 1;
}

int main(){
    int N,M;
    cat cats[10010];
    while(~scanf("%d%d",&N,&M)){
        for(int i=0;i<N;i++){
            char temp[50];
            scanf("%s%s%d",cats[i].name,temp,&(cats[i].age));
            switch(temp[0]){
                case 'e':
                    cats[i].occu = 1;
                    break;
                case 'n':
                    cats[i].occu = 2;
                    break;
                case 'k':
                    cats[i].occu = 3;
                    break;
                case 'w':
                    cats[i].occu = 4;
                    break;
                case 'a':
                    cats[i].occu = 5;
                    break;
                case 'm':
                    cats[i].occu = 6;
                    break;
                case 'd':
                    cats[i].occu = 7;
                    break;
                case 'l':
                    cats[i].occu = 8;
                    break;
            }
        }
        qsort(cats,N,sizeof(cat),cmp);
        for(int i=0;i<M&&i<N;i++){
            printf("%s\n",cats[i].name);
        }
    }
}
