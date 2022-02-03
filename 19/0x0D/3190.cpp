// https://www.acmicpc.net/problem/3190
#include <iostream>
#include <utility>
#include <deque>
using namespace std;

int n, k, l, ans, x, y, d = 1;
char c;
int map[101][101];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
deque<pair<int, int> > snake;
deque<pair<int, char> > turn;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> x >> y;
		map[x][y] = -1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		cin >> x >> c;
		turn.push_back(make_pair(x, c));
	}
	x = 1;
	y = 1;
	map[x][y] = 1;
	snake.push_back(make_pair(x, y));
	while (1)
	{
		ans++;
		x += dx[d];
		y += dy[d];
		if (x < 1 || x > n || y < 1 || y > n || map[x][y] == 1)
			break;
		if (map[x][y] == 0)
		{
			pair<int, int> tail = snake.front();
			map[tail.first][tail.second] = 0;
			snake.pop_front();
		}
		map[x][y] = 1;
		snake.push_back(make_pair(x, y));
		if (ans == turn.front().first)
		{
			if (turn.front().second == 'L')
			{
				switch (d)
				{
				case 0:
					d = 3;
					break;
				case 1:
					d = 0;
					break;
				case 2:
					d = 1;
					break;
				case 3:
					d = 2;
					break;
				}
			}
			if (turn.front().second == 'D')
			{
				switch (d)
				{
				case 0:
					d = 1;
					break;
				case 1:
					d = 2;
					break;
				case 2:
					d = 3;
					break;
				case 3:
					d = 0;
					break;
				}
			}
			turn.pop_front();
		}
	}
	cout << ans;
}
