#include <stdio.h>
#include <string.h>
#define SIZE 100

int main(void)
{
    int a[SIZE];
    int b[SIZE];
    int i;

    memset(a, 0, SIZE*sizeof(int));

    for (i=0; i<SIZE; i++) {
        printf("%d ", a[i]);
        if ((i+1)%10 == 0) printf("\n");
    }

    for (i=0; i<SIZE; i++) {
        a[i] = i*i;
    }

    memcpy(b, a, SIZE*sizeof(int));

    for (i=0; i<SIZE; i++) {
        printf("%5d", b[i]);
        if ((i+1)%10 == 0) printf("\n");
    }

    return 0;
}



