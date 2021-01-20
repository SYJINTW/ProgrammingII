// I2P(1) 2019 TA Leo Yang
#include <stdio.h>

char map[1010][1010];
int walked[1010][1010] = {0};
int teleport[1000010][2] = {0};
int max_row = 0, max_col = 0;
int n_teleports = 0;

int find(int row, int col);

int main()
{
    int n;
    char c;
 
    scanf("%d", &n);

    while (n--)
    {
        n_teleports = 0;
        scanf("%d%d", &max_row, &max_col);
        
        for (int i = 0; i < max_row; i++)
            for (int j = 0; j < max_col; j++)
            {
                scanf(" %c", &map[i][j]);
                walked[i][j] = 0;

                if (map[i][j] == 'T')
                {
                    teleport[n_teleports][0] = i;
                    teleport[n_teleports][1] = j;
                    n_teleports++;
                }
            }

        printf("%s\n", find(0, 0) ? "Yes" : "No");
    }
    
    return 0;
}

int find(int row, int col)
{
    walked[row][col] = 1;
    
    if (row == max_row - 1 && col == max_col - 1)
        return 1;

    if (col + 1 < max_col)
        if (!walked[row][col + 1] && map[row][col + 1] != '#')
            if (find(row, col + 1))
                return 1;
    
    if (row + 1 < max_row)
        if (!walked[row + 1][col] && map[row + 1][col] != '#')
            if (find(row + 1, col))
                return 1;

    if (col - 1 >= 0)
        if (!walked[row][col - 1] && map[row][col - 1] != '#')
            if (find(row, col - 1))
                return 1;

    if (row - 1 >= 0)
        if (!walked[row - 1][col] && map[row - 1][col] != '#')
            if (find(row - 1, col))
                return 1;

    if (map[row][col] == 'T')
        for (int i = 0; i < n_teleports; i++)
            if (!walked[teleport[i][0]][teleport[i][1]])
                if (find(teleport[i][0], teleport[i][1]))
                    return 1;

    return 0;
}
