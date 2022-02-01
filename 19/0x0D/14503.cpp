// https://www.acmicpc.net/problem/14503
#include <iostream>
using namespace std;

int map[50][50];
int n, m, r, c, d, ans;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int turn()
{
	if (d == 0)
		return (3);
	else
		return (d - 1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> r >> c >> d;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	while (1)
	{
		if (map[r][c] == 0)
			map[r][c] = -1;
		int cleaned = 0;
		for (int i = 0; i < 4; i++)
		{
			d = turn();
			if (map[r + dx[d]][c + dy[d]] == 0)
			{
				r += dx[d];
				c += dy[d];
				cleaned = 1;
				break;
			}
		}
		if (!cleaned)
		{
			if (map[r - dx[d]][c - dy[d]] == 1)
				break;
			r -= dx[d];
			c -= dy[d];
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (map[i][j] == -1)
				ans++;
	cout << ans;
}
