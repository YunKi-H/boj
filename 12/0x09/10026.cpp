// 문제
// 적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

// 크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

// 예를 들어, 그림이 아래와 같은 경우에

// RRRBB
// GGBBB
// BBBRR
// BBRRR
// RRRRR
// 적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

// 그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

// 입력
// 첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)

// 둘째 줄부터 N개 줄에는 그림이 주어진다.

// 출력
// 적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.
#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

string board[100];
int rgb[100][100];
int rb[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, res1 = 0, res2 = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> board[i];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rgb[i][j])
				continue;
			queue<pair<int, int> > q;
			rgb[i][j] = 1;
			q.push(make_pair(i, j));
			char a = board[i][j];
			res1++;
			while (!q.empty())
			{
				pair<int, int> now = q.front();
				q.pop();
				for (int d = 0; d < 4; d++)
				{
					int nx = now.first + dx[d];
					int ny = now.second + dy[d];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (rgb[nx][ny] || board[nx][ny] != a)
						continue;
					rgb[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (board[i][j] == 'G')
				board[i][j] = 'R';
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (rb[i][j])
				continue;
			queue<pair<int, int> > q;
			rb[i][j] = 1;
			q.push(make_pair(i, j));
			char a = board[i][j];
			res2++;
			while (!q.empty())
			{
				pair<int, int> now = q.front();
				q.pop();
				for (int d = 0; d < 4; d++)
				{
					int nx = now.first + dx[d];
					int ny = now.second + dy[d];
					if (nx < 0 || nx >= n || ny < 0 || ny >= n)
						continue;
					if (rb[nx][ny] || board[nx][ny] != a)
						continue;
					rb[nx][ny] = 1;
					q.push(make_pair(nx, ny));
				}
			}
		}
	}
	cout << res1 << ' ' << res2;
}
