#include <stdio.h>

int main(void)
{
    printf("int: %u bytes, char: %u bytes,\n", sizeof(int), sizeof(char));
    printf("long: %u bytes, double: %u bytes.\n", sizeof(long), sizeof(double));
    return 0;
}
