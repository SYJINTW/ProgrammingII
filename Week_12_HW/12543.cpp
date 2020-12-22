// BFS
#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int n, m;
int enemies;

int bfs(queue <tuple<int, int, int>> q, vector<vector <char>> maze)
{
	while(!q.empty())
	{
		tuple <int, int , int> now = q.front();
		q.pop();
		int now_x = get<0>(now);
		int now_y = get<1>(now);
		int step = get<2>(now);
		if(maze[now_x][now_y] == 'T')
		{
			if(--enemies == 0) return step;
		} 
		else if(maze[now_x][now_y] == 'C') continue;
		else;
		maze[now_x][now_y] = 'C';

		// upper
		if(now_y-1 >= 0)
		{
			if(maze[now_x][now_y-1] != 'C') q.push({now_x, now_y-1, step+1});
			else;
		}
		// down
		if(now_y+1 < m)
		{
			if(maze[now_x][now_y+1] != 'C') q.push({now_x, now_y+1, step+1});
			else;
		}
		// left
		if(now_x-1 >= 0)
		{
			if(maze[now_x-1][now_y] != 'C') q.push({now_x-1, now_y, step+1});
			else;
		}
		// right
		if(now_x+1 < n)
		{
			if(maze[now_x+1][now_y] != 'C') q.push({now_x+1, now_y, step+1});
			else;
		}
		//cout << step << endl;
	}
	return -1;
}

int main(){
	char c;
	cin >> n >> m;
	vector<vector <char>> maze(m, vector<char>(n));
	queue<tuple<int, int, int>> q;

	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			cin.get(c);
			if(c == '\n') cin.get(c);
			// Initial
			if(c == 'I')
			{
				maze[i][j] = 'I';
				q.push({i, j, 0});
			}
			else if(c == 'T')
			{	
				maze[i][j] = 'T';
				enemies++;
			}
			else if(c == '.')
			{
				maze[i][j] = '.';
			}
			else maze[i][j] = 'C';
		}
	}
	cout << bfs(q, maze) << '\n';
	return 0;
}

