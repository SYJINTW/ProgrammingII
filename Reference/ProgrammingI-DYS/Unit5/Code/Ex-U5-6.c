#include <stdio.h>
#define CODE 13
int main(void)
{
    int code_entered;
    printf("Please enter the secret code number: ");
    scanf("%d", &code_entered);
    while (code_entered != CODE) {
       printf("Please enter the secret code number: ");
       scanf("%d", &code_entered);
    }
    printf("Bingo!\n");
    return 0;
}

