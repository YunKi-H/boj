//https://www.acmicpc.net/problem/11559
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int isPuyo;
int vis[12][6];
string map[12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int ans;

void resetVis()
{
	for (int i = 0; i < 12; i++)
		for (int j = 0; j < 6; j++)
			vis[i][j] = 0;
}

void delpuyo(int x, int y)
{
	vis[x][y] = 1;
	char color = map[x][y];
	queue<pair<int, int> > q;
	vector<pair<int, int> > tmp;
	q.push(make_pair(x, y));
	tmp.push_back(make_pair(x, y));
	while(!q.empty())
	{
		pair<int, int> now = q.front();
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nx = now.first + dx[d];
			int ny = now.second + dy[d];
			if (nx < 0 || nx >= 12 || ny < 0 || ny >= 6)
				continue;
			if (vis[nx][ny] || map[nx][ny] == '.' || map[nx][ny] != color)
				continue;
			vis[nx][ny] = 1;
			q.push(make_pair(nx, ny));
			tmp.push_back(make_pair(nx, ny));
		}
	}
	if (tmp.size() >= 4)
	{
		isPuyo = 1;
		for (int i = 0; i < tmp.size(); i++)
			map[tmp[i].first][tmp[i].second] = '.';
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 12; i++)
		cin >> map[i];
	do
	{
		isPuyo = 0;
		for (int i = 0; i < 6; i++)
		{
			for (int j = 10; j >= 0; j--)
			{
				int tmp = j;
				while (tmp < 11 && map[tmp + 1][i] == '.')
				{
					swap(map[tmp][i], map[tmp + 1][i]);
					tmp++;
				}
			}
		}
		for (int i = 0; i < 12; i++)
			for (int j = 0; j < 6; j++)
				if (!vis[i][j] && map[i][j] != '.')
					delpuyo(i, j);
		if(isPuyo)
			ans++;
		resetVis();
	} while (isPuyo);
	cout << ans;
}
