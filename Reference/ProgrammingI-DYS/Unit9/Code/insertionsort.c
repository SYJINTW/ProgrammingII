#include <stdio.h>
#define LEN 5

void insertion_sort(int *, int);

int main(void)
{
    int arr[LEN]={10,2,5,3,6};
    int i;

    insertion_sort(arr,LEN);

    for(i=0;i<LEN;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void insertion_sort(int *ap, int n)
{
    int temp;
    int i,j;

    for(i=1;i<=n-1;i++)
    {
        temp=*(ap+i);
        j=i-1;

        while((j>=0) && (*(ap+j)>temp))
        {
            *(ap+j+1)=*(ap+j);
            j--;
        }
        *(ap+j+1)=temp;
    }
}
