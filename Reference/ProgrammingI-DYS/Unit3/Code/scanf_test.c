#include <stdio.h>
int main(void)
{
    char name[10];
    int x = -1;

    scanf("%d", &x);
    scanf("%s", name);

    printf("x = %d\n", x);
    printf("name: \"%s\"\n", name);

    return 0 ;
}
