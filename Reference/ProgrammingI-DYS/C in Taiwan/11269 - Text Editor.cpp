#include <stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_SIZE 500

char content[MAX_SIZE];
char input[MAX_SIZE];

int main()
{
	char temp[MAX_SIZE];
	int cursor=0;
    fgets(input, MAX_SIZE, stdin);
	for(int i=0;i<MAX_SIZE;i++){
		if(input[i]=='/'){
			if(input[i+1]=='b'){
				i+=9;
				if(cursor!=0){
					strcpy(temp,&content[cursor]);
					cursor--;
					strcpy(&content[cursor],temp);
				}
			}
			else if(input[i+1]=='n'){
				i+=7;
				strcpy(temp,&content[cursor]);
				content[cursor++]='\n';
				strcpy(&content[cursor],temp);
			}
			else if(input[i+1]=='l'){
				i+=4;
				if(cursor!=0)
					cursor--;
			}
			else if(input[i+1]=='r'){
				i+=5;
				if(content[cursor-1]!=0){
					cursor++;
				}
			}
		}
		else if(isalpha(input[i])||input[i]==' '){
			strcpy(temp,&content[cursor]);
			content[cursor++]=input[i];
			strcpy(&content[cursor],temp);
		}
	}
    
    

    printf("%s", content);

    return 0;
}
