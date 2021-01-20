#include <stdio.h>

void hanoi(char from, char to, char buffer, int n);

int main(void)
{
    int n;

    printf("Number of disks: ");
    scanf("%d", &n);

    hanoi('1', '3', '2', n);

    return 0;
}

/* move n disks from a to b using c as a buffer */
void hanoi(char a, char b, char c, int n)
{
    if (n == 1)  {
        printf("Move the top disk from Tower %c to Tower %c\n", a, b);
        return;
    }

    hanoi(a, c, b, n-1); /* move the top n-1 disks from a to c */

    printf("Move the top disk from Tower %c to Tower %c\n", a, b); /* move the last disk from a to b */

    hanoi(c, b, a, n-1); /* move the top n-1 disks from c to b */
}
