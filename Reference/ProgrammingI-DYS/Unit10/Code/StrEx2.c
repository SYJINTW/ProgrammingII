#include <stdio.h>
#include <string.h>

int main(void)
{
    char str1[30];
    char str2[30];
    char str3[60] = "ABCDEFGHIJKL";

    scanf("%29s", str1);
    scanf("%29s", str2);

    strcpy(str3, str1);

    printf("%s\n", str3);

    strcat(str3, str2);

    printf("%s\n", str3);

    return 0;
}
