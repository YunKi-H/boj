// https://www.acmicpc.net/problem/16985
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

int states[4][5][5][5];
int map[5][5][5];
int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};
int cmb[5] = {0, 1, 2, 3, 4};
int ans = 9999;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			for (int k = 0; k < 5; k++)
				cin >> states[0][i][j][k];
	for (int dir = 1; dir < 4; dir++)
		for (int z = 0; z < 5; z++)
			for (int y = 0; y < 5; y++)
				for (int x = 0; x < 5; x++)
					states[dir][z][y][x] = states[dir - 1][z][4 - x][y];
	do
	{
		for (int order = 0; order < 1024; order++)
		{
			int brute = order;
			for (int i = 0; i < 5; i++)
			{
				int dir = brute % 4;
				brute /= 4;
				for (int j = 0; j < 5; j++)
					for (int k = 0; k < 5; k++)
						map[i][j][k] = states[dir][cmb[i]][j][k];
			}
			int vis[5][5][5] = {0,};
			if (map[0][0][0] == 0 || map[4][4][4] == 0)
				continue;
			queue<pair<int, pair<int, int> > > q;
			q.push(make_pair(0, make_pair(0, 0)));
			vis[0][0][0] = 1;
			while (!q.empty())
			{
				pair<int, pair<int, int> > now = q.front();
				q.pop();
				for (int d = 0; d < 6; d++)
				{
					int nx = now.first + dx[d];
					int ny = now.second.first + dy[d];
					int nz = now.second.second + dz[d];
					if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5 || nz < 0 || nz >= 5)
						continue;
					if (map[nx][ny][nz] == 0 || vis[nx][ny][nz])
						continue;
					if (nx == 4 && ny == 4 && nz == 4)
						ans = min(ans, vis[now.first][now.second.first][now.second.second]);
					vis[nx][ny][nz] = vis[now.first][now.second.first][now.second.second] + 1;
					q.push(make_pair(nx, make_pair(ny, nz)));
				}
			}
		}
	} while (next_permutation(cmb, cmb + 5));
	if (ans == 9999)
		ans = -1;
	cout << ans;
}
