//https://www.acmicpc.net/problem/15683
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

int n, m, ans;
int board[9][9];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
vector<pair<int, int> > cctv;

void upd(int x, int y, int dir, bool rollback, int index)
{
	dir %= 4;
	while (1)
	{
		x += dx[dir];
		y += dy[dir];
		if (x < 0 || x >= n || y < 0 || y >= m || board[x][y] == 6)
			return;
		if (board[x][y] > 0 && board[x][y] <= 5)
			continue;
		if (rollback && board[x][y] == 7 + index)
		{
			board[x][y] = 0;
		}
		else if (board[x][y] == 0)
		{
			board[x][y] = 7 + index;
		}
	}
}

void solve(int index)
{
	if (index == cctv.size())
		return;
	pair<int, int> now = cctv[index];
	for (int dir = 0; dir < 4; dir++)
	{
		if (board[now.first][now.second] == 1)
		{
			upd(now.first, now.second, dir, 0, index);
		}
		else if (board[now.first][now.second] == 2)
		{
			upd(now.first, now.second, dir, 0, index);
			upd(now.first, now.second, dir + 2, 0, index);
		}
		else if (board[now.first][now.second] == 3)
		{
			upd(now.first, now.second, dir, 0, index);
			upd(now.first, now.second, dir + 1, 0, index);
		}
		else if (board[now.first][now.second] == 4)
		{
			upd(now.first, now.second, dir, 0, index);
			upd(now.first, now.second, dir + 1, 0, index);
			upd(now.first, now.second, dir + 2, 0, index);
		}
		else if (board[now.first][now.second] == 5)
		{
			upd(now.first, now.second, dir, 0, index);
			upd(now.first, now.second, dir + 1, 0, index);
			upd(now.first, now.second, dir + 2, 0, index);
			upd(now.first, now.second, dir + 3, 0, index);
		}
		int _min = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (board[i][j] == 0)
					_min++;
		// for (int i = 0; i < n; i++)
		// {
		// 	for (int j = 0; j < m; j++)
		// 	{
		// 		cout << board[i][j] << ' ';
		// 	}
		// 	cout << '\n';
		// }
		// cout << '\n';
		ans = min(ans, _min);
		solve(index + 1);
		if (board[now.first][now.second] == 1)
		{
			upd(now.first, now.second, dir, 1, index);
		}
		else if (board[now.first][now.second] == 2)
		{
			upd(now.first, now.second, dir, 1, index);
			upd(now.first, now.second, dir + 2, 1, index);
		}
		else if (board[now.first][now.second] == 3)
		{
			upd(now.first, now.second, dir, 1, index);
			upd(now.first, now.second, dir + 1, 1, index);
		}
		else if (board[now.first][now.second] == 4)
		{
			upd(now.first, now.second, dir, 1, index);
			upd(now.first, now.second, dir + 1, 1, index);
			upd(now.first, now.second, dir + 2, 1, index);
		}
		else if (board[now.first][now.second] == 5)
		{
			upd(now.first, now.second, dir, 1, index);
			upd(now.first, now.second, dir + 1, 1, index);
			upd(now.first, now.second, dir + 2, 1, index);
			upd(now.first, now.second, dir + 3, 1, index);
		}
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] > 0 && board[i][j] <= 5)
				cctv.push_back(make_pair(i, j));
			if (board[i][j] == 0)
				ans++;
		}
	}
	solve(0);
	cout << ans;
}
