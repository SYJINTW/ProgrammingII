// Author: <justin0u0>
// Contact: <dancinglinkxalgorithm@gmail.com>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int n, m;
char s[1010][1010];
bool vis[1010][1010];
bool can_teleport;

void dfs(int x, int y) {
	if (vis[x][y])
		return;
	vis[x][y] = true;
	if (s[x][y] == 'T')
		can_teleport = true;
	int i;
	int dx[] = {1, -1, 0, 0};
	int dy[] = {0, 0, 1, -1};
	for (i = 0; i < 4; i++) {
		int newx = x + dx[i];
		int newy = y + dy[i];
		if (newx < 0 || newy < 0 || newx >= n || newy >= m)
			continue;
		if (s[newx][newy] == '#')
			continue;
		dfs(newx, newy);
	}
}

int main() {
	int T,i,j;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (i = 0; i < n; i++)
			scanf("%s", s[i]);
		memset(vis, false, sizeof(vis));
		can_teleport = false;
		dfs(0, 0);
		if (can_teleport) {
			for (i = 0; i < n; i++)
				for (j = 0; j < m; j++)
					if (s[i][j] == 'T')
						dfs(i, j);
		}
		if (vis[n - 1][m - 1])
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}

