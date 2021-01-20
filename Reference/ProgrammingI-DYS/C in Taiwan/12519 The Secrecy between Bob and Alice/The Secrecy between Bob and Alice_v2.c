#include <stdio.h>
#include <string.h>
#define MAX_N 5000
#define MAX_S 5000

int N, cnt = 0;
char P[MAX_S+1];
char str[MAX_N][MAX_S+1];
char ans[MAX_N][MAX_S+1];
int freq[MAX_N] = {};

void pattern(char* p, char* s){
    char rule[26] = {};
    strcpy(p, s);
    int l = strlen(p);
    char cur = 'a';
    for(int i=0; i<l; i++){
        int idx = p[i] - 'a';
        if( rule[idx] == 0 )
            rule[idx] = cur++;
        p[i] = rule[idx];
    }
}

void myswap(int i, int j){
    char tmp[MAX_S+1];
    // �i�Ϋ��Чޥ��u�� swap 2 strings
    strcpy(tmp, str[i]);
    strcpy(str[i], str[j]);
    strcpy(str[j], tmp);

    int x = freq[i];
    freq[i] = freq[j];
    freq[j] = x;
}

int mycmp(int i, int j){
    if( freq[i] < freq[j] ) return 1;
    if( freq[i] > freq[j] ) return -1;
    return 0; // ��J�w�Ӧr��� �]�����ΦA��
    // return strcmp(str[i], str[j]);
}

int main(){
    scanf("%d %s", &N, P );
    pattern(P, P);

    for(int i=0; i<N; i++){
        char s[MAX_S+1], pat[MAX_S+1];
        scanf("%s", s);
        pattern(pat, s);

        // Step 2: �L�o���P P �򤣦P Pattern ���r��
        if( strcmp(pat, P) != 0 ) continue;

        // �έp�X�{�L���r�ꦸ��
        int prev = cnt-1;
        if( strcmp(s, str[prev]) != 0  ){ // ���e�S�X�{�L
            strcpy(str[cnt], s);
            freq[cnt] = 1;
            cnt++;
        }
        else{
            freq[prev]++;
        }
    }

    // Step 3: Sort by frequency, �r���
    for(int i=0; i<cnt; i++){
        for(int j=0; j<cnt-1; j++){
            if( mycmp(j, j+1) > 0){
                myswap(j, j+1);
            }
        }
    }

    printf("%d\n", cnt);
    for(int i=0; i<cnt; i++){
        printf("%s %d\n", str[i], freq[i]);
    }

    return 0;
}
