#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[30];
    char str2[30] = "123456789";
    int n;

    scanf("%s", str1);

    n = 2;

    strncpy(str2, str1, n);

    printf("%s\n", str2);

    return 0;
}
