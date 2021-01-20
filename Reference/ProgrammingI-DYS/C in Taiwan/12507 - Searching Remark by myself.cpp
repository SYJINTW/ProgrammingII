#include<stdio.h>
#include<string.h>
#include<ctype.h>
	char input[50];
int main(){
	char target[25];
	char *token;
	char stop[12]={' ','\n','-','/',':','(',')','[',']',',','.'};
	int ans=0;
	
	fgets(target,25,stdin);
	for(int i=0;i<strlen(target);i++){
		if(isupper(target[i]))
			target[i]=tolower(target[i]);
	}
	
	while(fgets(input,50,stdin)){
		token=strtok(input,stop);
		while(token!=NULL){
			for(int i=0;i<strlen(token);i++){
				if(isupper(token[i]))
					token[i]=tolower(token[i]);
			}
			if(strlen(token)==strlen(target)-1){
				if(strncmp(token,target,strlen(target)-1)==0)
					ans++;
			}
			token=strtok(NULL,stop);
		}
	}
	printf("%d\n",ans);
}
