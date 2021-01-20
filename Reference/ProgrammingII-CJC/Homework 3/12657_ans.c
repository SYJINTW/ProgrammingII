#include<stdio.h>
#include<stdlib.h>

int gx[] = { 0,1,0,-1,0 }, gy[] = { 1,0,-1,0 ,0};
int n, m;
char map[505][505]; int is_1[505][505], is_2[505][505];

#define min(a,b) a>b?b:a
#define INF 2147483647

void mark_island( int row, int col,char type) {
	
	if (row < 0 || col < 0 || row >= n || col >= m ||map[row][col]==type)return;

	if (map[row][col] == '1') {
		map[row][col] = type;
		for (int i = 0; i < 4; i++) {
			mark_island(row + gx[i], col + gy[i], type);
		}
	}
	map[row][col] = type;	//also mark the "skin" or I say "edge"

}

int main() {
	int i, j;
    
	int sx, sy, ex, ey;
	scanf("%d %d", &n, &m);
	scanf("%d %d", &sx, &sy);
	scanf("%d %d", &ex, &ey);
	sx--; sy--; ex--; ey--;

	for ( i = 0; i < n; i++) 
		scanf("%s", map [i]);
	
	mark_island(sx, sy, 's');//start

	if (map[ex][ey] == 's') {printf("0\n"); return 0;}

	mark_island(ex, ey, 'e');//end

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (map[i][j] == 's')is_1[i][j] = 1;
			else if (map[i][j] == 'e') is_2[i][j] = 1;
		}
	}
	
	int len = INF;

	int flag_1 = 0, flag_2 = 0;//flag代表現在是誰在前面
	int temp_i, temp_j;
	for (i = 0; i < n; i++) {//逐列檢查
		flag_1 = 0, flag_2 = 0;

		for (j = 0; j < m; j++) {
			if (is_1[i][j] == 1 && flag_2 == 0) {
				flag_1 = 1;
				temp_j = j;
			}
			else if (is_2[i][j] == 1 && flag_1 == 1) {//case met 1 then met 2
				flag_1 = 0;
				flag_2 = 1;
				len = min(len, (j - temp_j + 1));
				temp_j = j;
			}
			else if (is_2[i][j] == 1 && flag_1 == 0) {
				flag_2 = 1;
				temp_j = j;
			}
			else if (is_1[i][j] == 1 && flag_2 == 1) {
				flag_2 = 0;
				flag_1 = 1;
				len = min(len, (j - temp_j + 1));
				temp_j = j;
			}
		}
	}

	for (j = 0; j < m; j++) {//逐行檢查
		flag_1 = 0, flag_2 = 0;
		for (i = 0; i < n; i++)
		{
			if (is_1[i][j] == 1 && flag_2 == 0) {
				flag_1 = 1;
				temp_i = i;
			}
			else if (is_2[i][j] == 1 && flag_1 == 1) {//case met 1 then met 2
				flag_1 = 0;
				flag_2 = 1;
				len = min(len, (i - temp_i + 1));
				temp_i = i;
			}
			else if (is_2[i][j] == 1 && flag_1 == 0) {
				flag_2 = 1;
				temp_i = i;
			}
			else if (is_1[i][j] == 1 && flag_2 == 1) {
				flag_2 = 0;
				flag_1 = 1;
				len = min(len, (i - temp_i + 1));
				temp_i = i;
			}
		}
	}

	if (len == INF)printf("-1\n");
	else printf("%d\n", len);

	return 0;


		
}