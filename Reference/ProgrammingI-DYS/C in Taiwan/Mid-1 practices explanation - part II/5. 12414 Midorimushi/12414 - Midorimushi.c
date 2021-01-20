#include <stdio.h>

int main()
{
    int t, a;
    int time = 0, x = 0, y = 0, dir = 0;
    int dx[4] = {0, 10, 0, -10}, dy[4] = {10, 0, -10, 0};

    while (scanf("%d%d", &t, &a)) {
        x += (t - time) * dx[dir];
        y += (t - time) * dy[dir];
        time = t;

        if (a == 0)
            dir = (dir + 1) % 4;
        else if (a == 1)
            dir = (dir + 3) % 4;
        else if (a == 2)
            break;
    }

    printf("%d %d\n", x, y);

    return 0;
}