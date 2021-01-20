#include <stdio.h>
#include <stdlib.h>

typedef struct t_data {
    int size;
    int * ptr;
} DATA;

void create_data(DATA *z, int sz)
{
    int i;

    z->size = sz;
    z->ptr = (int *) malloc(sz*sizeof(int));

    for (i=0; i< sz; i++)  {
        (z->ptr)[i] = i;
    }
}

void show_data(DATA d)
{
    int i;

    printf("%u\n", sizeof(d));

    for (i=0; i<d.size; i++) {
        printf("%d ", (d.ptr)[i]);
        if ((i+1)%10 == 0) printf("\n");
    }
}

void delete_data(DATA *z)
{
    free(z->ptr);
    z->ptr = NULL;
    z->size = 0;
}

DATA clone_data(DATA x)
{
    int i;

    DATA y;

    y.size = x.size;
    y.ptr = (int *) malloc(y.size*sizeof(int));

    for (i=0; i<y.size; i++) {
        (y.ptr)[i] = (x.ptr)[i];
    }

    return y;
}

int main(void)
{
    DATA x , x_clone;

    create_data(&x, 100);
    show_data(x);
    x_clone = clone_data(x);
    delete_data(&x);
    show_data(x_clone);

    return 0;
}
