#include <stdio.h>
#define BIGINT_WIDTH 4
#define BIGINT_BASE 10000
#define DIGIT_NUM 16
#define NUM_SIZE (DIGIT_NUM/BIGINT_WIDTH)
#define ANS_SIZE (NUM_SIZE*2)

int main()
{
    int num[NUM_SIZE] = {0}; // store input number (under base 10000)
    int ans[ANS_SIZE] = {0}; // store answer (under base 10000)
    char input[DIGIT_NUM];   // store input nunber (under base 10)
    
    // input : input 16-digit number to a char array (under base 10)
    for(int i = 0; i < DIGIT_NUM; i++) scanf("%c", &input[i]);
    
    // convert from base 10 to base 10000
    for(int d = 0; d < DIGIT_NUM; d++)
    {
        int num_idx = (DIGIT_NUM-d-1)/BIGINT_WIDTH;
        num[num_idx] *= 10;
        num[num_idx] += input[d]-'0';
    }
    
    // TODO: multiplication
    for(int up = 0; up < NUM_SIZE; up++)
        for(int down = 0; down < NUM_SIZE; down++)
            ans[up+down] += num[down]*num[up];

    // TODO: deal with carry (處理進位)
    for(int d = 0; d < ANS_SIZE-1; d++)
    {
        ans[d+1]+=ans[d]/10000;
        ans[d]%=10000;
    }
    
    // print answer
    printf("%4d", ans[ANS_SIZE-1]);
    for(int d = ANS_SIZE-2; d >= 0; d--) printf("%04d", ans[d]);
    printf("\n");

    return 0;
}

