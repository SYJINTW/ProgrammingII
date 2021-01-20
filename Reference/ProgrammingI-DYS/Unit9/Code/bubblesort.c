#include <stdio.h>
#define LEN 5

void bubble_sort(int *, int);

int main(void)
{
    int arr[LEN]={10,2,5,3,6};
    int i;

    bubble_sort(arr,LEN);

    for(i=0;i<LEN;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void bubble_sort(int *ap, int n)
{
    int i, j, temp;
    for (i = 0; i < n-1; i++)
    {
        for (j = 0; j < n-1-i; j++)
        {
            if (ap[j] > ap[j + 1])
            {
                temp = ap[j];
                ap[j] = ap[j + 1];
                ap[j + 1] = temp;
            }
        }
    }
}
