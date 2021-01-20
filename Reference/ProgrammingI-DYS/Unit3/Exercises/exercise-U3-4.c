#include <stdio.h>
#include <string.h>

#define BORDER "############################################"

int main(void)
{
    char word[26];

    scanf("%25s", word);
    printf("%.*s\n", strlen(word)+2, BORDER);
    printf("#%s#\n", word);
    printf("%.*s\n", strlen(word)+2, BORDER);

    return 0 ;
}
