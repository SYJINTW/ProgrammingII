#include <stdio.h>
#include <string.h>

char c[25], a[25], passwd[25];
int len;
int npasswd;
void perm(int pos, int start, int end);

int main(){
	char temp;
	
    scanf("%s", c);
    len = strlen(c);
    
	for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(c[j] < c[i]){
                temp = c[j];
                c[j] = c[i];
                c[i] = temp;
            }
        }
    }
    
	perm(0,0,len-1);
    printf("\n");
    return 0;
}

void perm(int pos, int start, int end)
{
    int i;

    //basis step
    if(pos>=4)
    {
        npasswd++;
        passwd[pos]='\0';
        if(npasswd==1) printf("%s",passwd);
        else printf(", %s",passwd);
    }

    //recursive step
    for(i=start;i<=end;i++)
    {
        passwd[pos]=c[i];
        perm(pos+1,i+1,end);
    }
}


