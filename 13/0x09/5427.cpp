// 문제
// 상근이는 빈 공간과 벽으로 이루어진 건물에 갇혀있다. 건물의 일부에는 불이 났고, 상근이는 출구를 향해 뛰고 있다.

// 매 초마다, 불은 동서남북 방향으로 인접한 빈 공간으로 퍼져나간다. 벽에는 불이 붙지 않는다. 상근이는 동서남북 인접한 칸으로 이동할 수 있으며, 1초가 걸린다. 상근이는 벽을 통과할 수 없고, 불이 옮겨진 칸 또는 이제 불이 붙으려는 칸으로 이동할 수 없다. 상근이가 있는 칸에 불이 옮겨옴과 동시에 다른 칸으로 이동할 수 있다.

// 빌딩의 지도가 주어졌을 때, 얼마나 빨리 빌딩을 탈출할 수 있는지 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 테스트 케이스의 개수가 주어진다. 테스트 케이스는 최대 100개이다.

// 각 테스트 케이스의 첫째 줄에는 빌딩 지도의 너비와 높이 w와 h가 주어진다. (1 ≤ w,h ≤ 1000)

// 다음 h개 줄에는 w개의 문자, 빌딩의 지도가 주어진다.

// '.': 빈 공간
// '#': 벽
// '@': 상근이의 시작 위치
// '*': 불
// 각 지도에 @의 개수는 하나이다.

// 출력
// 각 테스트 케이스마다 빌딩을 탈출하는데 가장 빠른 시간을 출력한다. 빌딩을 탈출할 수 없는 경우에는 "IMPOSSIBLE"을 출력한다.
#include <iostream>
#include <queue>
#include <algorithm>
#include <utility>
using namespace std;

string board[1000];
int fire[1000][1000];
int human[1000][1000];

int solve()
{
	int r, c;
		cin >> c >> r;
		int dx[4] = {1, 0, -1, 0};
		int dy[4] = {0, 1, 0, -1};
		for (int i = 0; i < r; i++)
		{
			fill(fire[i], fire[i] + c, -1);
			fill(human[i], human[i] + c, -1);
		}
		for (int i = 0; i < r; i++)
			cin >> board[i];
		queue<pair<int, int> > q1;
		queue<pair<int, int> > q2;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				if (board[i][j] == '*')
				{
					q1.push(make_pair(i, j));
					fire[i][j] = 0;
				}
				if (board[i][j] == '@')
				{
					q2.push(make_pair(i, j));
					human[i][j] = 0;
				}
			}
		}
		while (!q1.empty())
		{
			pair<int, int> now = q1.front();
			q1.pop();
			for (int d = 0; d < 4; d++)
			{
				int nx = now.first + dx[d];
				int ny = now.second + dy[d];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
					continue;
				if (fire[nx][ny] >= 0 || board[nx][ny] == '#')
					continue;
				fire[nx][ny] = fire[now.first][now.second] + 1;
				q1.push(make_pair(nx, ny));
			}
		}
		while (!q2.empty())
		{
			pair<int, int> now = q2.front();
			q2.pop();
			for (int d = 0; d < 4; d++)
			{
				int nx = now.first + dx[d];
				int ny = now.second + dy[d];
				if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				{
					return (human[now.first][now.second] + 1);
				}
				if (human[nx][ny] >= 0 || board[nx][ny] == '#')
					continue;
				if (fire[nx][ny] != -1 && fire[nx][ny] <= human[now.first][now.second] + 1)
					continue;
				human[nx][ny] = human[now.first][now.second] + 1;
				q2.push(make_pair(nx, ny));
			}
		}
	return (-1);
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int ans = solve();
		if (ans == -1)
			cout << "IMPOSSIBLE\n";
		else
			cout << ans << '\n';
	}
}
