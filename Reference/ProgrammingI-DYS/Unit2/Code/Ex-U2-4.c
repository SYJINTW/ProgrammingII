#include <stdio.h>

int main(void)
{
    unsigned int un = 3000000000U;
    short small = 200;
    long big = 65537;

    printf("un = %u and not %d\n", un, un);
    printf("small = %hd and %d\n", small, small);
    printf("big = %ld and not %hd\n", big, big);

    return 0;
}
