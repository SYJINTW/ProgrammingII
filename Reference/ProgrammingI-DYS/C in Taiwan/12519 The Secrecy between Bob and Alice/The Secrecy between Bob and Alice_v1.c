#include <stdio.h>
#include <string.h>
 
int N;
char str[5000][5010];
int f[5000];
int temp = 0;

int check(char *input,char *p){
	int alpha1[26]={0},alpha2[26]={0};
	if(strlen(input)!=strlen(p))
		return 0;
	int i;
	for(i=0;i<strlen(p);i++){
		int idx1=input[i]-'a';
		alpha1[idx1]++;
		int idx2=p[i]-'a';
		alpha2[idx2]++;
	}
	for(i=0;i<26;i++){
		if(alpha1[i]!=alpha2[i])
			return 0;
	}
	return 1;
}

int main(void)
{
    char P[5010];
    scanf("%d %s",&N,P);
    int i;
	for(i=0;i<N;i++){
        char input[5010];
        int flag = 0;
        scanf("%s",input);
        if(check(input,P)==0)
            continue;
        int j;
        for(j=0;j<temp;j++){
            if(strcmp(str[j],input)==0){
                flag = 1;
                break;
            }
        }
        if(flag){
            f[j]++;
        }
        else{
            strcpy(str[temp],input);
            f[temp] = 1;
            temp++;
        }
    }
	int j;
    for(i=0;i<temp;i++){
        for(j=0;j<temp-i-1;j++){
            int flag = 0;
            if(f[j]<f[j+1])
                flag = 1;
            else if(f[j]>f[j+1])
                flag = 0;
            else{
                if(strcmp(str[j],str[j+1])>0)
                    flag = 1;
                else{
                    flag = 0;
                }
            }
            if(flag){
                char change[5010];
                strcpy(change,str[j]);
                strcpy(str[j],str[j+1]);
                strcpy(str[j+1],change);

                int change_int=f[j];
                f[j]=f[j+1];
                f[j+1]=change_int;
            }
        }
    }

    printf("%d\n",temp);
    for(i=0;i<temp;i++){
        printf("%s %d\n",str[i],f[i]);
    }
}

