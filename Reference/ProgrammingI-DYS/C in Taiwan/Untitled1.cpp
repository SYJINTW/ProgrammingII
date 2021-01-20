#include<stdio.h>
#include<string.h>
int check(char *input,char *p){
	int alpha1[26]={0},alpha2[26]={0};
	if(strlen(input)!=strlen(p))
		return 0;
	for(int i=0;i<strlen(p);i++){
		int idx1=input[i]-'a';
		alpha1[idx1]++;
		int idx2=p[i]-'a';
		alpha2[idx2]++;
	}
	for(int i=0;i<26;i++){
		if(alpha1[i]!=alpha2[i])
			return 0;
	}
	return 1;
}
int main(){
	char s[310];
	char *ps=s;
	char str[310][310];
	char target[310];
	char temp[310];
	int number;
	int f[310]={0};
	int flag;
	int k=0;
	scanf("%s",s);
	scanf("%d",&number);
	scanf("%s",target);
	for(int i=0;i<strlen(s)-number+1;i++){
		strncpy(temp,ps,number);
		temp[number]='\0';
		flag=0;
		printf("%s\n",temp);
		if(check(temp,target)){
			printf("1\n");
			flag=1;
		}
		if(flag){
			for(int j=0;j<k;k++){
				if(strcmp(temp,str[j])==0){
					f[j]++;
					flag=0;
					break;
				}
			}
		}
		if(flag){
			strcpy(str[k],temp);
			f[k]++;
			k++;
		}
		ps++;
	}
	for(int i=0;i<k;i++){
		printf("%s %d",str[i],f[i]);
	}
} 
