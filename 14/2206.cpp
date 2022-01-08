// 문제
// N×M의 행렬로 표현되는 맵이 있다. 맵에서 0은 이동할 수 있는 곳을 나타내고, 1은 이동할 수 없는 벽이 있는 곳을 나타낸다. 당신은 (1, 1)에서 (N, M)의 위치까지 이동하려 하는데, 이때 최단 경로로 이동하려 한다. 최단경로는 맵에서 가장 적은 개수의 칸을 지나는 경로를 말하는데, 이때 시작하는 칸과 끝나는 칸도 포함해서 센다.

// 만약에 이동하는 도중에 한 개의 벽을 부수고 이동하는 것이 좀 더 경로가 짧아진다면, 벽을 한 개 까지 부수고 이동하여도 된다.

// 한 칸에서 이동할 수 있는 칸은 상하좌우로 인접한 칸이다.

// 맵이 주어졌을 때, 최단 경로를 구해 내는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N(1 ≤ N ≤ 1,000), M(1 ≤ M ≤ 1,000)이 주어진다. 다음 N개의 줄에 M개의 숫자로 맵이 주어진다. (1, 1)과 (N, M)은 항상 0이라고 가정하자.

// 출력
// 첫째 줄에 최단 거리를 출력한다. 불가능할 때는 -1을 출력한다.
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

string board[1000];
int	vis[1000][1000][2];

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int dx[4] = {1, 0, -1, 0};
	int dy[4] = {0, 1, 0, -1};
	queue<pair<pair<int, int>, int> > q;
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	vis[0][0][0] = 1;
	q.push(make_pair(make_pair(0, 0), 0));
	while (!q.empty())
	{
		pair<pair<int, int>, int> now = q.front();
		q.pop();
		for (int d = 0; d < 4; d++)
		{
			int nx = now.first.first + dx[d];
			int ny = now.first.second + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m)
				continue;
			if (vis[nx][ny][now.second])
				continue;
			if (board[nx][ny] == '0')
			{
				vis[nx][ny][now.second] = vis[now.first.first][now.first.second][now.second] + 1;
				q.push(make_pair(make_pair(nx, ny), now.second));
			}
			if (board[nx][ny] == '1' && !now.second)
			{
				vis[nx][ny][1] = vis[now.first.first][now.first.second][now.second] + 1;
				q.push(make_pair(make_pair(nx, ny), 1));
			}
		}
	}
	if (!vis[n - 1][m - 1][0] && !vis[n - 1][m - 1][1])
		cout << -1;
	else if (!vis[n - 1][m - 1][0] && vis[n - 1][m - 1][1])
		cout << vis[n - 1][m - 1][1];
	else if (vis[n - 1][m - 1][0] && vis[n - 1][m - 1][1])
		cout << min(vis[n - 1][m - 1][0], vis[n - 1][m - 1][1]);
	else
		cout << vis[n - 1][m - 1][0];
}
