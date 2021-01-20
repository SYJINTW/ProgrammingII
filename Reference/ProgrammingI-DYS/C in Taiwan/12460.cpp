#include <stdio.h>
#include <string.h>

char c[25], a[25];
int len;

void ADO(int n, int k, int tag);

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
    
	ADO(0, 0, 1);
    printf("\n");
    return 0;
}
 
void ADO(int n, int k, int tag){
    
	if(k >= 4 && tag){
    	if(n != 4 || k != 4)printf(", ");       
        for(int i = 0; i < k; i++)printf("%c", a[i]);
    }
    
    if(n >= len)
		return;
		
    a[k] = c[n];
    k++;
    ADO(n+1, k, 1);
    k--;
    ADO(n+1, k, 0);
}

