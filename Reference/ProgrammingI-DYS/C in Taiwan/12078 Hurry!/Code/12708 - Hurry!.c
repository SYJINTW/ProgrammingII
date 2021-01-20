#include <stdio.h>
#define MAX_N 3005

int main(void)
{
    int T, N, K;
    int max_min, max_i, cur_L, cur_R, cur_min, cur_i;
    int urinal[MAX_N];

    scanf("%d", &T);

    while (T--)
    {
        scanf("%d%d", &N, &K);

        urinal[0] = urinal[N+1] = 1;
        for (int i = 1; i <= N ; i++) urinal[i] = 0;

        while (K--)
        {
            max_min = -1;
            max_i = 0;

            for (int i = 1; i <= N ; i++)
            {
                if (urinal[i]) continue;

                cur_L = cur_R = 0;
                cur_i = i;
                while (!urinal[--cur_i]) cur_L++;
                cur_i = i;
                while (!urinal[++cur_i]) cur_R++;

                cur_min = (cur_L < cur_R) ? cur_L : cur_R;
                if (cur_min > max_min)
                {
                    max_min = cur_min;
                    max_i = i;
                }
            }

            urinal[max_i] = 1;
        }

        printf("%d\n", max_i);
    }

    return 0;
}
