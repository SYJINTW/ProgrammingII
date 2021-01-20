#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[30];
    char str2[30];
    int n;

    scanf("%29s", str1);
    scanf("%29s", str2);

    printf("strcmp(%s, %s) = %d\n", str1, str2, strcmp(str1, str2));

    n = 3;

    printf("strncmp(%s, %s, n) = %d\n", str1, str2, strncmp(str1, str2, n));

    return 0;
}
