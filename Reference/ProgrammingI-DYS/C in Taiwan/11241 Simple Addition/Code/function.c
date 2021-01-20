#include <stdio.h>
#include "function.h"
int addition(int* ptr_a, int array_ID, int* entry[], int *index, int num_element)
{
    int i, sum = 0;
    int position;

    /*Add all the designated elements*/
    for(i = 0 ; i < num_element ; i++)
    {
        /*Calculate the position of the element */
        position = index[2*i]*50+index[2*i+1];
        sum = sum + *(ptr_a+position) + *(entry[array_ID]+position);
    }
    return sum;
}
