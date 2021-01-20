#include <stdio.h>

void print_sum(int num)
{
    int i = 1, sum;
    while(i <= num)
    {
        sum = sum + i;
        i++;
    }
    printf("The sum is %d\n", sum);
    return;
}
int main()
{
    int num;

    printf("Input a number : ");
    scanf("%d", &num);
    print_sum(num);

    return 0;
}
